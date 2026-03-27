---
title: 2 / Advanced Topics / Copper Loops and Branches and Comparison Enable
manual: hardware
chapter: hardware
section: 2-advanced-topics-copper-loops-and-branches-and-comparison
functions: []
libraries: []
---

# 2 / Advanced Topics / Copper Loops and Branches and Comparison Enable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can change the value in the  [location registers](hardware/2-using-the-copper-registers-location-registers.md)  at any time and use
this value to construct loops in the instruction list. Before the next
 [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  time, however, the  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  registers must be
repointed to the beginning of the appropriate Copper list. The value in
the  [COP1LC](hardware/2-using-the-copper-registers-location-registers.md)  location registers will be restored to the Copper's program
counter at the start of the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  period.

Bits 14-1 of instruction word 2 in the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  and  [SKIP](hardware/2-advanced-topics-the-skip-instruction.md) . instructions
specify which bits of the horizontal and vertical position are to be used
for the beam counter comparison. The position in instruction word 1 and
the compare enable bits in instruction word 2 are tested against the
actual beam counters before any further action is taken. A position bit in
instruction word 1 is used in comparing the positions with the actual beam
counters if and only if the corresponding enable bit in instruction word 2
is set to 1. If the corresponding enable bit is 0, the comparison is
always true. For instance, if you care only about the value in the last
four bits of the vertical position, you set only the last four compare
enable bits, bits (11-8) in instruction word 2.

Not all of the bits in the beam counter may be masked.  If you look at the
description of the IR2 (second instruction word) you will notice that bit
15 is the  [blitter-finished-disable bit](hardware/2-advanced-topics-using-the-copper-with-the-blitter.md) . This bit is not part of the beam
counter comparison mask, it has its own meaning in the Copper  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) 
instruction. Thus, you can not mask the most significant bit in  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  or
 [SKIP](hardware/2-advanced-topics-the-skip-instruction.md)  instructions. In most situations this limitation does not come into
play, however, the following example shows how to deal with it.

