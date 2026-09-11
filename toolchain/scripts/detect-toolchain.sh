#!/bin/bash
#
# detect-toolchain.sh — Detect available Amiga cross-compilers
#
# Outputs a JSON summary of available toolchains for use by
# the build-amiga skill.

HAS_DOCKER=false
HAS_DOCKER_BEBBO=false
HAS_DOCKER_VBCC=false
HAS_NATIVE_GCC=false
HAS_NATIVE_VBCC=false
RECOMMENDED=""

# Check Docker
if command -v docker &> /dev/null; then
    HAS_DOCKER=true
    if docker image inspect amigadev/m68k-amigaos-gcc &> /dev/null 2>&1; then
        HAS_DOCKER_BEBBO=true
        RECOMMENDED="docker-bebbo-gcc"
    elif docker image inspect amiport/bebbo-gcc &> /dev/null 2>&1; then
        HAS_DOCKER_BEBBO=true
        RECOMMENDED="docker-bebbo-gcc"
    fi
    if docker image inspect amiport/vbcc &> /dev/null; then
        HAS_DOCKER_VBCC=true
        [ -z "$RECOMMENDED" ] && RECOMMENDED="docker-vbcc"
    fi
fi

# Check native
if command -v m68k-amigaos-gcc &> /dev/null; then
    HAS_NATIVE_GCC=true
    [ -z "$RECOMMENDED" ] && RECOMMENDED="native-bebbo-gcc"
fi

if command -v vc &> /dev/null; then
    HAS_NATIVE_VBCC=true
    [ -z "$RECOMMENDED" ] && RECOMMENDED="native-vbcc"
fi

[ -z "$RECOMMENDED" ] && RECOMMENDED="none"

cat <<EOF
{
  "docker": $HAS_DOCKER,
  "docker_bebbo_gcc": $HAS_DOCKER_BEBBO,
  "docker_vbcc": $HAS_DOCKER_VBCC,
  "native_gcc": $HAS_NATIVE_GCC,
  "native_vbcc": $HAS_NATIVE_VBCC,
  "recommended": "$RECOMMENDED"
}
EOF
