# libSDL2 for AmigaOS 3.x -- Cross-compilation via bebbo-gcc
#
# Phase 0: Bootstrap -- all stubs, SDL_Init() returns 0

DOCKER_IMAGE = amigadev/crosstools:m68k-amigaos
CC_PREFIX = m68k-amigaos
CC = $(CC_PREFIX)-gcc
AR = $(CC_PREFIX)-ar
RANLIB = $(CC_PREFIX)-ranlib

CFLAGS = -std=gnu99 -O0 -m68020 -noixemul \
         -Wall -Wextra -Wno-unused-parameter \
         -I./include -I./src \
         -DSDL_DYNAMIC_API=0 \
         -D__AMIGAOS3__ \
         -DSDL_VIDEO_DRIVER_AMIGAOS3=1 \
         -DSDL_AUDIO_DRIVER_AHI=1 \
         -DSDL_THREAD_AMIGAOS3=1 \
         -DSDL_TIMER_AMIGAOS3=1 \
         -DSDL_JOYSTICK_AMIGAOS3=1 \
         -DSDL_FILESYSTEM_AMIGAOS3=1 \
         -DSDL_LOADSO_DUMMY=1 \
         -DSDL_HAPTIC_DUMMY=1

# Backend sources -- each phase adds files here
SRCS_VIDEO    = src/video/amigaos3/SDL_os3video.c
SRCS_AUDIO    = src/audio/amigaos3/SDL_os3audio.c
SRCS_THREAD   = src/thread/amigaos3/SDL_systhread.c \
                src/thread/amigaos3/SDL_sysmutex.c \
                src/thread/amigaos3/SDL_syscond.c \
                src/thread/amigaos3/SDL_syssem.c \
                src/thread/amigaos3/SDL_systls.c
SRCS_TIMER    = src/timer/amigaos3/SDL_systimer.c
SRCS_JOYSTICK = src/joystick/amigaos3/SDL_sysjoystick.c
SRCS_FILESYS  = src/filesystem/amigaos3/SDL_sysfilesystem.c
SRCS_LOADSO   = src/loadso/dummy/SDL_sysloadso.c
SRCS_HAPTIC   = src/haptic/dummy/SDL_syshaptic.c
SRCS_MAIN     = src/main/amigaos3/SDL_os3_main.c

SRCS = $(SRCS_VIDEO) $(SRCS_AUDIO) $(SRCS_THREAD) $(SRCS_TIMER) \
       $(SRCS_JOYSTICK) $(SRCS_FILESYS) $(SRCS_LOADSO) $(SRCS_HAPTIC) \
       $(SRCS_MAIN)

OBJS = $(SRCS:.c=.o)

TARGET = libSDL2.a

# --- Targets ---

.PHONY: all clean examples test setup-toolchain docker-build

all: docker-build

# Build inside Docker (default)
docker-build:
	docker run --rm -v "$(PWD):/work" -w /work $(DOCKER_IMAGE) \
		make -f Makefile native-build

# Build natively (called from inside Docker)
native-build: $(TARGET)
	@echo "Built $(TARGET) ($$(wc -c < $(TARGET)) bytes)"

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^
	$(RANLIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

examples: docker-build
	@echo "TODO: Build example programs (Phase 1+)"

test:
	@echo "TODO: FS-UAE RTG testing (Phase 1+)"

setup-toolchain:
	@echo "Pulling bebbo-gcc Docker image..."
	docker pull $(DOCKER_IMAGE)
	@echo "Toolchain ready."

clean:
	rm -f $(OBJS) $(TARGET)

# --- Dependencies ---
# TODO: Auto-generate with -MMD -MP
