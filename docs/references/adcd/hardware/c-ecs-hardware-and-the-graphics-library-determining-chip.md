---
title: C / ECS Hardware and the Graphics Library / Determining Chip Revisions
manual: hardware
chapter: hardware
section: c-ecs-hardware-and-the-graphics-library-determining-chip
functions: []
libraries: []
---

# C / ECS Hardware and the Graphics Library / Determining Chip Revisions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The V36 graphics.library field GfxBase->ChipRevBits0 contains bit
definitions to tell you whether ECS is currently installed and activated.
These bits are derived from the new or changed registers in the ECS chips.

The bit GFXF_HR_AGNUS indicates that enhanced HiRes Agnus is installed.
This is derived from the Agnus VPOSR register.  The VPOSR register is
defined as follows:

   VPOSR - Read vertical most significant bits (and frame flop)


    Bit   15 14 13 12 11 10 09 08  07 06 05 04 03  02 01 00
    Use  LOF I6 I5 I4 I3 I2 I1 I0 LOL -- -- -- -- v10 v9 V8
I0-I6 (bits 8-14) provide the chip identification. At present there are
four possible settings.  A value of 20 or 30 indicates that the enhanced
Hires Agnus is present.

   8361 (regular NTSC) or 8370 (fat NTSC) = 10 for NTSC Agnus
   8367 (regular PAL)  or 8371 (fat PAL)  = 00 for PAL Agnus
   8368 (hr)           or 8372 (fat-hr)   = 20 for PAL, 30 for NTSC

Similarly, the graphics.library flag GFXF_HR_DENISE is derived from the
Denise register DENISEID.  This is a new register which can have one of
two values.  The original Denise (8362) does not have this register, so
whatever value is left over on the bus from the last cycle will be there.
The enhanced HighRes Denise (8373) will return $FC in the lower 8 bits.
The upper 8 bits are reserved.

