---
title: C / ECS Hardware and the Graphics Library / Other ECS Modifications
manual: hardware
chapter: hardware
section: c-ecs-hardware-and-the-graphics-library-other-ecs
functions: []
libraries: []
---

# C / ECS Hardware and the Graphics Library / Other ECS Modifications

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The preceding sections cover most of the ECS registers appearing in the
ECS register map.  This section briefly describes the remaining
modifications to the Enhanced Chip Set registers.

The following registers now have two additional bits for addressing larger
segments of memory, when the Enhanced Chip Set is present:

   DSKPTH    020   W   A      Disk pointer
```c
                                  (high 5 bits, was 3 bits)
```
   BLTxPTH   050   W   A      Blitter pointer to x
```c
                                  (high 5 bits, was 3 bits)
```
   COP1LCH   080   W   A      Coprocessor 1st location
```c
                                  (high 5 bits,was 3 bits)
```
   COP2LCH   084   W   A      Coprocessor 2nd location
```c
                                  (high 5 bits,was 3 bits)
```
   AUDxLCH   0A0   W   A      Audio channel x location

```c
                                  (high 5 bits was 3 bits)
```
The Strobe Long Line register (STRLONG) can be disabled if the Disable
Long Line (LOLDIS) bit is set in the BEAMCON0 register.

   STRLONG   03E   S   D      Strobe for identification of long horiz line

See the Multi-Sync and Bi-Sync Monitors section in this appendix for the
bit descriptions in BEAMCON0.

Bit 7 (DOFF) of the BLTCON1 register, when set, disables the output of the
Blitter hardware on channel D.

   BLTCON1   042   W   A      Blitter control register 1

This allows inputs to channels A, B and C and certain address modification
if necessary, without the Blitter outputting over channel D.

The BLTCON0L register writes the low bits of BLTCON0, thereby expediting
the set up of some blits and generally speeding up the software, since the
upper bits are often the same.

   BLTCON0L  05A   W   A      Blitter control 0, lower 8 bits (minterms)

