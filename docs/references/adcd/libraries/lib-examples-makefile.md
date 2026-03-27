---
title: lib_examples/makefile
manual: libraries
chapter: libraries
section: lib-examples-makefile
functions: []
libraries: []
---

# lib_examples/makefile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

# MAKEFILE for sample.library, sample.lib, and asm library test program
# define linker command
LINKER = Blink

all: sample.library sample.lib alibtest

sample.library: sample.library.o
	$(LINKER) from sample.library.o to sample.library LIB lib:amiga.lib

sample.lib: sample_stubs.o sample_lvos.o
	JOIN sample_stubs.o sample_lvos.o AS sample.lib

alibtest: alibtest.o
  $(LINKER) from astartup.obj,alibtest.o to alibtest LIB lib:amiga.lib,sample.lib

# assembler command line for Adapt assembler
.asm.o:
	HX68 -A $*.asm -iINCLUDE: -o$*.o

