#!/bin/bash
# amiport doctor — check that all prerequisites are installed

set -euo pipefail

# Color support
if [ -t 1 ] && command -v tput >/dev/null 2>&1 && [ "$(tput colors 2>/dev/null || echo 0)" -ge 8 ]; then
    GREEN=$(tput setaf 2); RED=$(tput setaf 1); YELLOW=$(tput setaf 3); BOLD=$(tput bold); RESET=$(tput sgr0)
else
    GREEN=""; RED=""; YELLOW=""; BOLD=""; RESET=""
fi

OS=$(uname -s)
PASS=0
FAIL=0
WARN=0
TOTAL=5

ok()   { echo "${GREEN}[OK]${RESET}   $1"; PASS=$((PASS + 1)); }
fail() { echo "${RED}[FAIL]${RESET} $1"; echo "       -> $2"; FAIL=$((FAIL + 1)); }
warn() { echo "${YELLOW}[WARN]${RESET} $1"; echo "       -> $2"; WARN=$((WARN + 1)); }

echo "${BOLD}=== amiport prerequisites ===${RESET}"

# 1. Docker (must be running, not just installed)
if docker info >/dev/null 2>&1; then
    ok "Docker (running)"
else
    if [ "$OS" = "Darwin" ]; then
        fail "Docker (not running or not installed)" "brew install --cask docker"
    else
        fail "Docker (not running or not installed)" "apt install docker.io"
    fi
fi

# 2. Cross-compiler: Docker image OR native m68k-amigaos-gcc
if docker image inspect amigadev/m68k-amigaos-gcc >/dev/null 2>&1; then
    ok "Cross-compiler (amigadev/m68k-amigaos-gcc Docker image)"
elif docker image inspect amiport/bebbo-gcc >/dev/null 2>&1; then
    ok "Cross-compiler (amiport/bebbo-gcc Docker image)"
elif command -v m68k-amigaos-gcc >/dev/null 2>&1; then
    ok "Cross-compiler (native m68k-amigaos-gcc)"
else
    fail "Cross-compiler (no Docker image or native gcc found)" "make setup-toolchain"
fi

# 3. vamos
if command -v vamos >/dev/null 2>&1; then
    ok "vamos (amitools)"
else
    fail "vamos (not found)" "pip install amitools"
fi

# 4. lha (optional — only needed for packaging)
if command -v lha >/dev/null 2>&1; then
    ok "lha (archiver)"
else
    if [ "$OS" = "Darwin" ]; then
        warn "lha (optional — needed for packaging)" "brew install lha"
    else
        warn "lha (optional — needed for packaging)" "apt install lha"
    fi
fi

# 5. Python 3
if command -v python3 >/dev/null 2>&1; then
    ok "Python 3"
else
    fail "Python 3 (not found)" "Install Python 3 from https://python.org"
fi

# Summary
echo ""
FOUND=$((PASS + WARN))
OPTIONAL_NOTE=""
if [ "$WARN" -gt 0 ]; then
    OPTIONAL_NOTE=" ($WARN optional missing)"
fi
echo "${BOLD}Result: ${FOUND}/${TOTAL} prerequisites found${OPTIONAL_NOTE}${RESET}"

if [ "$FAIL" -gt 0 ]; then
    echo "${RED}$FAIL required prerequisite(s) missing.${RESET}"
    exit 1
fi
exit 0
