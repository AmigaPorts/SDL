#!/bin/bash
# PreToolUse hook: Block direct gcc/cc/ld/as calls in Bash
# Forces agents to use the toolchain wrapper scripts or make targets.
INPUT=$(cat)
CMD=$(echo "$INPUT" | jq -r '.tool_input.command // empty')

# Only check for direct compiler invocations, not make or docker commands
if echo "$CMD" | grep -vE '(^make |docker |toolchain/)' | grep -qE '\b(m68k-amigaos-gcc|m68k-amigaos-ld|m68k-amigaos-as)\b'; then
  echo "BLOCKED: Use 'make build TARGET=...' or toolchain/scripts/cross-compile.sh instead of calling the cross-compiler directly." >&2
  exit 2
fi
exit 0
