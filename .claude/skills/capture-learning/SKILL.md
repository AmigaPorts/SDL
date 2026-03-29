---
name: capture-learning
description: Route a bug, pitfall, or process failure to the right enforcement mechanism (crash-patterns, known-pitfalls, memory, agent prompt, or hook)
user_invocable: true
---

# Capture Learning

Route a discovery from this session to the right enforcement mechanism so it
is never repeated. Called after bugs, crashes, wrong output, user corrections,
or process failures.

## Instructions

When invoked, analyze what happened and route to ONE of these destinations:

### 1. Crash Pattern
**When:** Guru Meditation, ALERT code, silent hang, memory corruption.
**Action (MCP FIRST):** Call `mcp__amiga-kb__amiga_add_crash_pattern` to add to the shared KB. This is the primary store -- both amiport and libSDL2 benefit.
**Also:** Add a numbered entry to `docs/references/crash-patterns.md` for local reference.

### 2. Known Pitfall
**When:** API misuse, behavioral difference between platforms, toolchain quirk.
**Action (MCP FIRST):** Call `mcp__amiga-kb__amiga_add_pitfall` to add to the shared KB. This is the primary store -- both amiport and libSDL2 benefit.
**Also:** If critical-path (affects every build/test), add to `.claude/rules/known-pitfalls.md`.

### 3. Memory (auto-memory system)
**When:** User preference, process correction, project context that helps future sessions.
**Action:** Write to the appropriate memory file (feedback, project, user, reference).

### 4. Agent Prompt Update
**When:** An agent produced wrong output because its prompt was missing context.
**Action:** Edit the agent's .claude/agents/<name>.md to add the missing guidance.

### 5. Hook or Rule
**When:** A behavior should be BLOCKED or WARNED about automatically.
**Action:** Create a hookify rule or update .claude/rules/ file.

### 6. Reference Doc Update
**When:** A reference doc was wrong, incomplete, or missing.
**Action:** Update the doc in docs/references/.

## Decision Tree

```
Did something crash or hang?
  YES -> Crash Pattern (#1)
  NO  -> Was it an API misuse or platform difference?
           YES -> Known Pitfall (#2)
           NO  -> Was it a user correction or preference?
                    YES -> Memory (#3)
                    NO  -> Did an agent make a mistake?
                             YES -> Agent Prompt (#4)
                             NO  -> Should it be auto-prevented?
                                      YES -> Hook/Rule (#5)
                                      NO  -> Was a doc wrong?
                                               YES -> Reference Doc (#6)
                                               NO  -> Not a learning
```

## After Routing

1. Make the change (edit file, write memory, create hook)
2. Confirm what was captured and where
3. If the learning came from an agent, include it in the agent's response too
