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

### Fix AHI audio backend for 16-bit stereo
- **What:** Debug and fix the AHI audio backend (SDL_os3audio.c) so SDL2_mixer gets proper 16-bit stereo output
- **Why:** Paula caps at 8-bit mono 22kHz. AHI unlocks 16-bit stereo with panning -- critical for SDL2_mixer quality and future ports (OpenTTD, Stratagus). AHI code exists in SDL_os3audio.c but is non-functional on FS-UAE.
- **How:** Install AHI device in FS-UAE system partition. Debug OpenDevice/CMD_WRITE flow. Reference SDL 1.2 AHI backend (indexed in amiga-kb). Test with examples/loopwave and examples/test_mixer.
- **Depends on:** Phase A SDL2_mixer complete (so we have a test harness), AHI installed in FS-UAE
- **Target:** Post Phase A
- **Added:** 2026-03-29 via /plan-eng-review

### Phase B: MIDI music via SDL2_mixer timidity
- **What:** Enable MUSIC_MID_TIMIDITY in SDL2_mixer build to add MIDI playback
- **Why:** Chocolate Doom converts MUS to MIDI. With timidity, SDL2_mixer plays MIDI natively instead of relying on OPL emulation. Also needed for any future port that expects MIDI music support.
- **How:** Add -DMUSIC_MID_TIMIDITY to SDL2_mixer CFLAGS. Compile ~4850 LOC timidity source (bundled, no external deps). Ship GUS patch set (~4MB) to Amiga filesystem. Verify SDL_sin/cos from SDL2 libm work on 68k (timidity tables.h uses them).
- **Risk:** Float math on 68k -- our custom __divsf3 and SDL2 libm handle this but needs verification.
- **Depends on:** Phase A SDL2_mixer complete, AHI working (timidity on Paula would be very low quality)
- **Target:** After AHI is fixed
- **Added:** 2026-03-29 via /plan-eng-review

### Custom c2p for AGA performance
- **What:** Replace WriteChunkyPixels with optimized c2p if frame time is too high
- **Why:** System c2p (WriteChunkyPixels) may be 30-50ms/frame on 68030. Games need <16ms for 60 FPS or <33ms for 30 FPS.
- **How:** Measure WCP frame time on FS-UAE A1200 config with C&C. If >15ms, implement Kalms c2p1x1_8_c5_gen (public domain, 68020+ asm) or pure C 5-pass merge algorithm. Assembly API: `c2p1x1_8_c5_gen_init(w, h, offsx, offsy)` + `c2p1x1_8_c5_gen(src, dst)`. Repository: github.com/Kalmalyzer/kalms-c2p/normal/
- **Depends on:** AGA backend working (WriteChunkyPixels path functional)
- **Target:** Phase 6 optimization
- **Added:** 2026-04-01 via /plan-eng-review
