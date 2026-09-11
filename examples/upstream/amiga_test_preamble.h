/*
 * amiga_test_preamble.h -- AmigaOS 3.x boilerplate for upstream SDL2 tests.
 *
 * Injected via -include so upstream sources stay unmodified.
 * Provides stack cookie and version string required by AmigaOS.
 */
#ifndef AMIGA_TEST_PREAMBLE_H
#define AMIGA_TEST_PREAMBLE_H

/* 64KB stack for all upstream tests (SDLTest_Common uses ~1KB on stack).
 * Only define in the main translation unit, not helper objects like testutils.o.
 * The build system compiles testutils.o without -include of this header. */
#ifndef AMIGA_TEST_NO_STACK
long __stack = 65536;
#endif

/* Version string -- overridden per-binary via -D if needed */
#ifndef AMIGA_VERSTAG
#define AMIGA_VERSTAG "$VER: sdl2test 0.1 (28.03.2026)"
#endif
static const char *amiga_verstag __attribute__((used)) = AMIGA_VERSTAG;

#endif /* AMIGA_TEST_PREAMBLE_H */
