# libSDL2_mixer for AmigaOS 3.x -- Cross-compilation via bebbo-gcc
#
# Phase A: WAV-only (zero external dependencies)
# Produces: libSDL2_mixer.a
#
# Usage:
#   make                 # Build via Docker (default)
#   make docker-build    # Same as above
#   make native-build    # Called from inside Docker

DOCKER_IMAGE = amigadev/crosstools:m68k-amigaos
CC = m68k-amigaos-gcc
AR = m68k-amigaos-ar
RANLIB = m68k-amigaos-ranlib

# Path to libSDL2 project root (for SDL2 headers)
SDL2_DIR = ../..

CFLAGS = -std=gnu99 -O0 -m68030 -noixemul \
         -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare \
         -I$(SDL2_DIR)/include -I$(SDL2_DIR)/src \
         -Iinclude -Isrc -Isrc/codecs \
         -D__AMIGAOS3__ \
         -DMUSIC_WAV

# --- Source files (WAV-only build) ---

SRCS = \
	src/mixer.c \
	src/music.c \
	src/utils.c \
	src/effects_internal.c \
	src/effect_position.c \
	src/effect_stereoreverse.c \
	src/codecs/music_wav.c \
	src/codecs/load_aiff.c \
	src/codecs/load_voc.c \
	src/codecs/mp3utils.c \
	src/codecs/remap_channels.c

OBJS = $(SRCS:.c=.o)
TARGET = libSDL2_mixer.a

.PHONY: all clean docker-build native-build

all: docker-build

docker-build:
	docker run --rm -v "$$(cd $(SDL2_DIR) && pwd):/work" \
		-w /work/lib/SDL2_mixer \
		$(DOCKER_IMAGE) \
		make -f Makefile native-build SDL2_DIR=/work

native-build: $(TARGET)
	@echo "Built $(TARGET) ($$(wc -c < $(TARGET)) bytes)"
	@echo "Sources: $$(echo $(SRCS) | wc -w) files"

$(TARGET): $(OBJS)
	$(AR) rcs $@ $^
	$(RANLIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
