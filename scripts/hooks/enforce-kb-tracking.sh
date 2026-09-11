#!/bin/bash
# Hook: enforce-kb-tracking.sh
# Stop hook — blocks stop if code was changed this session but KB tracking
# may not have been updated. Checks for uncommitted or recently committed
# changes to src/ files, which indicates implementation work was done.
#
# This prevents the pattern where sessions complete major work (entire phases)
# without updating amiga-kb plans/todos, leaving the KB stale.

INPUT=$(cat)
STOP_HOOK_ACTIVE=$(echo "$INPUT" | jq -r '.stop_hook_active // false')

# Second attempt — let it through (prevent infinite loop)
if [ "$STOP_HOOK_ACTIVE" = "true" ]; then
  exit 0
fi

# Check if any src/ files were modified (staged, unstaged, or committed today)
cd "$(dirname "$0")/../.." || exit 0

DIRTY_SRC=$(git diff --name-only HEAD 2>/dev/null | grep -c '^src/')
STAGED_SRC=$(git diff --cached --name-only 2>/dev/null | grep -c '^src/')
TODAY=$(date +%Y-%m-%d)
COMMITTED_TODAY=$(git log --since="$TODAY" --name-only --pretty=format: 2>/dev/null | grep -c '^src/')

TOTAL=$((DIRTY_SRC + STAGED_SRC + COMMITTED_TODAY))

if [ "$TOTAL" -gt 0 ]; then
  jq -n '{
    "decision": "block",
    "reason": "You changed src/ files this session. Before stopping: (1) call amiga_get_work({project: \"libSDL2\"}) to see current KB state, (2) call amiga_update_status for any todos you completed or started, (3) call amiga_add_todo for any new work discovered. The KB went stale before because this was not enforced. Do it now, then stop."
  }'
  exit 0
fi

# No src/ changes — no enforcement needed
exit 0
