---
title: 2 Coprocessor Hardware / The WAIT Instruction
manual: hardware
chapter: hardware
section: 2-coprocessor-hardware-the-wait-instruction
functions: []
libraries: []
---

# 2 Coprocessor Hardware / The WAIT Instruction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The WAIT instruction causes the Copper to wait until the video beam
counters are equal to (or greater than) the coordinates specified in the
instruction. While waiting, the Copper is off the bus and not using memory
cycles.

The first instruction word contains the vertical and horizontal
coordinates of the beam position. The second word contains enable bits
that are used to form a "mask" that tells the system which bits of the
beam position to use in making the comparison.




```c
     FIRST WAIT INSTRUCTION WORD (IR1)
     ---------------------------------
     Bit 0           Always set to 1.

     Bits 15 - 8      [Vertical beam position](hardware/2-the-wait-instruction-vertical-beam-position.md)  (called VP).

     Bits 7 - 1       [Horizontal beam position](hardware/2-the-wait-instruction-horizontal-beam-position.md)  (called HP).


     SECOND WAIT INSTRUCTION WORD (IR2)
     ----------------------------------
     Bit 0           Always set to 0.

     Bit 15          The  [blitter-finished-disable bit](hardware/2-advanced-topics-using-the-copper-with-the-blitter.md) .  Normally, this
                     bit is a 1. (See the "Advanced Topics" section below.)

     Bits 14 - 8     Vertical position compare enable bits (called VE).

     Bits 7 - 1      Horizontal position compare enable bits (called HE).
```
The following example WAIT instruction waits for scan line 150 ($96) with
the horizontal position masked off.


```c
        DC.W    $9601,$FF00     ;Wait for line 150,
                                ;   ignore horizontal counters.
```
The following example WAIT instruction waits for scan line 255 and
horizontal position 254. This event will never occur, so the Copper stops
until the next  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval begins.


```c
        DC.W    $FFFF,$FFFE     ;Wait for line 255,
                                ;   H = 254 (ends Copper list).
```
To understand why position VP=$FF HP=$FE will never occur, you must look
at the comparison operation of the Copper and the size restrictions of the
position information. Line number 255 is a valid line to wait for, in fact
it is the maximum value that will fit into this field. Since 255 is the
maximum number, the next line will wrap to zero (line 256 will appear as a
zero in the comparison.) The line number will never be greater than $FF.
The horizontal position has a maximum value of $E2.  This means that the
largest number that will ever appear in the comparison is $FFE2. When
waiting for $FFFE, the line $FF will be reached, but the horizontal
position $FE will never happen. Thus, the position will never reach $FFFE.

You may be tempted to wait for horizontal position $FE (since it will
never happen), and put a smaller number into the vertical position field.
This will not lead to the desired result. The comparison operation is
waiting for the beam position to become greater than or equal to the
entered position. If the vertical position is not $FF, then as soon as the
line number becomes higher than the entered number, the comparison will
evaluate to true and the wait will end.

The following notes on horizontal and vertical beam position apply to both
the WAIT instruction and to the  [SKIP](hardware/2-advanced-topics-the-skip-instruction.md) . instruction. The  [SKIP](hardware/2-advanced-topics-the-skip-instruction.md)  instruction
is described below in the  [Advanced Topics](hardware/2-coprocessor-hardware-advanced-topics.md)  section.

 [Horizontal Beam Position](hardware/2-the-wait-instruction-horizontal-beam-position.md) 
 [Vertical Beam Position](hardware/2-the-wait-instruction-vertical-beam-position.md) 
 [The Comparison Enable Bits](hardware/2-the-wait-instruction-the-comparison-enable-bits.md) 

