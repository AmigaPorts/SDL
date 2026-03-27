#!/bin/bash
# SessionStart hook: Check toolchain prerequisites and inject status.
ISSUES=""

# Check Docker
if ! command -v docker &>/dev/null; then
  ISSUES="${ISSUES}Docker is not installed. "
elif ! docker info &>/dev/null 2>&1; then
  ISSUES="${ISSUES}Docker is not running. "
fi

# Check vamos (amitools)
if ! command -v vamos &>/dev/null; then
  ISSUES="${ISSUES}vamos not found (pip install amitools). "
fi

# Check lha
if ! command -v lha &>/dev/null; then
  ISSUES="${ISSUES}lha not found (needed for packaging). "
fi

# Check jq (used by hooks)
if ! command -v jq &>/dev/null; then
  ISSUES="${ISSUES}jq not found (needed by hooks). "
fi

if [ -n "$ISSUES" ]; then
  echo "{\"systemMessage\":\"Toolchain issues: ${ISSUES}Some pipeline stages may fail.\"}"
fi

exit 0
