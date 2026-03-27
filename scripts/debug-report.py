#!/usr/bin/env python3
"""
debug-report.py — Parse Enforcer crash output and map addresses to source lines.

Part of the amiport autonomous debug pipeline (Layer 1d).

Enforcer hit format (from Enforcer.doc by Michael Sinz):

  [DATESTAMP line if enabled: DD-Mon-YY  HH:MM:SS]
  {TYPE} {to|from} {ADDRESS}  [data={DATA}]  PC: {PC}
  USP: {USP} SR: {SR} SW: {SW}  ({flags})  TCB: {TCB}
  Data: {D0} {D1} {D2} {D3} {D4} {D5} {D6} {D7}
  Addr: {A0} {A1} {A2} {A3} {A4} {A5} {A6} --------
  Stck: ... (STACKLINES lines of 8 longwords each)
  ----> {PC} - "{name}" Hunk {NNNN} Offset {XXXXXXXX}
  [PC-8: ... (optional, shows code around crash)]
  [PC *: ... (optional)]
  Name: "{task}" CLI: "{cli}" Hunk {NNNN} Offset {XXXXXXXX}

Hit types: BYTE-READ, BYTE-WRITE, WORD-READ, WORD-WRITE,
           LONG-READ, LONG-WRITE, (INST), Alert
Write types use 'to' with a data= field. Read types use 'from' with no data field.
Flags: (U0)=user mode, (F)=Forbid, (D)=Disable, (-)=inactive

Mungwall sentinel patterns in crash address:
  0xDEADBEEF -> use-after-free (freed memory)
  0xABADCAFE -> pre-fill pattern
  0xCCCCCCCC -> uninitialized memory

Subcommands:
  parse <enforcer.log>       Parse Enforcer output into structured JSON
  map <hits.json> <binary>   Map hunk+offset to source file and line number
"""

import argparse
import json
import os
import re
import subprocess
import sys


# --------------------------------------------------------------------------- #
# Mungwall sentinel detection
# --------------------------------------------------------------------------- #

MUNGWALL_SENTINELS = {
    0xDEADBEEF: "use-after-free (freed memory)",
    0xABADCAFE: "pre-fill pattern",
    0xCCCCCCCC: "uninitialized memory",
}


def detect_mungwall(address_int):
    """Check if an address matches a known Mungwall sentinel pattern."""
    return MUNGWALL_SENTINELS.get(address_int)


def classify_crash(address_int, hit_type):
    """Classify a crash based on address and hit type."""
    mungwall = detect_mungwall(address_int)
    if mungwall:
        return "Mungwall: {}".format(mungwall)

    if address_int < 0x1000:
        if address_int == 0:
            return "NULL pointer {}".format(hit_type.lower().replace("-", " "))
        return "NULL pointer {} (offset 0x{:X} from NULL struct pointer)".format(
            hit_type.lower().replace("-", " "), address_int
        )

    return hit_type


# --------------------------------------------------------------------------- #
# Parse subcommand
# --------------------------------------------------------------------------- #

# Regex for the first line of an Enforcer hit:
#   LONG-READ from 00000014  PC: 00343F4A
#   LONG-WRITE to 00000014  data=00000000  PC: 00343F4A
#   Alert !! Alert 87000003
RE_HIT_LINE = re.compile(
    r"^(BYTE|WORD|LONG)-(READ|WRITE)\s+(from|to)\s+([0-9A-Fa-f]+)"
    r"(?:\s+data=([0-9A-Fa-f]+))?"
    r"\s+PC:\s+([0-9A-Fa-f]+)$"
)

RE_ALERT_LINE = re.compile(
    r"^Alert\s+!!\s+Alert\s+([0-9A-Fa-f]+)"
    r"(?:\s+TCB:\s+([0-9A-Fa-f]+)\s+USP:\s+([0-9A-Fa-f]+))?$"
)

# Datestamp: DD-Mon-YY  HH:MM:SS
RE_DATESTAMP = re.compile(
    r"^\d{2}-[A-Z][a-z]{2}-\d{2}\s+\d{2}:\d{2}:\d{2}$"
)

# USP: XXXXXXXX SR: XXXX SW: XXXX  (U0)(-)(-) or (flags)  TCB: XXXXXXXX
# Real Enforcer uses three separate paren groups: (U0)(-)(-)
RE_STATUS = re.compile(
    r"^USP:\s+([0-9A-Fa-f]+)\s+SR:\s+([0-9A-Fa-f]+)\s+SW:\s+([0-9A-Fa-f]+)"
    r"\s+(\([^)]*\)(?:\([^)]*\))*)\s+TCB:\s+([0-9A-Fa-f]+)$"
)

# Data: D0 D1 D2 D3 D4 D5 D6 D7
RE_DATA_REGS = re.compile(
    r"^Data:\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+"
    r"([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+"
    r"([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)$"
)

# Addr: A0 A1 A2 A3 A4 A5 A6 --------
RE_ADDR_REGS = re.compile(
    r"^Addr:\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+"
    r"([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+"
    r"([0-9A-Fa-f]+)\s+[-]+$"
)

# Stck: val val val val val val val val
RE_STACK = re.compile(
    r"^Stck:\s+([0-9A-Fa-f]+(?:\s+[0-9A-Fa-f]+)*)$"
)

# ----> PC - "name" Hunk NNNN Offset XXXXXXXX
RE_SEGTRACKER = re.compile(
    r"^---->\s+[0-9A-Fa-f]+\s+-\s+\"([^\"]+)\"\s+Hunk\s+(\d+)\s+Offset\s+([0-9A-Fa-f]+)$"
)

# Name: "task" CLI: "cli" Hunk NNNN Offset XXXXXXXX
RE_NAME = re.compile(
    r"^Name:\s+\"([^\"]*)\"\s+CLI:\s+\"([^\"]*)\"\s+Hunk\s+(\d+)\s+Offset\s+([0-9A-Fa-f]+)$"
)


def parse_flags(flags_str):
    """Parse Enforcer flag string into a dict.

    Handles both single-group '(UF)' and multi-group '(U0)(F)(-)' formats.
    The raw string may include outer parens: '(U0)(-)(-)'
    """
    flags_str = flags_str.strip()
    return {
        "user_mode": "U" in flags_str,
        "forbid": "F" in flags_str,
        "disable": "D" in flags_str,
    }


def parse_enforcer_log(filepath):
    """Parse an Enforcer log file into structured hit records."""
    with open(filepath, "r") as f:
        lines = [line.rstrip() for line in f]

    hits = []
    current_hit = None
    pending_datestamp = None

    for line in lines:
        # Skip blank lines
        if not line.strip():
            continue

        # Check for datestamp (appears before a hit)
        m = RE_DATESTAMP.match(line.strip())
        if m:
            pending_datestamp = line.strip()
            continue

        # Check for alert
        m = RE_ALERT_LINE.match(line.strip())
        if m:
            if current_hit:
                hits.append(current_hit)
            current_hit = {
                "type": "Alert",
                "alert_code": "0x{}".format(m.group(1).upper()),
                "address": None,
                "data": None,
                "pc": None,
                "usp": "0x{}".format(m.group(3).upper()) if m.group(3) else None,
                "sr": None,
                "flags": {"user_mode": False, "forbid": False, "disable": False},
                "registers": {},
                "stack": [],
                "segtracker": None,
                "task_name": None,
                "cli_name": None,
                "datestamp": pending_datestamp,
            }
            pending_datestamp = None
            continue

        # Check for hit first line (TYPE READ/WRITE)
        m = RE_HIT_LINE.match(line.strip())
        if m:
            if current_hit:
                hits.append(current_hit)
            size = m.group(1)
            direction = m.group(2)
            hit_type = "{}-{}".format(size, direction)
            address_hex = m.group(4).upper()
            data_hex = m.group(5).upper() if m.group(5) else None
            pc_hex = m.group(6).upper()

            current_hit = {
                "type": hit_type,
                "address": "0x{}".format(address_hex.zfill(8)),
                "data": "0x{}".format(data_hex.zfill(8)) if data_hex else None,
                "pc": "0x{}".format(pc_hex.zfill(8)),
                "usp": None,
                "sr": None,
                "flags": {"user_mode": False, "forbid": False, "disable": False},
                "registers": {},
                "stack": [],
                "segtracker": None,
                "task_name": None,
                "cli_name": None,
                "datestamp": pending_datestamp,
            }
            pending_datestamp = None
            continue

        if not current_hit:
            continue

        # USP / SR / flags line
        m = RE_STATUS.match(line.strip())
        if m:
            current_hit["usp"] = "0x{}".format(m.group(1).upper().zfill(8))
            current_hit["sr"] = "0x{}".format(m.group(2).upper().zfill(4))
            current_hit["flags"] = parse_flags(m.group(4))
            continue

        # Data registers
        m = RE_DATA_REGS.match(line.strip())
        if m:
            for i in range(8):
                current_hit["registers"]["d{}".format(i)] = "0x{}".format(
                    m.group(i + 1).upper().zfill(8)
                )
            continue

        # Address registers
        m = RE_ADDR_REGS.match(line.strip())
        if m:
            for i in range(7):
                current_hit["registers"]["a{}".format(i)] = "0x{}".format(
                    m.group(i + 1).upper().zfill(8)
                )
            continue

        # Stack
        m = RE_STACK.match(line.strip())
        if m:
            vals = m.group(1).split()
            for v in vals:
                current_hit["stack"].append("0x{}".format(v.upper().zfill(8)))
            continue

        # SegTracker resolution
        m = RE_SEGTRACKER.match(line.strip())
        if m:
            current_hit["segtracker"] = {
                "name": m.group(1),
                "hunk": int(m.group(2)),
                "offset": "0x{}".format(m.group(3).upper().zfill(8)),
            }
            continue

        # Name/CLI line
        m = RE_NAME.match(line.strip())
        if m:
            current_hit["task_name"] = m.group(1)
            current_hit["cli_name"] = m.group(2)
            continue

        # PC-8: and PC *: lines — store as optional context but don't parse deeply
        # These are code dump lines around the crash point

    # Don't forget the last hit
    if current_hit:
        hits.append(current_hit)

    # Build summary
    crash_types = []
    unique_pcs = set()
    for hit in hits:
        if hit["pc"]:
            unique_pcs.add(hit["pc"])
        if hit["type"] == "Alert":
            crash_types.append("Alert {}".format(hit.get("alert_code", "unknown")))
        elif hit["address"]:
            addr_int = int(hit["address"], 16)
            crash_types.append(classify_crash(addr_int, hit["type"]))

    # Remove None fields for cleaner output
    for hit in hits:
        if hit.get("data") is None:
            del hit["data"]
        if hit.get("alert_code") is None and "alert_code" in hit:
            del hit["alert_code"]
        if hit.get("datestamp") is None:
            del hit["datestamp"]

    return {
        "hits": hits,
        "summary": {
            "total_hits": len(hits),
            "unique_locations": len(unique_pcs),
            "crash_types": list(dict.fromkeys(crash_types)),  # dedupe, preserve order
        },
    }


def is_rom_false_positive(hit):
    """Detect known ROM interrupt handler false positives.

    The Kickstart ROM interrupt handler writes to 0xF0FFFC (CIAB ICR)
    from PC 0xF00408. This fires hundreds of times per test run and
    is NOT a bug in user code. Enforcer flags it because the address
    is outside the normal RAM range, but it's a legitimate hardware
    register write from supervisor mode.

    See crash-patterns.md "ROM Interrupt Handler False Positives".
    """
    addr = hit.get("address", "")
    pc = hit.get("pc", "")
    name = hit.get("task_name", "") or ""

    # Classic pattern: LONG-WRITE to 00F0FFFC from PC 00F00408
    if addr.upper() == "00F0FFFC" and pc.upper() == "00F00408":
        return True

    # Broader: any hit where BOTH address and PC are in ROM range (0xF00000+)
    # and the task is an interrupt handler
    if "Interrupt" in name or "interrupt" in name:
        try:
            addr_int = int(addr, 16) if addr else 0
            pc_int = int(pc, 16) if pc else 0
            if addr_int >= 0xF00000 and pc_int >= 0xF00000:
                return True
        except ValueError:
            pass

    return False


def filter_app_hits(result, app_name):
    """Filter Enforcer hits to only those involving a specific application.

    A hit is relevant if:
    - Its SegTracker resolution names the app (e.g., "WORK:diff")
    - Its CLI name matches the app
    - Its task name matches the app

    ROM/system hits (from interrupt handlers, Kickstart, etc.) are excluded
    unless the app appears in their SegTracker or stack trace references.
    Known ROM false positives (interrupt handler writes to CIAB) are always excluded.

    Enforcer has no built-in filtering — this post-processing step is the
    standard practice per Amiga developer documentation.
    """
    app_lower = app_name.lower()
    filtered = []
    rom_filtered = 0

    for hit in result["hits"]:
        # Always exclude known ROM false positives
        if is_rom_false_positive(hit):
            rom_filtered += 1
            continue

        # Check SegTracker name
        seg = hit.get("segtracker")
        if seg and app_lower in seg.get("name", "").lower():
            filtered.append(hit)
            continue

        # Check CLI/task name
        cli = (hit.get("cli_name") or "").lower()
        task = (hit.get("task_name") or "").lower()
        if app_lower in cli or app_lower in task:
            filtered.append(hit)
            continue

    # Rebuild summary for filtered hits
    crash_types = []
    unique_pcs = set()
    for hit in filtered:
        if hit.get("pc"):
            unique_pcs.add(hit["pc"])
        if hit["type"] == "Alert":
            crash_types.append("Alert {}".format(hit.get("alert_code", "unknown")))
        elif hit.get("address"):
            addr_int = int(hit["address"], 16)
            crash_types.append(classify_crash(addr_int, hit["type"]))

    return {
        "hits": filtered,
        "summary": {
            "total_hits": len(filtered),
            "unique_locations": len(unique_pcs),
            "crash_types": list(dict.fromkeys(crash_types)),
        },
        "filtered_from": result["summary"]["total_hits"],
        "rom_false_positives": rom_filtered,
    }


def cmd_parse(args):
    """Handle the 'parse' subcommand."""
    if not os.path.isfile(args.enforcer_log):
        print("error: file not found: {}".format(args.enforcer_log), file=sys.stderr)
        sys.exit(1)

    result = parse_enforcer_log(args.enforcer_log)

    # Filter to application hits if --app specified
    if hasattr(args, "app") and args.app:
        result = filter_app_hits(result, args.app)

    json.dump(result, sys.stdout, indent=2)
    print()  # trailing newline


# --------------------------------------------------------------------------- #
# Map subcommand
# --------------------------------------------------------------------------- #

def count_sections(binary):
    """Count sections in binary using objdump -h."""
    try:
        result = subprocess.run(
            ["m68k-amigaos-objdump", "-h", binary],
            capture_output=True, text=True, timeout=10
        )
    except FileNotFoundError:
        print("error: m68k-amigaos-objdump not found in PATH", file=sys.stderr)
        sys.exit(1)

    # Count section lines (lines starting with a section index number)
    section_count = 0
    for line in result.stdout.splitlines():
        stripped = line.strip()
        # objdump -h section lines start with a number like "  0 .text  ..."
        if stripped and stripped[0].isdigit() and len(stripped.split()) >= 3:
            section_count += 1
    return section_count


def parse_linker_map(map_path):
    """Parse a GCC linker map file to find hunk base addresses.

    Returns a dict: hunk_number -> {"section": str, "base": int}
    """
    if not os.path.isfile(map_path):
        return None

    # The linker map from -Wl,-Map contains section addresses.
    # We look for lines like:
    #   .text   0x00000000   0x1234
    #   .data   0x00001234   0x0100
    #   .bss    0x00001334   0x0050
    hunks = {}
    hunk_num = 0
    re_section = re.compile(
        r"^(\.\w+)\s+0x([0-9a-fA-F]+)\s+0x([0-9a-fA-F]+)"
    )

    with open(map_path, "r") as f:
        for line in f:
            m = re_section.match(line.strip())
            if m:
                section = m.group(1)
                base = int(m.group(2), 16)
                size = int(m.group(3), 16)
                if size > 0 and section in (".text", ".data", ".bss"):
                    hunks[hunk_num] = {
                        "section": section,
                        "base": base,
                    }
                    hunk_num += 1

    return hunks if hunks else None


def section_for_hunk(hunk_map, hunk_num):
    """Determine the objdump section name for a given hunk number."""
    if hunk_map and hunk_num in hunk_map:
        return hunk_map[hunk_num]["section"]
    # Default: hunk 0 is .text, hunk 1 is .data, hunk 2 is .bss
    defaults = {0: ".text", 1: ".data", 2: ".bss"}
    return defaults.get(hunk_num, ".text")


def run_addr2line(binary, section, offset):
    """Run m68k-amigaos-addr2line and return (file, line, function)."""
    try:
        result = subprocess.run(
            [
                "m68k-amigaos-addr2line",
                "-e", binary,
                "--section={}".format(section),
                "-f",  # also print function name
                offset,
            ],
            capture_output=True, text=True, timeout=10
        )
    except FileNotFoundError:
        print("error: m68k-amigaos-addr2line not found in PATH", file=sys.stderr)
        sys.exit(1)

    lines = result.stdout.strip().splitlines()
    func = lines[0] if len(lines) >= 1 else "??"
    location = lines[1] if len(lines) >= 2 else "??:0"

    if func == "??":
        func = None

    if location == "??:0" or location.startswith("??:"):
        return None, None, func

    # Parse "file.c:47"
    parts = location.rsplit(":", 1)
    if len(parts) == 2:
        source_file = parts[0]
        try:
            line_num = int(parts[1])
        except ValueError:
            return source_file, None, func
        return source_file, line_num, func

    return location, None, func


def read_source_context(source_file, line_num, context=3):
    """Read source context around a crash line (3 lines before + after)."""
    if not source_file or not line_num:
        return None

    # Try the file path as-is, then relative to cwd
    candidates = [source_file]
    if not os.path.isabs(source_file):
        candidates.append(os.path.join(os.getcwd(), source_file))

    for path in candidates:
        if os.path.isfile(path):
            try:
                with open(path, "r") as f:
                    all_lines = f.readlines()
            except (IOError, OSError):
                return None

            start = max(0, line_num - 1 - context)
            end = min(len(all_lines), line_num + context)
            result = []
            for i in range(start, end):
                result.append("{}:{}".format(
                    i + 1, all_lines[i].rstrip()
                ))
            return result

    return None


def cmd_map(args):
    """Handle the 'map' subcommand."""
    if not os.path.isfile(args.hits_json):
        print("error: file not found: {}".format(args.hits_json), file=sys.stderr)
        sys.exit(1)

    if not os.path.isfile(args.binary):
        print("error: binary not found: {}".format(args.binary), file=sys.stderr)
        sys.exit(1)

    with open(args.hits_json, "r") as f:
        hits_data = json.load(f)

    hits = hits_data.get("hits", [])
    num_sections = count_sections(args.binary)
    is_multi_hunk = num_sections > 1

    # For multi-hunk, we need the linker map
    hunk_map = None
    map_path = args.binary + ".map"
    if is_multi_hunk:
        hunk_map = parse_linker_map(map_path)
        if hunk_map is None:
            print(
                "error: multi-hunk binary requires .map file — "
                "rebuild with -Wl,-Map={}".format(map_path),
                file=sys.stderr,
            )
            sys.exit(1)

    mapped_hits = []

    for hit in hits:
        seg = hit.get("segtracker")
        if not seg:
            mapped_hits.append({
                "address": hit.get("pc"),
                "error": "no SegTracker data — cannot map to source",
            })
            continue

        hunk_num = seg["hunk"]
        offset = seg["offset"]
        section = section_for_hunk(hunk_map, hunk_num)

        source_file, line_num, func = run_addr2line(
            args.binary, section, offset
        )

        entry = {
            "address": hit.get("pc"),
            "hunk": hunk_num,
            "offset": offset,
        }

        if source_file is None and line_num is None:
            entry["error"] = "no debug info — rebuild with -gstabs"
            if func:
                entry["function"] = func
        else:
            entry["source_file"] = source_file
            if line_num is not None:
                entry["line"] = line_num
            if func:
                entry["function"] = func
            context = read_source_context(source_file, line_num)
            if context:
                entry["source_context"] = context

        mapped_hits.append(entry)

    result = {"mapped_hits": mapped_hits}
    json.dump(result, sys.stdout, indent=2)
    print()  # trailing newline


# --------------------------------------------------------------------------- #
# Main
# --------------------------------------------------------------------------- #

def main():
    parser = argparse.ArgumentParser(
        description="Parse Enforcer crash output and map addresses to source lines."
    )
    subparsers = parser.add_subparsers(dest="command", help="subcommand")
    subparsers.required = True

    # parse subcommand
    parse_parser = subparsers.add_parser(
        "parse",
        help="Parse Enforcer log into structured JSON",
    )
    parse_parser.add_argument(
        "enforcer_log",
        help="Path to Enforcer log file",
    )
    parse_parser.add_argument(
        "--app",
        help="Filter to hits involving this application (e.g., 'diff'). "
             "Excludes ROM/system hits that aren't related to the app.",
    )
    parse_parser.set_defaults(func=cmd_parse)

    # map subcommand
    map_parser = subparsers.add_parser(
        "map",
        help="Map hunk+offset from hits JSON to source lines",
    )
    map_parser.add_argument(
        "hits_json",
        help="Path to JSON file from 'parse' subcommand",
    )
    map_parser.add_argument(
        "binary",
        help="Path to Amiga binary (compiled with -gstabs)",
    )
    map_parser.set_defaults(func=cmd_map)

    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
