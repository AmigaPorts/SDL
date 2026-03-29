# Project Tracking — Mandatory Workflow

## Session Start (ALWAYS DO THIS FIRST)

At the very beginning of every session, before doing any work:

1. Call `amiga_get_work({project: "libSDL2"})` to see current plans and outstanding work
2. Report to the user what the current project state is: active plans, outstanding todos, any blockers
3. If the user's request maps to an existing todo, mention it: "This looks like it maps to the todo 'X' in work package 'Y'"

## During Work

### Creating new work
When the user asks to implement something that doesn't have a plan yet:
- Create one: `amiga_add_plan({title: "...", source_project: "libSDL2", template: "sdl2-subsystem"})` for new subsystem work
- Or add todos to existing plans: `amiga_add_todo({title: "...", source_project: "libSDL2", work_package: "...", related_apis: [...]})`

### Tracking progress
- When you start working on something: `amiga_update_status({type: "todo", title: "...", source_project: "libSDL2", status: "in_progress"})`
- When you finish something: `amiga_update_status({type: "todo", title: "...", source_project: "libSDL2", status: "done"})`
- When you discover a blocker from another project: `amiga_add_dependency({from_title: "...", from_project: "libSDL2", to_title: "...", to_project: "amiport", blocking: true})`

### Discovering new work
When debugging or implementing reveals new tasks:
- `amiga_add_todo({title: "...", source_project: "libSDL2", work_package: "...", related_apis: ["FunctionName"]})`
- Link to relevant AmigaOS APIs so the knowledge graph connects your work to known pitfalls

## Session End

Before ending a session, update the status of any todos you worked on. The dream loop and dashboard track staleness based on `updated_at`.

## Available Templates

For new plans, use these templates:
- `sdl2-subsystem` — for implementing a new SDL2 backend subsystem (video, audio, etc.)
- `port-library` — for porting a POSIX library (if bundling a dependency)
