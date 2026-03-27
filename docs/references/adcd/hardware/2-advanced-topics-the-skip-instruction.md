---
title: 2 / Advanced Topics / The SKIP Instruction
manual: hardware
chapter: hardware
section: 2-advanced-topics-the-skip-instruction
functions: []
libraries: []
---

# 2 / Advanced Topics / The SKIP Instruction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The SKIP instruction causes the Copper to skip the next instruction if the
video beam counters are equal to or greater than the value given in the
instruction.

The contents of the SKIP instruction's words are shown below. They are
identical to the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  instruction, except that bit 0 of the second
instruction word is a 1 to identify this as a SKIP instruction.


```c
          FIRST SKIP INSTRUCTION WORD (IR1)
          ---------------------------------
          Bit 0           Always set to 1.

          Bits 15 - 8      [Vertical position](hardware/2-the-wait-instruction-vertical-beam-position.md)  (called VP).

          Bits 7 - 1       [Horizontal position](hardware/2-the-wait-instruction-horizontal-beam-position.md)  (called HP).

                          Skip if the beam counter is equal to or
                          greater than these combined bits
                          (bits 15 through 1).


          SECOND SKIP INSTRUCTION WORD (IR2)
          ----------------------------------
          Bit 0           Always set to 1.

          Bit 15          The  [blitter-finished-disable bit](hardware/2-advanced-topics-using-the-copper-with-the-blitter.md) .
                          (See "Using the Copper with the Blitter"
```
			  below.)



```c
          Bits 14 - 8     Vertical position compare enable bits
                          (called VE).

          Bits 7 - 1      Horizontal position compare enable bits
                          (called HE).
```
The notes about  [horizontal](hardware/2-the-wait-instruction-horizontal-beam-position.md)  and  [vertical beam position](hardware/2-the-wait-instruction-vertical-beam-position.md)  found in the
discussion of the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  instruction apply also to the SKIP instruction.

The following example SKIP instruction skips the instruction following it
if VP ( [vertical beam position](hardware/2-the-wait-instruction-vertical-beam-position.md) ) is greater than or equal to 100 ($64).


```c
        DC.W    $6401,$FF01     ;If VP >= 100,
                                ;  skip next instruction (ignore HP)
```
