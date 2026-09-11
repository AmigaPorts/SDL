#!/bin/bash
# PreToolUse hook: Block Write/Edit of C source files containing non-ASCII bytes.
# bebbo-gcc preprocessor silently eats code around UTF-8 characters.

# The hook receives tool input on stdin as JSON.
# For Edit: file_path, old_string, new_string
# For Write: file_path, content

INPUT=$(cat)
FILE_PATH=$(echo "$INPUT" | grep -o '"file_path"[[:space:]]*:[[:space:]]*"[^"]*"' | head -1 | sed 's/.*"file_path"[[:space:]]*:[[:space:]]*"//;s/"$//')

# Only check C source files
case "$FILE_PATH" in
    *.c|*.h)
        ;;
    *)
        exit 0
        ;;
esac

# Check new_string (Edit) or content (Write) for non-ASCII
NEW_CONTENT=$(echo "$INPUT" | python3 -c "
import sys, json
try:
    data = json.load(sys.stdin)
    text = data.get('new_string', '') or data.get('content', '')
    print(text)
except:
    pass
" 2>/dev/null)

if echo "$NEW_CONTENT" | LC_ALL=C grep -Pn '[^\x00-\x7F]' > /dev/null 2>&1; then
    echo "BLOCKED: Non-ASCII characters detected in C source file: $FILE_PATH"
    echo "bebbo-gcc silently corrupts preprocessor output on UTF-8 bytes."
    echo "Replace: em-dash with --, arrows with ->, smart quotes with straight quotes."
    echo ""
    echo "Offending bytes:"
    echo "$NEW_CONTENT" | LC_ALL=C grep -Pn '[^\x00-\x7F]' | head -5
    exit 2
fi

exit 0
