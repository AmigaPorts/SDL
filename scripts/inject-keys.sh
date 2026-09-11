#!/bin/bash
#
# inject-keys.sh — Send keystrokes to FS-UAE window from macOS host
#
# Builds a SINGLE osascript invocation containing all keystrokes.
# Each osascript call has ~5s overhead, so batching is critical.
#
# Usage: inject-keys.sh <fs-uae-pid> <key-sequence>
#   inject-keys.sh 12345 "WAIT2000,CTRL_N,WAIT1000"
#
# Architecture: ADR-025

set -euo pipefail

FSUAE_PID="${1:?Usage: inject-keys.sh <fs-uae-pid> <key-sequence>}"
KEYS="${2:?Usage: inject-keys.sh <fs-uae-pid> <key-sequence>}"

# Build a single AppleScript with all keystrokes
SCRIPT='tell application "System Events"
    tell process "fs-uae"
        set frontmost to true
'

IFS=',' read -ra TOKENS <<< "$KEYS"

for token in "${TOKENS[@]}"; do
    token=$(echo "$token" | tr -d ' ')

    case "$token" in
        WAIT[0-9]*)
            ms="${token#WAIT}"
            secs=$(echo "scale=3; $ms / 1000" | bc)
            SCRIPT+="        delay $secs
"
            ;;
        UP)       SCRIPT+='        key code 126
' ;;
        DOWN)     SCRIPT+='        key code 125
' ;;
        LEFT)     SCRIPT+='        key code 123
' ;;
        RIGHT)    SCRIPT+='        key code 124
' ;;
        RETURN)   SCRIPT+='        key code 36
' ;;
        ESC)      SCRIPT+='        key code 53
' ;;
        SPACE)    SCRIPT+='        key code 49
' ;;
        TAB)      SCRIPT+='        key code 48
' ;;
        BACKSPACE) SCRIPT+='        key code 51
' ;;
        DELETE)   SCRIPT+='        key code 117
' ;;
        F1)       SCRIPT+='        key code 122
' ;;
        F2)       SCRIPT+='        key code 120
' ;;
        F3)       SCRIPT+='        key code 99
' ;;
        F4)       SCRIPT+='        key code 118
' ;;
        F5)       SCRIPT+='        key code 96
' ;;
        F6)       SCRIPT+='        key code 97
' ;;
        F7)       SCRIPT+='        key code 98
' ;;
        F8)       SCRIPT+='        key code 100
' ;;
        F9)       SCRIPT+='        key code 101
' ;;
        F10)      SCRIPT+='        key code 109
' ;;
        HELP)     SCRIPT+='        key code 114
' ;;
        CTRL_*)
            key="${token#CTRL_}"
            case "$key" in
                [A-Z]) key=$(echo "$key" | tr 'A-Z' 'a-z')
                       SCRIPT+="        keystroke \"$key\" using control down
" ;;
                [a-z]) SCRIPT+="        keystroke \"$key\" using control down
" ;;
                SPACE) SCRIPT+='        key code 49 using control down
' ;;
                SLASH) SCRIPT+='        keystroke "/" using control down
' ;;
                *)     echo "inject-keys: unknown CTRL_ target: $key" >&2 ;;
            esac
            ;;
        ALT_*)
            key="${token#ALT_}"
            case "$key" in
                [A-Z]) key=$(echo "$key" | tr 'A-Z' 'a-z')
                       SCRIPT+="        keystroke \"$key\" using option down
" ;;
                [a-z]) SCRIPT+="        keystroke \"$key\" using option down
" ;;
                *)     echo "inject-keys: unknown ALT_ target: $key" >&2 ;;
            esac
            ;;
        ?)
            SCRIPT+="        keystroke \"$token\"
"
            ;;
        *)
            echo "inject-keys: unknown token: $token" >&2
            ;;
    esac
done

SCRIPT+='    end tell
end tell'

# Single osascript call — all keystrokes in one batch
osascript -e "$SCRIPT" 2>/dev/null
