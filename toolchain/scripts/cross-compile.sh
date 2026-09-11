#!/bin/bash
#
# cross-compile.sh — Cross-compile C source for Amiga
#
# Usage: cross-compile.sh [options] source.c -o output
#
# Options:
#   --target PROFILE   Target profile (68000, 68020, 68040, default: 68020)
#   --toolchain TC     Toolchain (auto, docker-bebbo, native-bebbo, default: auto)
#   --shim-dir DIR     Path to posix-shim (default: auto-detect)

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)"
CONFIGS_DIR="$SCRIPT_DIR/../configs"

# Defaults
TARGET_PROFILE="68020"
TOOLCHAIN="auto"
SHIM_DIR="$PROJECT_DIR/lib/posix-shim"

# Parse arguments
SOURCES=()
OUTPUT=""
EXTRA_FLAGS=()

while [ $# -gt 0 ]; do
    case "$1" in
        --target)
            TARGET_PROFILE="$2"
            shift 2
            ;;
        --toolchain)
            TOOLCHAIN="$2"
            shift 2
            ;;
        --shim-dir)
            SHIM_DIR="$2"
            shift 2
            ;;
        -o)
            OUTPUT="$2"
            shift 2
            ;;
        -*)
            EXTRA_FLAGS+=("$1")
            shift
            ;;
        *)
            SOURCES+=("$1")
            shift
            ;;
    esac
done

if [ ${#SOURCES[@]} -eq 0 ]; then
    echo "Usage: cross-compile.sh [options] source.c -o output"
    exit 1
fi

if [ -z "$OUTPUT" ]; then
    OUTPUT="${SOURCES[0]%.c}"
fi

# Load target profile flags
PROFILE_FILE="$CONFIGS_DIR/target-profiles/amiga-${TARGET_PROFILE}.mk"
if [ -f "$PROFILE_FILE" ]; then
    CPU_FLAGS=$(grep "^CPU_FLAGS" "$PROFILE_FILE" | cut -d= -f2 | tr -d ' ')
else
    CPU_FLAGS="-m68020"
fi

# Auto-detect toolchain
if [ "$TOOLCHAIN" = "auto" ]; then
    DETECTED=$(bash "$SCRIPT_DIR/detect-toolchain.sh" | grep recommended | cut -d'"' -f4)
    TOOLCHAIN="$DETECTED"
fi

# Compile flags
CFLAGS="-O2 -noixemul $CPU_FLAGS -Wall -I$SHIM_DIR/include ${EXTRA_FLAGS[*]}"
LDFLAGS="-L$SHIM_DIR -lamiport"

case "$TOOLCHAIN" in
    docker-bebbo-gcc|docker-bebbo)
        echo "Compiling with Docker bebbo-gcc (target: $TARGET_PROFILE)..."
        docker run --rm -v "$PROJECT_DIR:/work" amiport/bebbo-gcc \
            m68k-amigaos-gcc $CFLAGS -o "$OUTPUT" "${SOURCES[@]}" $LDFLAGS
        ;;
    native-bebbo-gcc|native-bebbo)
        echo "Compiling with native bebbo-gcc (target: $TARGET_PROFILE)..."
        m68k-amigaos-gcc $CFLAGS -o "$OUTPUT" "${SOURCES[@]}" $LDFLAGS
        ;;
    native-vbcc)
        echo "Compiling with native VBCC (target: $TARGET_PROFILE)..."
        vc +kick13 $CFLAGS -o "$OUTPUT" "${SOURCES[@]}" $LDFLAGS
        ;;
    none)
        echo "ERROR: No toolchain available. Run 'make setup-toolchain' first."
        exit 1
        ;;
    *)
        echo "ERROR: Unknown toolchain: $TOOLCHAIN"
        exit 1
        ;;
esac

echo "Built: $OUTPUT"
