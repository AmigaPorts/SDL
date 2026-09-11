# Build KeyInject for AmigaOS
# Keystroke injector for automated interactive testing (ADR-023)

CC = ../scripts/m68k-amigaos-gcc
CFLAGS = -O2 -noixemul -m68000 -Wall
KEYINJECT_BIN = KeyInject

all: $(KEYINJECT_BIN)

$(KEYINJECT_BIN): keyinject.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(KEYINJECT_BIN)

.PHONY: all clean
