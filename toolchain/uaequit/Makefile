# Build UAEQuit for AmigaOS
CC = ../scripts/m68k-amigaos-gcc
CFLAGS = -O2 -noixemul -m68000 -Wall
# Use UAEQUIT_BIN to avoid collision with parent Makefile's TARGET
UAEQUIT_BIN = UAEQuit

all: $(UAEQUIT_BIN)

$(UAEQUIT_BIN): uaequit.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(UAEQUIT_BIN)
