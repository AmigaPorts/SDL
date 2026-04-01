# libSDL2 for AmigaOS 3.x -- Cross-compilation via bebbo-gcc
#
# Phase 0: Bootstrap + First Pixels
# Target: 68030 minimum (RTG cards require 68020+, all RTG setups have 68030+)

DOCKER_IMAGE = amigadev/crosstools:m68k-amigaos
CC_PREFIX = m68k-amigaos
CC = $(CC_PREFIX)-gcc
AR = $(CC_PREFIX)-ar
RANLIB = $(CC_PREFIX)-ranlib

CFLAGS = -std=gnu99 -O0 -m68030 -noixemul \
         -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare \
         -I./include -I./src \
         -D__AMIGAOS3__ -DSDL_OS3_DEBUG

# --- SDL2 Core Source Files (platform-independent) ---
# Enumerated from SDL2 CMakeLists.txt (SDL2 branch, commit f9e8203)

SRCS_CORE = \
	src/SDL.c \
	src/SDL_assert.c \
	src/SDL_error.c \
	src/SDL_guid.c \
	src/SDL_hints.c \
	src/SDL_list.c \
	src/SDL_log.c \
	src/SDL_dataqueue.c \
	src/SDL_utils.c

SRCS_ATOMIC = \
	src/atomic/SDL_atomic.c \
	src/atomic/SDL_spinlock.c

SRCS_CPUINFO = \
	src/cpuinfo/SDL_cpuinfo.c

SRCS_DYNAPI = \
	src/dynapi/SDL_dynapi.c

SRCS_STDLIB = \
	src/stdlib/SDL_crc16.c \
	src/stdlib/SDL_crc32.c \
	src/stdlib/SDL_getenv.c \
	src/stdlib/SDL_iconv.c \
	src/stdlib/SDL_malloc.c \
	src/stdlib/SDL_qsort.c \
	src/stdlib/SDL_stdlib.c \
	src/stdlib/SDL_string.c \
	src/stdlib/SDL_strtokr.c \
	src/stdlib/SDL_os3float.c \
	src/stdlib/SDL_os3double.c

SRCS_LIBM = \
	src/libm/e_atan2.c \
	src/libm/e_exp.c \
	src/libm/e_fmod.c \
	src/libm/e_log.c \
	src/libm/e_log10.c \
	src/libm/e_pow.c \
	src/libm/e_rem_pio2.c \
	src/libm/e_sqrt.c \
	src/libm/k_cos.c \
	src/libm/k_rem_pio2.c \
	src/libm/k_sin.c \
	src/libm/k_tan.c \
	src/libm/s_atan.c \
	src/libm/s_copysign.c \
	src/libm/s_cos.c \
	src/libm/s_fabs.c \
	src/libm/s_floor.c \
	src/libm/s_scalbn.c \
	src/libm/s_sin.c \
	src/libm/s_tan.c

SRCS_FILE = \
	src/file/SDL_rwops.c

SRCS_EVENTS = \
	src/events/SDL_clipboardevents.c \
	src/events/SDL_displayevents.c \
	src/events/SDL_dropevents.c \
	src/events/SDL_events.c \
	src/events/SDL_gesture.c \
	src/events/SDL_keyboard.c \
	src/events/SDL_keysym_to_scancode.c \
	src/events/SDL_mouse.c \
	src/events/SDL_quit.c \
	src/events/SDL_scancode_tables.c \
	src/events/SDL_touch.c \
	src/events/SDL_windowevents.c \
	src/events/imKStoUCS.c

# --- Video: core + AmigaOS3 driver + dummy fallback ---
SRCS_VIDEO_CORE = \
	src/video/SDL_RLEaccel.c \
	src/video/SDL_blit.c \
	src/video/SDL_blit_0.c \
	src/video/SDL_blit_1.c \
	src/video/SDL_blit_A.c \
	src/video/SDL_blit_N.c \
	src/video/SDL_blit_auto.c \
	src/video/SDL_blit_copy.c \
	src/video/SDL_blit_slow.c \
	src/video/SDL_bmp.c \
	src/video/SDL_clipboard.c \
	src/video/SDL_fillrect.c \
	src/video/SDL_pixels.c \
	src/video/SDL_rect.c \
	src/video/SDL_shape.c \
	src/video/SDL_stretch.c \
	src/video/SDL_surface.c \
	src/video/SDL_video.c \
	src/video/SDL_yuv.c \
	src/video/yuv2rgb/yuv_rgb_std.c

SRCS_VIDEO_OS3 = \
	src/video/amigaos3/SDL_os3video.c \
	src/video/amigaos3/SDL_os3window.c \
	src/video/amigaos3/SDL_os3framebuffer.c \
	src/video/amigaos3/SDL_os3events.c \
	src/video/amigaos3/SDL_os3mouse.c \
	src/video/amigaos3/SDL_os3aga.c

SRCS_VIDEO_DUMMY = \
	src/video/dummy/SDL_nullevents.c \
	src/video/dummy/SDL_nullframebuffer.c \
	src/video/dummy/SDL_nullvideo.c

SRCS_VIDEO = $(SRCS_VIDEO_CORE) $(SRCS_VIDEO_OS3) $(SRCS_VIDEO_DUMMY)

# --- Audio: core + AmigaOS3 AHI driver + dummy fallback ---
SRCS_AUDIO_CORE = \
	src/audio/SDL_audio.c \
	src/audio/SDL_audiocvt.c \
	src/audio/SDL_audiodev.c \
	src/audio/SDL_audiotypecvt.c \
	src/audio/SDL_mixer.c \
	src/audio/SDL_wave.c

SRCS_AUDIO_OS3 = \
	src/audio/amigaos3/SDL_os3audio.c \
	src/audio/amigaos3/SDL_os3paula.c

SRCS_AUDIO_DUMMY = \
	src/audio/dummy/SDL_dummyaudio.c

SRCS_AUDIO = $(SRCS_AUDIO_CORE) $(SRCS_AUDIO_OS3) $(SRCS_AUDIO_DUMMY)

# --- Threading: core + AmigaOS3 Exec Tasks ---
SRCS_THREAD_CORE = \
	src/thread/SDL_thread.c

SRCS_THREAD_OS3 = \
	src/thread/amigaos3/SDL_systhread.c \
	src/thread/amigaos3/SDL_sysmutex.c \
	src/thread/amigaos3/SDL_syscond.c \
	src/thread/amigaos3/SDL_syssem.c \
	src/thread/amigaos3/SDL_systls.c

SRCS_THREAD = $(SRCS_THREAD_CORE) $(SRCS_THREAD_OS3)

# --- Timer: core + AmigaOS3 ReadEClock ---
SRCS_TIMER_CORE = \
	src/timer/SDL_timer.c

SRCS_TIMER_OS3 = \
	src/timer/amigaos3/SDL_systimer.c

SRCS_TIMER = $(SRCS_TIMER_CORE) $(SRCS_TIMER_OS3)

# --- Joystick: core + AmigaOS3 gameport ---
SRCS_JOYSTICK_CORE = \
	src/joystick/SDL_gamecontroller.c \
	src/joystick/SDL_joystick.c \
	src/joystick/SDL_steam_virtual_gamepad.c \
	src/joystick/controller_type.c

SRCS_JOYSTICK_OS3 = \
	src/joystick/amigaos3/SDL_sysjoystick.c

SRCS_JOYSTICK = $(SRCS_JOYSTICK_CORE) $(SRCS_JOYSTICK_OS3)

# --- Haptic: disabled (dummy) ---
SRCS_HAPTIC = \
	src/haptic/SDL_haptic.c \
	src/haptic/dummy/SDL_syshaptic.c

# --- Render: core + software ---
SRCS_RENDER_CORE = \
	src/render/SDL_d3dmath.c \
	src/render/SDL_render.c \
	src/render/SDL_yuv_sw.c

SRCS_RENDER_SW = \
	src/render/software/SDL_blendfillrect.c \
	src/render/software/SDL_blendline.c \
	src/render/software/SDL_blendpoint.c \
	src/render/software/SDL_drawline.c \
	src/render/software/SDL_drawpoint.c \
	src/render/software/SDL_render_sw.c \
	src/render/software/SDL_rotate.c \
	src/render/software/SDL_triangle.c

SRCS_RENDER = $(SRCS_RENDER_CORE) $(SRCS_RENDER_SW)

# --- Filesystem: AmigaOS3 (PROGDIR: / ENVARC:) ---
SRCS_FILESYS = \
	src/filesystem/amigaos3/SDL_sysfilesystem.c

# --- Loadso: disabled (dummy) ---
SRCS_LOADSO = \
	src/loadso/dummy/SDL_sysloadso.c

# --- Sensor: disabled ---
# (SDL_sensor.c compiled but with SDL_SENSOR_DISABLED, no backend needed)
SRCS_SENSOR = \
	src/sensor/SDL_sensor.c \
	src/sensor/dummy/SDL_dummysensor.c

# --- Power: disabled (no battery on Amiga) ---
SRCS_POWER = \
	src/power/SDL_power.c

# --- Locale: dummy stub ---
SRCS_LOCALE = \
	src/locale/SDL_locale.c \
	src/locale/dummy/SDL_syslocale.c

# --- Misc/URL: dummy stub ---
SRCS_MISC = \
	src/misc/SDL_url.c \
	src/misc/dummy/SDL_sysurl.c

# --- Main entry point ---
SRCS_MAIN = \
	src/main/amigaos3/SDL_os3_main.c

# --- Complete source list ---
SRCS = $(SRCS_CORE) $(SRCS_ATOMIC) $(SRCS_CPUINFO) $(SRCS_DYNAPI) \
       $(SRCS_STDLIB) $(SRCS_LIBM) $(SRCS_FILE) $(SRCS_EVENTS) \
       $(SRCS_VIDEO) $(SRCS_AUDIO) $(SRCS_THREAD) $(SRCS_TIMER) \
       $(SRCS_JOYSTICK) $(SRCS_HAPTIC) $(SRCS_RENDER) \
       $(SRCS_FILESYS) $(SRCS_LOADSO) $(SRCS_SENSOR) \
       $(SRCS_POWER) $(SRCS_LOCALE) $(SRCS_MISC) $(SRCS_MAIN)

OBJS = $(SRCS:.c=.o)

TARGET = libSDL2.a

# --- SDL2_test library (test framework for upstream tests) ---
SRCS_TEST_LIB = \
	src/test/SDL_test_assert.c \
	src/test/SDL_test_common.c \
	src/test/SDL_test_compare.c \
	src/test/SDL_test_crc32.c \
	src/test/SDL_test_font.c \
	src/test/SDL_test_fuzzer.c \
	src/test/SDL_test_harness.c \
	src/test/SDL_test_imageBlit.c \
	src/test/SDL_test_imageBlitBlend.c \
	src/test/SDL_test_imageFace.c \
	src/test/SDL_test_imagePrimitives.c \
	src/test/SDL_test_imagePrimitivesBlend.c \
	src/test/SDL_test_log.c \
	src/test/SDL_test_md5.c \
	src/test/SDL_test_memory.c \
	src/test/SDL_test_random.c

OBJS_TEST_LIB = $(SRCS_TEST_LIB:.c=.o)
TEST_LIB = libSDL2_test.a

# --- Targets ---

.PHONY: all clean examples test test-fsemu test-vamos setup-toolchain docker-build

all: docker-build

# Build inside Docker (default)
docker-build:
	docker run --rm -v "$(PWD):/work" -w /work $(DOCKER_IMAGE) \
		make -f Makefile native-build

# Build natively (called from inside Docker)
native-build: $(TARGET) $(TEST_LIB)
	@echo "Built $(TARGET) ($$(wc -c < $(TARGET)) bytes)"
	@echo "Built $(TEST_LIB) ($$(wc -c < $(TEST_LIB)) bytes)"
	@echo "Sources: $$(echo $(SRCS) | wc -w) files"

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^
	$(RANLIB) $@

$(TEST_LIB): $(OBJS_TEST_LIB)
	$(AR) rcs $@ $^
	$(RANLIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build example programs
examples: docker-build
	docker run --rm -v "$(PWD):/work" -w /work $(DOCKER_IMAGE) \
		make -f Makefile native-examples

# Build example/test programs.
# tests.txt format: NAME CATEGORY TIER [DEPS]
# DEPS: (empty)=SDL only, TEST=+libSDL2_test, UTILS=+testutils.o
# Source lookup: examples/upstream/NAME.c first, then examples/NAME.c
CFLAGS_UPSTREAM = $(CFLAGS) -include examples/upstream/amiga_test_preamble.h

native-examples: $(TARGET) $(TEST_LIB)
	$(CC) $(CFLAGS) -o examples/test_bare examples/test_bare.c
	@echo "Built examples/test_bare (no SDL)"
	$(CC) $(CFLAGS) -o examples/test_beep examples/test_beep.c -lamiga
	@echo "Built examples/test_beep (no SDL, audio.device test)"
	@if [ -f lib/SDL2_mixer/libSDL2_mixer.a ]; then \
		$(CC) $(CFLAGS) -Ilib/SDL2_mixer/include \
			-o examples/test_mixer examples/test_mixer.c \
			-Llib/SDL2_mixer -L. -lSDL2_mixer -lSDL2 -ldebug -lamiga -lm -lstubs && \
		echo "Built examples/test_mixer (SDL2_mixer)"; \
	fi
	@grep -v '^#' tests.txt | grep -v '^\s*$$' | grep -v test_bare | while read t cat tier deps rest; do \
		if [ -f "examples/upstream/$$t.c" ]; then \
			src="examples/upstream/$$t.c"; \
			cf="$(CFLAGS_UPSTREAM)"; \
		else \
			src="examples/$$t.c"; \
			cf="$(CFLAGS)"; \
		fi; \
		libs="-L. -lSDL2 -ldebug -lamiga -lm -lstubs"; \
		case "$$deps" in *TEST*) libs="-L. -lSDL2_test -lSDL2 -ldebug -lamiga -lm -lstubs" ;; esac; \
		utils=""; \
		case "$$deps" in \
			*UTILS*) \
				if [ ! -f examples/upstream/testutils.o ]; then \
					$(CC) $(CFLAGS) -I./examples/upstream -c examples/upstream/testutils.c -o examples/upstream/testutils.o; \
				fi; \
				utils="examples/upstream/testutils.o" ;; \
		esac; \
		$(CC) $$cf -o examples/$$t $$src $$utils $$libs && \
		echo "Built examples/$$t" ; \
	done

test: test-vamos

# Run vamos smoke tests (fast, no GUI, no RTG)
# Tier 1 and 12 tests from tests.txt are run on vamos.
# vamos -C 68020: 68030 integer ISA == 68020, vamos has no -C 68030
VAMOS = vamos -C 68020 -s 32 -m 8192

test-vamos: examples
	@echo "=== vamos smoke tests ==="
	@PASS=0; TOTAL=0; \
	for line in $$(grep -v '^#' tests.txt | awk '$$3 ~ /1/ {print $$1}'); do \
		TOTAL=$$((TOTAL + 1)); \
		echo "--- $$line ---"; \
		$(VAMOS) examples/$$line && { echo "PASS $$line"; PASS=$$((PASS + 1)); } || { echo "FAIL $$line"; exit 1; }; \
	done; \
	echo "=== vamos: $$PASS/$$TOTAL passed ==="

# Run full FS-UAE test suite (RTG, all tests)
# Requires FS-UAE, Kickstart 3.1 ROM, and build/system/ WB 3.1
# Use TEST=test_foo to run a single test: make test-fsemu TEST=test_audio
test-fsemu:
	scripts/test-fsemu.sh $(if $(TEST),--target $(TEST))

# Run FS-UAE tests without rebuilding examples first
test-fsemu-no-build:
	scripts/test-fsemu.sh --no-build $(if $(TEST),--target $(TEST))

setup-toolchain:
	@echo "Pulling bebbo-gcc Docker image..."
	docker pull $(DOCKER_IMAGE)
	@echo "Toolchain ready."

clean:
	find src -name '*.o' -delete
	rm -f $(TARGET) $(TEST_LIB) examples/test_init examples/upstream/testutils.o

# --- Release ---
release:
	scripts/release.sh

release-dry-run:
	scripts/release.sh --dry-run

# --- Dependencies ---
# TODO: Auto-generate with -MMD -MP
