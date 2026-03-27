# IX-1/lmkfile


ASM	= asm
AFLAGS	= -iinclude:
CC	= sc
CFLAGS	= NMINC STRMERGE
LN	= slink

LIBS = LIB:sc.lib LIB:amiga.lib

.c.o:
		$(CC) $(CFLAGS) $*.c

.asm.o:
		$(ASM) $(AFLAGS) $*.asm

4play:	4play.o read34.o
		$(LN) FROM LIB:c.o,4play.o,read34.o TO 4play LIBRARY $(LIBS)

