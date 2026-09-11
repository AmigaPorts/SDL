# Build ScreenRead for AmigaOS
# Screen state reader for visual verification testing (ADR-025)

CC = ../scripts/m68k-amigaos-gcc
CFLAGS = -O2 -noixemul -m68000 -Wall
SCREENREAD_BIN = ScreenRead

all: $(SCREENREAD_BIN)

$(SCREENREAD_BIN): screenread.c call_screen_trap.s
	$(CC) $(CFLAGS) -o $@ screenread.c call_screen_trap.s

clean:
	rm -f $(SCREENREAD_BIN)

.PHONY: all clean
