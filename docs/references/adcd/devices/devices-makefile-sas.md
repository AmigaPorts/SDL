---
title: Devices/Makefile.SAS
manual: devices
chapter: devices
section: devices-makefile-sas
functions: []
libraries: []
---

# Devices/Makefile.SAS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#MYLIBS= LIB:debug.lib

CC = lc
ASM = asm

CFLAGS = -cfistq -v -j73 -iINCLUDE:
AFLAGS = -iINCLUDE:
LFLAGS = SC BATCH ND

M      = modules/
A      = apps/

# Our iffparse support object modules to link with
IFFO      = $(M)parse.o $(M)Hook.o
ILBMRO    = $(M)ilbmr.o $(M)unpacker.o
ILBMSO    = $(M)getdisplay.o $(M)screen.o
ILBMLO    = $(M)loadilbm.o $(M)getbitmap.o
ILBMWO    = $(M)saveilbm.o $(M)ilbmw.o $(M)packer.o
ILBMO     = $(IFFO) $(ILBMRO) $(ILBMLO) $(ILBMSO) $(ILBMWO)
EXTRAO    = $(M)copychunks.o $(M)screendump.o $(M)bmprintc.o


# Our iffparse applications
APP1   = $(A)ILBMDemo/ILBMDemo
APP2   = $(A)ILBMLoad/ILBMLoad
APP3   = $(A)Play8SVX/Play8SVX
APP4   = $(A)ILBMtoC/ILBMtoC
APP5   = $(A)ILBMtoRaw/ILBMtoRaw
APP6   = $(A)ScreenSave/ScreenSave
APP7   = $(A)RawtoILBM/RawtoILBM
APP8   = $(A)24bitDemo/24bitDemo


# The object modules needed by each application example
APP1O  = $(APP1).o $(ILBMO) $(M)screendump.o $(M)copychunks.o
APP2O  = $(APP2).o $(IFFO) $(ILBMRO) $(ILBMLO) $(ILBMSO)
APP3O  = $(APP3).o $(IFFO)
APP4O  = $(APP4).o $(IFFO) $(ILBMRO) $(ILBMLO) $(M)bmprintc.o
APP5O  = $(APP5).o $(IFFO) $(ILBMRO) $(ILBMLO)
APP6O  = $(APP6).o $(IFFO) $(ILBMWO)
APP7O  = $(APP7).o $(IFFO) $(ILBMWO)
APP8O  = $(APP8).o $(IFFO) $(ILBMRO) $(ILBMLO) $(ILBMSO) $(ILBMWO)

.SUFFIXES:
.SUFFIXES:	.o .c .h .asm .i

# Make all of the applications
all:	$(APP1) $(APP2) $(APP3) $(APP4) $(APP5) $(APP6) $(APP7) $(APP8)

# Linkage for each application

$(APP1): $(APP1O)
  blink <WITH <
FROM lib:c.o $(APP1O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP1) $(LFLAGS)
<

$(APP2): $(APP2O)
  blink <WITH <
FROM lib:c.o $(APP2O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP2) $(LFLAGS)
<

$(APP3): $(APP3O)
  blink <WITH <
FROM lib:c.o $(APP3O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP3) $(LFLAGS)
<

$(APP4): $(APP4O)
  blink <WITH <
FROM lib:c.o $(APP4O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP4) $(LFLAGS)
<

$(APP5): $(APP5O)
  blink <WITH <
FROM lib:c.o $(APP5O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP5) $(LFLAGS)
<

$(APP6): $(APP6O)
  blink <WITH <
FROM lib:c.o $(APP6O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP6) $(LFLAGS)
<

$(APP7): $(APP7O)
  blink <WITH <
FROM lib:c.o $(APP7O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP7) $(LFLAGS)
<

$(APP8): $(APP8O)
  blink <WITH <
FROM lib:c.o $(APP8O)
LIBRARY lib:lc.lib LIB:amiga.lib $(MYLIBS)
TO $(APP8) $(LFLAGS)
<

.c.o:
	$(CC) $(CFLAGS) $*.c

.asm.o:
	$(ASM) $(AFLAGS) $*.asm

