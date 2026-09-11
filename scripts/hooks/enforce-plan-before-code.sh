#!/bin/bash
# Hook: enforce-plan-before-code.sh
# PreToolUse hook for Edit|Write -- warns when modifying src/**/*.c files
# if no KB plan tracking has been done this session.
#
# Uses a sentinel file (.kb_plan_checked) that the agent should create
# after calling amiga_get_work and creating/confirming a plan.
# The sentinel is gitignored and ephemeral (per-session).
#
# This prevents the pattern where the agent jumps straight into coding
# without first creating a KB plan or checking existing work packages.

FILE_PATH="$TOOL_INPUT_FILE_PATH"

# Only check src/ C source files
case "$FILE_PATH" in
    */src/*.c|*/src/*.h) ;;
    *) exit 0 ;;
esac

# Check for sentinel file indicating KB plan was checked this session
PROJECT_ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
SENTINEL="$PROJECT_ROOT/.kb_plan_checked"

if [ ! -f "$SENTINEL" ]; then
    echo "WARNING: You are editing src/ code without confirming a KB plan."
    echo ""
    echo "MANDATORY before writing implementation code:"
    echo "  1. Call amiga_get_work({project: \"libSDL2\"}) to see current plans"
    echo "  2. Create a plan (amiga_add_plan) if this work has no plan yet"
    echo "  3. Create a sentinel: touch .kb_plan_checked"
    echo ""
    echo "The project-tracking rule requires plan-before-code."
    echo "Do this NOW, then retry your edit."
fi

exit 0
