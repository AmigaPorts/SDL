#!/bin/bash
#
# setup-emu.sh — Install and configure FS-UAE for interactive Amiga testing
#
# Installs FS-UAE via Homebrew (macOS) or provides instructions for Linux,
# creates the Kickstarts directory, and checks for ROM files.

set -euo pipefail

OS=$(uname -s)

echo "=== amiport emulator setup ==="
echo ""

# Step 1: Install FS-UAE
if command -v fs-uae >/dev/null 2>&1; then
    echo "[OK] FS-UAE already installed: $(fs-uae --version 2>/dev/null || echo 'version unknown')"
else
    echo "[--] FS-UAE not found"
    if [ "$OS" = "Darwin" ]; then
        echo "     Installing via Homebrew..."
        if command -v brew >/dev/null 2>&1; then
            brew install fs-uae
            echo "[OK] FS-UAE installed"
        else
            echo "[FAIL] Homebrew not found. Install from: https://fs-uae.net/download"
            exit 1
        fi
    else
        echo "     Install with your package manager:"
        echo "       Ubuntu/Debian: sudo apt install fs-uae"
        echo "       Fedora: sudo dnf install fs-uae"
        echo "       Or download from: https://fs-uae.net/download"
        exit 1
    fi
fi

# Step 2: Create directories
FSDIR="$HOME/Documents/FS-UAE"
KICKDIR="$FSDIR/Kickstarts"
CONFDIR="$FSDIR/Configurations"

mkdir -p "$KICKDIR" "$CONFDIR"
echo "[OK] FS-UAE directories ready ($FSDIR)"

# Step 3: Check for Kickstart ROM
echo ""
if ls "$KICKDIR"/*.rom >/dev/null 2>&1 || ls "$KICKDIR"/*.ROM >/dev/null 2>&1; then
    echo "[OK] Kickstart ROM(s) found in $KICKDIR:"
    ls "$KICKDIR"/*.rom "$KICKDIR"/*.ROM 2>/dev/null | while read f; do
        echo "     $(basename "$f")"
    done
else
    echo "[!!] No Kickstart ROM found in $KICKDIR"
    echo ""
    echo "     You need a Kickstart 3.1 ROM to run the emulator."
    echo "     Options:"
    echo "       1. Purchase Amiga Forever (~\$10): https://www.amigaforever.com"
    echo "       2. Extract from real Amiga hardware using Transrom"
    echo ""
    echo "     Place the ROM file in: $KICKDIR/"
    echo "     Any filename works — FS-UAE identifies ROMs by content."
fi

# Step 4: Install amitools for vamos (if not already)
echo ""
if command -v vamos >/dev/null 2>&1; then
    echo "[OK] vamos already installed"
else
    echo "[--] vamos not found — installing amitools..."
    pip install amitools
    echo "[OK] vamos installed"
fi

echo ""
echo "=== Setup complete ==="
echo ""
echo "Next steps:"
echo "  1. Ensure you have a Kickstart 3.1 ROM in $KICKDIR/"
echo "  2. Build some ports:  make build-ports"
echo "  3. Install to emu:    make install-emu"
echo "  4. Launch:            make emu"
echo ""
echo "In the Amiga shell, your ports are available at WORK:"
