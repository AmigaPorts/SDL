#!/usr/bin/env python3
"""
verify-screen.py -- Reconstruct terminal screen from ANSI log and verify assertions.

Reads raw ANSI output captured by FS-UAE's consolehook and feeds it through
pyte (a Python terminal emulator) to reconstruct the screen state. Then
checks EXPECT_AT and EXPECT_CURSOR assertions against the screen.

Usage:
    verify-screen.py <ansi-log> <assertions-file>
    verify-screen.py <ansi-log> --dump   # Dump reconstructed screen (debug)

Assertions file format (one per line):
    EXPECT_AT row,col,text
    EXPECT_CURSOR row,col
    EXPECT_TRAP_CURSOR row,col   (requires --screen-dir)

Row and col are 1-based (matching ANSI conventions).

Exit codes:
    0 = all assertions passed
    1 = one or more assertions failed
    2 = usage error or missing file

Architecture: ADR-024 (FS-UAE Visual Verification)
"""

import sys
import os
import glob
import json

try:
    import pyte
except ImportError:
    print("ERROR: pyte not installed. Run: pip3 install pyte", file=sys.stderr)
    sys.exit(2)


def load_screen(ansi_log_path, cols=77, rows=30):
    """Feed ANSI log through pyte and return the Screen object.

    Default size: 77x30 matches the Amiga Shell window opened by the
    ITEST harness (CON:0/0/640/256/ITEST/AUTO at 8px font = ~77 cols,
    ~30 rows with title bar overhead).
    """
    screen = pyte.Screen(cols, rows)
    stream = pyte.Stream(screen)

    with open(ansi_log_path, "rb") as f:
        data = f.read()

    # FS-UAE consolehook captures raw bytes from console.device CMD_WRITE.
    # AmigaOS uses ISO-8859-1 encoding for console output.
    text = data.decode("iso-8859-1", errors="replace")
    stream.feed(text)

    return screen


def dump_screen(screen):
    """Print the reconstructed screen with row numbers."""
    for row_idx in range(screen.lines):
        line = screen.display[row_idx]
        print(f"{row_idx + 1:3d} |{line}|")
    print(f"Cursor: row={screen.cursor.y + 1}, col={screen.cursor.x + 1}")


def parse_assertions(assertions_path):
    """Parse assertions file. Returns list of (type, args) tuples."""
    assertions = []
    with open(assertions_path, "r") as f:
        for line_num, line in enumerate(f, 1):
            line = line.strip()
            if not line or line.startswith("#"):
                continue

            if line.startswith("EXPECT_AT "):
                # EXPECT_AT row,col,text
                rest = line[len("EXPECT_AT ") :]
                parts = rest.split(",", 2)
                if len(parts) != 3:
                    print(
                        f"ERROR: line {line_num}: EXPECT_AT needs row,col,text",
                        file=sys.stderr,
                    )
                    sys.exit(2)
                row, col, text = int(parts[0]), int(parts[1]), parts[2]
                if not text:
                    print(
                        f"ERROR: line {line_num}: EXPECT_AT has empty text"
                        " (vacuous assertion -- always passes)",
                        file=sys.stderr,
                    )
                    sys.exit(2)
                assertions.append(("EXPECT_AT", row, col, text))

            elif line.startswith("EXPECT_CURSOR "):
                rest = line[len("EXPECT_CURSOR ") :]
                parts = rest.split(",", 1)
                if len(parts) != 2:
                    print(
                        f"ERROR: line {line_num}: EXPECT_CURSOR needs row,col",
                        file=sys.stderr,
                    )
                    sys.exit(2)
                row, col = int(parts[0]), int(parts[1])
                assertions.append(("EXPECT_CURSOR", row, col))

            elif line.startswith("EXPECT_TRAP_CURSOR "):
                # ADR-025: cursor position from ConUnit trap (.screen JSON)
                rest = line[len("EXPECT_TRAP_CURSOR ") :]
                parts = rest.split(",", 1)
                if len(parts) != 2:
                    print(
                        f"ERROR: line {line_num}: EXPECT_TRAP_CURSOR needs row,col",
                        file=sys.stderr,
                    )
                    sys.exit(2)
                row, col = int(parts[0]), int(parts[1])
                assertions.append(("EXPECT_TRAP_CURSOR", row, col))

            else:
                print(
                    f"WARNING: line {line_num}: unknown assertion: {line}",
                    file=sys.stderr,
                )

    return assertions


def check_assertions(screen, assertions, screen_data=None):
    """Run assertions against screen. Returns (passed, failed, details).

    screen_data: dict from .screen JSON (ADR-025 trap), or None.
    """
    passed = 0
    failed = 0
    details = []

    for assertion in assertions:
        if assertion[0] == "EXPECT_AT":
            _, row, col, expected_text = assertion
            # Convert 1-based to 0-based
            r = row - 1
            c = col - 1

            if r < 0 or r >= screen.lines:
                details.append(
                    f"FAIL: EXPECT_AT {row},{col}: row out of range (screen has {screen.lines} rows)"
                )
                failed += 1
                continue

            if c < 0 or c >= screen.columns:
                details.append(
                    f"FAIL: EXPECT_AT {row},{col}: col out of range (screen has {screen.columns} cols)"
                )
                failed += 1
                continue

            line = screen.display[r]
            end = c + len(expected_text)
            actual = line[c:end] if c < len(line) else ""

            if actual == expected_text:
                details.append(f"PASS: EXPECT_AT {row},{col},{expected_text}")
                passed += 1
            else:
                details.append(
                    f"FAIL: EXPECT_AT {row},{col},{expected_text}"
                    f" -- actual: '{actual}'"
                )
                failed += 1

        elif assertion[0] == "EXPECT_CURSOR":
            _, row, col = assertion
            actual_row = screen.cursor.y + 1
            actual_col = screen.cursor.x + 1

            if actual_row == row and actual_col == col:
                details.append(f"PASS: EXPECT_CURSOR {row},{col}")
                passed += 1
            else:
                details.append(
                    f"FAIL: EXPECT_CURSOR {row},{col}"
                    f" -- actual: {actual_row},{actual_col}"
                )
                failed += 1

        elif assertion[0] == "EXPECT_TRAP_CURSOR":
            # ADR-025: cursor position from ConUnit trap (.screen JSON)
            _, row, col = assertion
            if not screen_data:
                details.append(
                    f"FAIL: EXPECT_TRAP_CURSOR {row},{col}"
                    f" -- no .screen file found (did ScreenRead run?)"
                )
                failed += 1
                continue
            actual_row = screen_data["cursor_row"]
            actual_col = screen_data["cursor_col"]
            if actual_row == row and actual_col == col:
                details.append(f"PASS: EXPECT_TRAP_CURSOR {row},{col}")
                passed += 1
            else:
                details.append(
                    f"FAIL: EXPECT_TRAP_CURSOR {row},{col}"
                    f" -- actual: {actual_row},{actual_col}"
                )
                failed += 1

    return passed, failed, details


def load_screen_data(screen_dir):
    """Load .screen JSON from ADR-025 trap dump. Returns dict or None."""
    if not screen_dir:
        return None
    screen_files = sorted(glob.glob(os.path.join(screen_dir, "*.screen")))
    if not screen_files:
        return None
    # Use the last (newest) .screen file
    with open(screen_files[-1]) as f:
        return json.load(f)


def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <ansi-log> <assertions-file>")
        print(f"       {sys.argv[0]} <ansi-log> --dump")
        sys.exit(2)

    ansi_log_path = sys.argv[1]
    if not os.path.isfile(ansi_log_path):
        print(f"ERROR: ANSI log not found: {ansi_log_path}", file=sys.stderr)
        sys.exit(2)

    # Optional: --cols N --rows N --screen-dir PATH
    cols = 77
    rows = 30
    screen_dir = None
    i = 3
    while i < len(sys.argv):
        if sys.argv[i] == "--cols" and i + 1 < len(sys.argv):
            cols = int(sys.argv[i + 1])
            i += 2
        elif sys.argv[i] == "--rows" and i + 1 < len(sys.argv):
            rows = int(sys.argv[i + 1])
            i += 2
        elif sys.argv[i] == "--screen-dir" and i + 1 < len(sys.argv):
            screen_dir = sys.argv[i + 1]
            i += 2
        else:
            i += 1

    screen = load_screen(ansi_log_path, cols=cols, rows=rows)

    if sys.argv[2] == "--dump":
        dump_screen(screen)
        sys.exit(0)

    assertions_path = sys.argv[2]
    if not os.path.isfile(assertions_path):
        print(
            f"ERROR: Assertions file not found: {assertions_path}", file=sys.stderr
        )
        sys.exit(2)

    assertions = parse_assertions(assertions_path)
    if not assertions:
        print("WARNING: No assertions found in file", file=sys.stderr)
        sys.exit(0)

    screen_data = load_screen_data(screen_dir)
    passed, failed, details = check_assertions(screen, assertions, screen_data)

    for detail in details:
        print(detail)

    print(f"\n# {passed} passed, {failed} failed out of {len(assertions)} assertions")

    sys.exit(1 if failed > 0 else 0)


if __name__ == "__main__":
    main()
