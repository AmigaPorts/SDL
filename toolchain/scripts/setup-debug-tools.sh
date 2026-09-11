#!/bin/bash
#
# setup-debug-tools.sh — Download Amiga debug tools from Aminet
#
# Downloads Enforcer, Mungwall, SegTracker, and bgdbserver into
# toolchain/debug-tools/. Idempotent — skips tools already present.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)"
DEBUG_TOOLS_DIR="$PROJECT_DIR/toolchain/debug-tools"
DOWNLOAD_DIR="$DEBUG_TOOLS_DIR/.downloads"

AMINET_BASE="https://aminet.net"

# Tool definitions: name|aminet_path|archive_name
# Archive names match what's currently on Aminet (case-sensitive!).
# If Aminet updates the version, the download will fail with a clear error.
# Note: MungWall uses .lzh format, not .lha.
TOOLS=(
    "Enforcer|dev/debug|enforcer.lha"
    "MungWall|dev/debug|Mungwall37_64.lzh"
    "SegTracker|dev/debug|SegTracker.lha"
    "bgdbserver|dev/debug|bgdbserver.lha"
)

echo "=== amiport debug tools setup ==="
echo ""

# Create directories
mkdir -p "$DEBUG_TOOLS_DIR"
mkdir -p "$DOWNLOAD_DIR"

# Check for extraction tool
HAS_LHA=0
if command -v lha &> /dev/null; then
    HAS_LHA=1
elif command -v docker &> /dev/null; then
    HAS_LHA=2  # Will use Docker fallback
else
    echo "ERROR: Neither 'lha' nor 'docker' found."
    echo "Install lha:  brew install lha  (macOS) / apt install lha (Linux)"
    echo "Or install Docker for container-based extraction."
    exit 1
fi

extract_lha() {
    local archive="$1"
    local dest="$2"

    if [ "$HAS_LHA" = "1" ]; then
        (cd "$dest" && lha xq "$archive")
    else
        # Docker fallback using the cross-compiler image
        docker run --rm \
            -v "$archive:/tmp/archive.lha:ro" \
            -v "$dest:/tmp/out" \
            amigadev/m68k-amigaos-gcc \
            sh -c 'cd /tmp/out && lha xq /tmp/archive.lha'
    fi
}

download_tool() {
    local name="$1"
    local aminet_path="$2"
    local archive_name="$3"

    local url="${AMINET_BASE}/${aminet_path}/${archive_name}"
    local archive_file="${DOWNLOAD_DIR}/${archive_name}"
    local extract_dir="${DOWNLOAD_DIR}/${name}_extracted"

    printf "  %-15s " "$name"

    # Check if tool binary already exists in debug-tools/
    # Look for the tool (case-insensitive match since Amiga filenames vary)
    if find "$DEBUG_TOOLS_DIR" -maxdepth 1 -iname "$name" -type f 2>/dev/null | grep -q .; then
        echo "SKIP (already installed)"
        return 0
    fi

    # Download archive
    if [ ! -f "$archive_file" ]; then
        local http_code
        http_code=$(curl -s -L -o "$archive_file" -w "%{http_code}" --max-time 30 "$url" 2>/dev/null || echo "000")

        if [ "$http_code" != "200" ]; then
            rm -f "$archive_file"
            echo "FAIL (HTTP $http_code from $url)"
            echo "         The archive name may have changed on Aminet."
            echo "         Check: https://aminet.net/package/${aminet_path}/${name}"
            return 1
        fi
    fi

    # Verify it's actually an LHA archive (not an HTML error page)
    if ! file "$archive_file" 2>/dev/null | grep -qi 'lha\|archive\|data'; then
        local head_bytes
        head_bytes=$(head -c 20 "$archive_file" 2>/dev/null | strings || echo "")
        if echo "$head_bytes" | grep -qi 'html\|error\|not found'; then
            rm -f "$archive_file"
            echo "FAIL (received HTML instead of archive — URL may have changed)"
            echo "         Check: https://aminet.net/package/${aminet_path}/${name}"
            return 1
        fi
    fi

    # Extract
    rm -rf "$extract_dir"
    mkdir -p "$extract_dir"

    if ! extract_lha "$archive_file" "$extract_dir" 2>/dev/null; then
        echo "FAIL (extraction failed)"
        rm -rf "$extract_dir"
        return 1
    fi

    # Find and copy the binary — look for the tool name in extracted files
    # Aminet archives often have nested directory structures
    local found=0
    while IFS= read -r -d '' candidate; do
        local basename
        basename=$(basename "$candidate")
        # Skip obvious non-binaries
        case "$basename" in
            *.doc|*.txt|*.readme|*.info|*.guide|*.html|*.lha|*.DIC) continue ;;
        esac
        # Match tool name case-insensitively
        if echo "$basename" | grep -qi "^${name}$"; then
            cp "$candidate" "$DEBUG_TOOLS_DIR/$name"
            chmod +x "$DEBUG_TOOLS_DIR/$name"
            found=1
            break
        fi
    done < <(find "$extract_dir" -type f -print0 2>/dev/null)

    # If exact match not found, try partial match (e.g., "Enforcer" in "Enforcer.030")
    if [ "$found" = "0" ]; then
        while IFS= read -r -d '' candidate; do
            local basename
            basename=$(basename "$candidate")
            case "$basename" in
                *.doc|*.txt|*.readme|*.info|*.guide|*.html|*.lha|*.DIC) continue ;;
            esac
            if echo "$basename" | grep -qi "${name}"; then
                cp "$candidate" "$DEBUG_TOOLS_DIR/$name"
                chmod +x "$DEBUG_TOOLS_DIR/$name"
                found=1
                break
            fi
        done < <(find "$extract_dir" -type f -print0 2>/dev/null)
    fi

    # Clean up extraction directory
    rm -rf "$extract_dir"

    if [ "$found" = "1" ]; then
        echo "OK"
    else
        echo "FAIL (binary not found in archive)"
        echo "         Extracted contents did not contain '$name'"
        return 1
    fi
}

# Download and install each tool
echo "Downloading debug tools from Aminet..."
echo ""

failures=0
for tool_def in "${TOOLS[@]}"; do
    IFS='|' read -r name aminet_path archive_name <<< "$tool_def"
    if ! download_tool "$name" "$aminet_path" "$archive_name"; then
        failures=$((failures + 1))
    fi
done

echo ""

# Summary
installed=$(find "$DEBUG_TOOLS_DIR" -maxdepth 1 -type f ! -name '.*' 2>/dev/null | wc -l | tr -d ' ')
echo "=== Summary ==="
echo "  Install directory: $DEBUG_TOOLS_DIR"
echo "  Tools installed:   $installed / ${#TOOLS[@]}"

if [ "$failures" -gt 0 ]; then
    echo ""
    echo "WARNING: $failures tool(s) failed to download."
    echo "Aminet archive names may have changed. Check the URLs above"
    echo "and update the TOOLS array in this script if needed."
    exit 1
fi

echo ""
echo "All debug tools installed successfully."
