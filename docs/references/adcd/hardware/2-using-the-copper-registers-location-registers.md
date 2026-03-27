---
title: 2 / Using the Copper Registers / Location Registers
manual: hardware
chapter: hardware
section: 2-using-the-copper-registers-location-registers
functions: []
libraries: []
---

# 2 / Using the Copper Registers / Location Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Copper has two sets of location registers:


          COP1LCH High 3 bits of first Copper list address.
          COP1LCL Low 16 bits of first Copper list address.
          COP2LCH High 3 bits of second Copper list address.
          COP2LCL Low 16 bits of second Copper list address.
In accessing the hardware directly, you often have to write to a pair of
registers that contains the address of some data. The register with the
lower address always has a name ending in "H" and contains the most
significant data, or high 3 bits of the address. The register with the
higher address has a name ending in "L" and contains the least significant
data, or low 15 bits of the address. Therefore, you write the 18-bit
address by moving one long word to the register whose name ends in "H."
This is because when you write long words with the 680x0, the most
significant word goes in the lower addressed word.

In the case of the Copper location registers, you write the address to
COP1LCH. In the following text, for simplicity, these addresses are
referred to as COP1LC or COP2LC.

The Copper location registers contain the two indirect jump addresses used
by the Copper. The Copper fetches its instructions by using its program
counter and increments the program counter after each fetch. When a
 [jump address strobe](hardware/2-using-the-copper-registers-jump-strobe-address.md)  is written, the corresponding location register is
loaded into the Copper program counter. This causes the Copper to jump to
a new location, from which its next instruction will be fetched.
Instruction fetch continues sequentially until the Copper is interrupted
by another  [jump address strobe](hardware/2-using-the-copper-registers-jump-strobe-address.md) .

   About Copper restart.
   ---------------------
   At the start of each  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval, COP1LC is
   automatically used to start the program counter.  That is, no matter
   what the Copper is doing, when the end of  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  occurs,
   the Copper is automatically forced to restart its operations at the
   address contained in COP1LC.

