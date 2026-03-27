---
title: Devices/Makefile.Manx
manual: devices
chapter: devices
section: devices-makefile-manx
functions: []
libraries: []
---

# Devices/Makefile.Manx

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#MYLIBS= LIB:debug.lib

CC = cc
ASM = as

CFLAGS = -IWork:manxinclude
AFLAGS =
LFLAGS =

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
	ln -o $(APP1) $(LFLAGS) $(APP1O) -lc +l amiga.lib

$(APP2): $(APP2O)
	ln -o $(APP2) $(LFLAGS) $(APP2O) -lc +l amiga.lib

$(APP3): $(APP3O)
	ln -o $(APP3) $(LFLAGS) $(APP3O) -lc +l amiga.lib

$(APP4): $(APP4O)
	ln -o $(APP4) $(LFLAGS) $(APP4O) -lc +l amiga.lib

$(APP5): $(APP5O)
	ln -o $(APP5) $(LFLAGS) $(APP5O) -lc +l amiga.lib

$(APP6): $(APP6O)
	ln -o $(APP6) $(LFLAGS) $(APP6O) -lc +l amiga.lib

$(APP7): $(APP7O)
	ln -o $(APP7) $(LFLAGS) $(APP7O) -lc +l amiga.lib

$(APP8): $(APP8O)
	ln -o $(APP8) $(LFLAGS) $(APP8O) -lc +l amiga.lib


.c.o:
	cc $(CFLAGS) -o $*.o $*.c

.asm.o:
	as $(AFLAGS) -o $*.o $*.asm

