#!/bin/bash
#
# install-emu.sh — Copy all built ports and examples to the emulator directory
#
# Copies compiled Amiga binaries to build/amiga/ which is mounted as WORK:
# in FS-UAE. After running this, launch the emulator and the binaries
# are available at WORK:
#
# Usage: make install-emu

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
EMU_DIR="$PROJECT_DIR/build/amiga"

mkdir -p "$EMU_DIR"

INSTALLED=0

echo "=== Installing to emulator directory ==="

# Install built ports
for dir in "$PROJECT_DIR"/ports/*/; do
    name=$(basename "$dir")
    if [ -f "$dir/$name" ]; then
        cp "$dir/$name" "$EMU_DIR/"
        echo "  [OK] $name (port)"
        INSTALLED=$((INSTALLED + 1))
    fi
done

# Install built examples (skip if a port with the same name exists —
# ports take priority over examples to avoid shadowing)
for dir in "$PROJECT_DIR"/examples/*/; do
    name=$(basename "$dir")
    if [ -f "$dir/$name" ]; then
        if [ -f "$PROJECT_DIR/ports/$name/$name" ]; then
            echo "  [SKIP] $name (example) — port exists, skipping"
        else
            cp "$dir/$name" "$EMU_DIR/"
            echo "  [OK] $name (example)"
            INSTALLED=$((INSTALLED + 1))
        fi
    fi
done

# Install toolchain helpers (KeyInject, ScreenRead, UAEQuit)
for helper in KeyInject ScreenRead UAEQuit; do
    for helperdir in "$PROJECT_DIR"/toolchain/*/; do
        if [ -f "$helperdir/$helper" ]; then
            cp "$helperdir/$helper" "$EMU_DIR/"
            echo "  [OK] $helper (toolchain)"
            INSTALLED=$((INSTALLED + 1))
            break
        fi
    done
done

# Install common test data files
COMMON_DATA="$PROJECT_DIR/ports/common-test-data"
if [ -d "$COMMON_DATA" ]; then
    for datafile in "$COMMON_DATA"/*; do
        if [ -f "$datafile" ]; then
            cp "$datafile" "$EMU_DIR/"
        fi
    done
    echo "  [OK] common test data"
fi

if [ "$INSTALLED" -eq 0 ]; then
    echo "  No built binaries found. Run 'make build-ports' first."
    exit 1
fi

echo ""
echo "$INSTALLED binaries installed to build/amiga/"
echo ""
echo "Launch emulator with:"
echo "  make emu"
echo "  # or: fs-uae toolchain/configs/amiport-test.fs-uae"
echo ""
echo "In the Amiga shell, run: WORK:<program>"
