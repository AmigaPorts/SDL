---
title: 3 / / Allocating Memory for Bitplanes / NTSC Example of Bitplane Size
manual: hardware
chapter: hardware
section: 3-allocating-memory-for-bitplanes-ntsc-example-of-bitplane
functions: []
libraries: []
---

# 3 / / Allocating Memory for Bitplanes / NTSC Example of Bitplane Size

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For example, using a normal, NTSC, low resolution, non-interlaced display
with 320 pixels across each display line and a total of 200 display lines,
each line of the bitplane requires 40 bytes (320 bits divided by 8 bits
per byte = 40). Multiply the 200 lines times 40 bytes per line to get
8,000 bytes per bitplane as given above.

A low resolution, non-interlaced playfield made up of two bitplanes
requires 16,000 bytes of memory area. The memory for each bitplane must be
continuous, so you need to have two 8,000-byte blocks of available memory.
Figure 3-7 shows an 8,000-byte memory area organized as 200 lines of 40
bytes each, providing 1 bit for each pixel position in the display plane.

  _______________________________         _______________________________
 |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ----> |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|

         Memory Location N                     Memory Location N+38
  _______________________________         _______________________________
 |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ----> |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|

       Memory Location N+40          |         Memory Location N+78
                                     |
                                     |
                                    \|/
  _______________________________         _______________________________
 |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ----> |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|



      Memory Location N+7960                  Memory Location N+7998


          Figure 3-7: Memory Organization for a Basic Bitplane
Access to bitplanes in memory is provided by two address registers,
 [BPLxPTH and BPLxPTL](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) , for each bitplane (12 registers in all). The "x"
position in the name holds the bitplane number; for example BPL1PTH and
BPL1PTL hold the starting address of PLANE 1. Pairs of registers with
names ending in PTH and PTL contain 19-bit addresses. 68000 programmers
may treat these as one 32-bit address and write to them as one long word.
You write to the high order word, which is the register whose name ends in
"PTH."

The example below shows how to set the bitplane pointers. Assuming two
bitplanes, one at $21000 and the other at $25000, the processor sets
BPL1PT to $21000 and BPL2PT to $25000. Note that this is usually the
Copper's task.

;
; Since the bitplane pointer registers are mapped as full 680x0 long-word
; data, we can store the addresses with a 32-bit move...
;
   LEA     CUSTOM,a0              ; Get base address of custom hardware...
   MOVE.L  $21000,BPL1PTH(a0)     ; Write bitplane 1 pointer
   MOVE.L  $25000,BPL2PTH(a0)     ; Write bitplane 2 pointer


Note that the memory requirements given here are for the playfield only.
You may need to allocate additional memory for other parts of the display
--  [sprites](hardware/4-forming-a-sprite-building-the-data-structure.md) ,  [audio](hardware/5-forming-and-playing-a-sound-creating-the-waveform-data.md) ,  [animation](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  -- and for your application programs.
Memory allocation for other parts of the display is discussed in the
chapters describing those topics.

