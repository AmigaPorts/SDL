---
title: Devices/Dev_examples/HP_Laserjet_Makefile
manual: devices
chapter: devices
section: devices-dev-examples-hp-laserjet-makefile
functions: []
libraries: []
---

# Devices/Dev_examples/HP_Laserjet_Makefile

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

LC = lc:lc
ASM = lc:asm
CFLAGS = -iINCLUDE: -b0 -d0 -v
ASMFLAGS = -iINCLUDE:
LINK = lc:blink
LIB = lib:amiga.lib+lib:lc.lib
OBJ = printertag.o+init.o+data.o+dospecial.o+render.o+transfer.o+density.o
TARGET = hp_laserjet


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
printertag.o: printertag.asm hp_rev.i

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

