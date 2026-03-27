---
title: 2 / Using the Copper Registers / Control Register
manual: hardware
chapter: hardware
section: 2-using-the-copper-registers-control-register
functions: []
libraries: []
---

# 2 / Using the Copper Registers / Control Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Copper can access some special-purpose registers all of the time, some
registers only when a special control bit is set to a 1, and some registers
not at all.  The registers that the Copper can always affect are numbered
$80 through $FF inclusive.  (See  [Appendix B](hardware/amiga-hardware-reference-manual-b-register-summary-address.md)  for a list of registers in
address order.) Those it cannot affect at all are numbered $00 to $3E
inclusive.  The Copper control register is within this group ($00 to $3E).
The rest of the registers, from $40 to $7E, are protected by a bit in the
Copper control register.

In the Copper control register, called COPCON, only bit 1 is currently in
use by the system. This bit, called CDANG (for Copper Danger Bit) protects
all registers numbered between $40 and $7E inclusive. This range includes
the blitter control registers. When CDANG is 0, these registers cannot be
written by the Copper. When CDANG is 1, these registers can be written by
the Copper. Preventing the Copper from accessing the blitter control
registers prevents a runaway Copper (caused by a poorly formed instruction
list) from accidentally affecting system memory.

   Warning:
   --------
   Keep in mind that the CDANG bit is cleared after a reset.

