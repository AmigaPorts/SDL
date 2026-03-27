# Capture Learning — Continuous Improvement Rule

## When to Invoke `/capture-learning`

After completing any significant task (port, build, test, debug, review), check:

1. **Did anything go wrong?** Bug, crash, wrong output, process failure, missing doc
2. **Did the user correct you?** "No, don't do that", "you forgot X", "use the agent"
3. **Did you discover a new pitfall?** libnix behavior, bebbo-gcc quirk, AmigaOS limitation
4. **Did you bypass the pipeline?** Built directly instead of using an agent, skipped a step

If YES to any: invoke `/capture-learning` before the session ends. State what happened, what should have happened, and let the skill route it to the right enforcement mechanism (hook > rule > agent > skill > pitfall > memory).

## Agents: Report Learnings to Main Session

Subagents cannot invoke skills directly. Instead, **include a "Learnings" section in your final report** listing any bugs, surprises, or process issues discovered. The main session will route these via `/capture-learning`.

Format:
```
## Learnings
- [PITFALL] vsnprintf(NULL, 0) crashes on libnix — needs probe buffer
- [PROCESS] Had to rebuild twice because X was missing
- [BUG] Function Y returns wrong value when Z
```
