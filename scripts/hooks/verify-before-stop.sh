#!/bin/bash
# Stop hook: Force Claude to verify work before stopping.
# First stop attempt: blocks and tells Claude to verify.
# Second stop attempt (stop_hook_active=true): allows stop to prevent infinite loop.
INPUT=$(cat)
STOP_HOOK_ACTIVE=$(echo "$INPUT" | jq -r '.stop_hook_active // false')

# Second attempt — let it stop
if [ "$STOP_HOOK_ACTIVE" = "true" ]; then
  exit 0
fi

# First attempt — block the stop, Claude sees the reason and must address it
echo '{"continue":false,"stopReason":"Before stopping, verify: (1) run tests if you changed code, (2) no stray files in project root, (3) all affected docs updated per CLAUDE.md rules, (4) if any bugs, mistakes, or process failures occurred this session, run /capture-learning to route the fix to the right enforcement mechanism. Then you may stop."}'
exit 0
