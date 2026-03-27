---
title: Devices/Dev_examples/Epsonx_Makefile
manual: devices
chapter: devices
section: devices-dev-examples-epsonx-makefile
functions: []
libraries: []
---

# Devices/Dev_examples/Epsonx_Makefile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

LC = lc:lc
ASM = lc:asm
CFLAGS = -iINCLUDE: -b0 -d0 -v
ASMFLAGS = -iINCLUDE:
LINK = lc:blink
LIB = lib:lc.lib+lib:amiga.lib
OBJ = printertag.o+init.o+data.o+dospecial.o+render.o+transfer.o+density.o
TARGET = EpsonX


```c
        @$(LC) $(CFLAGS) $*
```
$(TARGET): printertag.o init.o data.o dospecial.o render.o density.o transfer.o

```c
        @$(LINK) <WITH <
        FROM $(OBJ)
        TO $(TARGET)
        LIBRARY $(LIB)
        NODEBUG SC SD VERBOSE MAP $(TARGET).map H
        <
```
init.o: init.asm

```c
        @$(ASM) $(ASMFLAGS) init.asm
```
printertag.o: printertag.asm epsonX_rev.i

```c
        @$(ASM) $(ASMFLAGS) printertag.asm
```
transfer.o: transfer.asm

```c
        @$(ASM) $(ASMFLAGS) transfer.asm
```
dospecial.o: dospecial.c

data.o: data.c

density.o: density.c

render.o: render.c

