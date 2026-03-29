# Capture Learning & Track Progress — Continuous Improvement Rule

## Session Start

At the beginning of every session, call `amiga_get_work({project: "libSDL2"})` to see current plans and outstanding work. This gives you context for what to work on.

## During Work

### Track progress as you go

- When you start working on a todo: `amiga_update_status({type: "todo", title: "...", source_project: "libSDL2", status: "in_progress"})`
- When you complete a todo: `amiga_update_status({type: "todo", title: "...", source_project: "libSDL2", status: "done"})`
- When you discover new work needed: `amiga_add_todo({title: "...", source_project: "libSDL2", work_package: "...", related_apis: [...]})`
- When work is blocked by another project: `amiga_add_dependency({from_title: "...", from_project: "libSDL2", to_title: "...", to_project: "amiport", blocking: true})`

### Capture knowledge

After completing any significant task (build, test, debug, review), check:

1. **Did anything go wrong?** Bug, crash, wrong output, process failure
2. **Did the user correct you?** "No, don't do that", "you forgot X"
3. **Did you discover a new pitfall?** libnix behavior, bebbo-gcc quirk, AmigaOS limitation
4. **Did you bypass expected process?** Skipped a step, used wrong approach

## How to Route Knowledge

**Universal Amiga knowledge** (OS behavior, 68k gotchas, libnix bugs, API pitfalls):
  → Call `amiga_add_pitfall(title, description, severity, relatedApis, "libSDL2")`
  → Call `amiga_add_crash_pattern(symptom, cause, fix, guruCode, relatedApis, "libSDL2")`
  → Call `amiga_report_gap(topic, context, "libSDL2")` for missing documentation

  This routes knowledge to the shared amiga-kb. Both amiport and libSDL2 benefit.

**Project-specific knowledge** (SDL2 backend contracts, build config, test setup):
  → Update the relevant `.claude/rules/` file or skill definition
  → Invoke `/capture-learning` for routing guidance

## Agents: Report Learnings to Main Session

Subagents cannot call MCP tools directly. Include a "Learnings" section in your
final report. The main session will route universal learnings to amiga-kb.

Format:
```
## Learnings
- [PITFALL] vsnprintf(NULL, 0) crashes on libnix — needs probe buffer
- [TODO] Need to implement X before Y works
- [DONE] Completed Z, marked in amiga-kb
- [BLOCKED] Can't do W until amiport adds mmap shim
```
