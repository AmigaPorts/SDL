# TODOS

## Post-Phase 0

### Per-file optimization audit
- **What:** Identify which SDL2 core files can safely compile with -O2 vs -O0
- **Why:** -O0 increases binary size ~30-50% and hurts performance. Phase 6 needs -O2 for blitters. bebbo-gcc (GCC 6.5.0b) has codegen bugs at -O1/-O2 (struct returns > 8 bytes corrupted), but most files don't trigger this.
- **How:** After Phase 0, systematically test each .c file with -O2. Run test suite after each change. Build a per-file CFLAGS override in the Makefile.
- **Depends on:** Phase 0 complete, Phase 1 test suite
- **Added:** 2026-03-27 via /plan-eng-review (Codex point #7)

### SDL_main WBStartup implementation
- **What:** Proper SDL_main entry point with WBStartup message handling, __stack cookie, and AmigaOS startup sequence
- **Why:** Without this, SDL2 programs can only be launched from CLI, not Workbench. Real-world usage requires both launch methods.
- **How:** Handle WBenchMsg in SDL_os3_main.c. Reply to WBStartup message on exit. Set __stack cookie for stack allocation. Reference SDL 1.2 68k and SDL2 OS4 SDL_main implementations.
- **Depends on:** Phase 0 complete (CLI launch works first)
- **Target:** Phase 2 (input/events, when Workbench launch matters)
- **Added:** 2026-03-27 via /plan-eng-review (Codex point #10)

### Robust SDL_GetPrefPath implementation
- **What:** Replace simple ENVARC: path with proper persistent preferences handling
- **Why:** Phase 0 uses ENVARC:{org}/{app}/ which works but doesn't handle directory creation, CLI vs Workbench launch differences, or edge cases (missing ENVARC:, long path names)
- **How:** Use CreateDir() to ensure path exists. Handle both CLI and Workbench launch contexts. Consider S: as fallback if ENVARC: is unavailable. Test with multiple apps to verify isolation.
- **Depends on:** Phase 0 filesystem backend exists
- **Target:** Phase 5 (polish)
- **Added:** 2026-03-27 via /plan-ceo-review (Codex point #8)

### AHI reference documentation
- **What:** Create docs/references/ahi-reference.md documenting AHI audio API
- **Why:** AHI is a third-party library not in ADCD. Needed before implementing audio backend in Phase 3.
- **How:** Document AHI_AllocAudio(), AHI_ControlAudio(), callback-based audio, mixing modes. Source: AHI autodocs, ahi_protos.h, SDL 1.2 source.
- **Depends on:** Nothing (documentation task)
- **Target:** Phase 3 (audio)
- **Added:** 2026-03-27 via /plan-ceo-review (deferred expansion)
