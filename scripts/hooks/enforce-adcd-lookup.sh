#!/bin/bash
# Hook: enforce-adcd-lookup.sh
# PreToolUse hook for Edit|Write — warns when modifying C files that
# contain AmigaOS API includes (proto/*.h, devices/*.h, exec/*.h)
# without having loaded the ADCD reference docs.
#
# This is a WARN hook (exits 0 with message), not a BLOCK hook.
# The agent sees the warning and should invoke /amiga-api-lookup.

FILE_PATH="$TOOL_INPUT_FILE_PATH"

# Only check C source files
case "$FILE_PATH" in
    *.c|*.h) ;;
    *) exit 0 ;;
esac

# Skip if file doesn't exist yet (new file creation)
[ -f "$FILE_PATH" ] || exit 0

# Check if file includes AmigaOS API headers
if grep -qE '#include\s*<(proto|devices|exec|intuition|graphics|libraries|dos)/' "$FILE_PATH" 2>/dev/null; then
    echo "WARNING: This file includes AmigaOS API headers."
    echo "MANDATORY: Invoke /amiga-api-lookup before writing AmigaOS API code."
    echo "MANDATORY: Dispatch hardware-expert agent for hardware assumptions."
    echo "Do NOT guess at struct layouts, function signatures, or field offsets."
fi

exit 0
