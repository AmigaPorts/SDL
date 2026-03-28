Paths: src/**/*.c, src/**/*.h, include/**/*.h, examples/**/*.c

# Known Pitfalls

The shared **amiga-kb** knowledge base has 70+ documented pitfalls.
This file contains only the critical-path items that MUST be in context
during every code generation. For the full KB, use MCP tools.

## How to use pitfalls

**Check pitfalls before writing code:**
  → Call `amiga_pitfalls_for("function_or_topic")`

**Check pitfalls when debugging:**
  → Call `amiga_crash_diagnosis("symptoms or Guru code")`

**Report a new pitfall:**
  → Call `amiga_add_pitfall(title, description, severity, relatedApis, "libSDL2")`
  → Do NOT append to this file. Route to amiga-kb so both projects benefit.

---

## Critical: Always in Context

### bebbo-gcc -O1/-O2 Corrupts Large Struct Returns
Any struct > 4 bytes returned by value is corrupted at -O1 or -O2. **Always use -O0 for files with struct returns**, or return via pointer. Affects SDL_Color, SDL_Rect, SDL_Point.

### 68k Alignment Is 2, Not 4 or 8
68000 requires 2-byte alignment for word/long access. Custom allocators that assume 4 or 8 byte alignment may work on 68020+ but crash on 68000. Use `AMIPORT_ALIGN()`.

### MsgPort Signals Are Task-Relative
`CreateMsgPort()` signal bits belong to the calling task. `WaitIO()` from a different task hangs forever. Create MsgPort in the same task that calls WaitIO. Critical for all SDL2 device backends (audio, timer).

### CreateNewProcTags tc_UserData Race
New process can start before `tc_UserData` is set. Wrap with `Forbid()/Permit()`. Critical for SDL2 thread creation.

### vsnprintf(NULL, 0, ...) Crash
libnix writes to address zero. Use a probe buffer instead.

### Large Local Buffers Cause Guru
>2KB local arrays overflow the 4-8KB default stack. Use static or heap allocation.

### SDL2-Specific: Function Pointer Safety
All SDL backend function pointers must be set to valid functions or NULL. Never leave uninitialized. SDL_VideoDevice, SDL_AudioDevice function tables must be complete.
