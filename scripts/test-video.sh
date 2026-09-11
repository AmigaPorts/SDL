#!/bin/bash
#
# test-video.sh -- Build and launch SDL2 video test on FS-UAE with RTG
#
# Usage:
#   scripts/test-video.sh           # Build + launch FS-UAE
#   scripts/test-video.sh --no-build # Launch only (skip Docker build)
#
# Prerequisites:
#   - Docker (for cross-compilation)
#   - FS-UAE (brew install fs-uae)
#   - Kickstart 3.1 ROM at ~/Documents/FS-UAE/Kickstarts/kick3.1.rom
#   - build/system/ (bootable WB 3.1 -- copied from amiport)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
AMIGA_DIR="$PROJECT_DIR/build/amiga"
CONFIG="$PROJECT_DIR/toolchain/configs/sdl2-test.fs-uae"
KICKSTART="$HOME/Documents/FS-UAE/Kickstarts/kick3.1.rom"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

# Check prerequisites
if [ ! -f "$KICKSTART" ]; then
    echo -e "${RED}ERROR: Kickstart ROM not found at $KICKSTART${NC}"
    exit 1
fi

if [ ! -d "$PROJECT_DIR/build/system" ]; then
    echo -e "${RED}ERROR: build/system/ not found. Copy from amiport:${NC}"
    echo "  cp -a ~/Developer/amiport/build/system build/system"
    exit 1
fi

if ! command -v fs-uae &>/dev/null; then
    echo -e "${RED}ERROR: fs-uae not found. Install: brew install fs-uae${NC}"
    exit 1
fi

# Build unless --no-build
if [ "${1:-}" != "--no-build" ]; then
    echo -e "${YELLOW}Building libSDL2.a and test programs...${NC}"
    cd "$PROJECT_DIR"
    make examples 2>&1
    echo -e "${GREEN}Build complete.${NC}"
fi

# Create FS-UAE state directory for isolation from other sessions
mkdir -p "$PROJECT_DIR/build/fs-uae-state/Logs"
mkdir -p "$PROJECT_DIR/build/fs-uae-state/Save"

# Copy test binary to WORK: volume
mkdir -p "$AMIGA_DIR"
cp "$PROJECT_DIR/examples/test_video" "$AMIGA_DIR/test_video"
echo -e "${GREEN}Copied test_video to build/amiga/${NC}"

# Ensure UAEQuit is available
if [ ! -f "$AMIGA_DIR/UAEQuit" ]; then
    if [ -f "$HOME/Developer/amiport/build/amiga/UAEQuit" ]; then
        cp "$HOME/Developer/amiport/build/amiga/UAEQuit" "$AMIGA_DIR/UAEQuit"
    else
        echo -e "${YELLOW}WARNING: UAEQuit not found -- you will need to close FS-UAE manually${NC}"
    fi
fi

echo ""
echo -e "${GREEN}=== Launching FS-UAE with RTG ===${NC}"
echo ""
echo -e "Once Workbench boots, open a Shell and run:"
echo ""
echo -e "  ${YELLOW}WORK:test_video${NC}"
echo ""
echo -e "You should see a window with four colored quadrants:"
echo -e "  ${RED}RED${NC}    | ${GREEN}GREEN${NC}"
echo -e "  ------+------"
echo -e "  BLUE  | WHITE"
echo ""
echo -e "To shut down FS-UAE cleanly: ${YELLOW}WORK:UAEQuit${NC}"
echo ""

# Launch FS-UAE
# Prefer the forked FS-UAE with better features if available
FSUAE_BIN="fs-uae"
if [ -x "$HOME/Developer/fs-uae/fs-uae" ]; then
    FSUAE_BIN="$HOME/Developer/fs-uae/fs-uae"
fi

exec "$FSUAE_BIN" "$CONFIG"
