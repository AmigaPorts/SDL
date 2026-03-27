---
title: IX-1/lmkfile
manual: amiga-mail
chapter: amiga-mail
section: ix-1-lmkfile
functions: []
libraries: []
---

# IX-1/lmkfile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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

