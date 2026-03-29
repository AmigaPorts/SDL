Paths: src/**/*.c, src/**/*.h, examples/**/*.c

# Debugging Rules

## DLOG/SDL_Log File-Based Debugging -- MANDATORY

**When debugging crashes on FS-UAE, ALWAYS use file-based logging:**

1. **For SDL2 source code:** Use `SDL_Log()` -- it automatically writes to `WORK:sdl_log.txt` on AmigaOS (survives crashes).
2. **For backend code:** Use `DLOG()` from `SDL_os3debug.h` -- writes to `WORK:sdl_debug.log`.
3. **After running on FS-UAE:** Read `build/amiga/sdl_log.txt` or `build/amiga/sdl_debug.log` from the host.

**NEVER rely on printf/fprintf for crash debugging** -- console output dies with the Guru.

## Systematic Step-Through Debugging

When a function crashes, add SDL_Log calls BETWEEN each line to narrow down the exact crash point:

```c
SDL_Log("step 1: before X");
X();
SDL_Log("step 2: after X, before Y");
Y();
SDL_Log("step 3: after Y");
```

The last line that appears in `sdl_log.txt` tells you exactly which call crashed. Binary search to narrow further.

## Do Not Guess -- Instrument and Observe

Per CLAUDE.md Rule 0: add debug output, read the actual values, THEN form a theory. Don't hypothesize the fix -- verify the root cause first.
