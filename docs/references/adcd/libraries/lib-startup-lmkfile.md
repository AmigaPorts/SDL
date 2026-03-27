---
title: lib_startup/lmkfile
manual: libraries
chapter: libraries
section: lib-startup-lmkfile
functions: []
libraries: []
---

# lib_startup/lmkfile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ASM = casm

SNAME	= startup
AFILE  	= $(SNAME).asm
AFLAGS 	= -c s -i V36:include
OFILES	= Astartup.obj AWstartup.obj Rstartup.obj RWstartup.obj RXstartup.obj Qstartup.obj
.SUFFIXES:	.obj .c .h .asm .i

Qstartup.obj:	startup.asm
	$(ASM) -a startup.asm $(AFLAGS) -hastartup.i -o Astartup.obj

	$(ASM) -a startup.asm $(AFLAGS) -hawstartup.i -o AWstartup.obj

	$(ASM) -a startup.asm $(AFLAGS) -hrstartup.i -o Rstartup.obj

	$(ASM) -a startup.asm $(AFLAGS) -hrwstartup.i -o RWstartup.obj

	$(ASM) -a startup.asm $(AFLAGS) -hrxstartup.i -o RXstartup.obj

	$(ASM) -a startup.asm $(AFLAGS) -hqstartup.i -o Qstartup.obj

