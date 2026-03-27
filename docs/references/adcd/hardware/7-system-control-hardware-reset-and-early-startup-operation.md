---
title: 7 System Control Hardware / Reset and Early Startup Operation
manual: hardware
chapter: hardware
section: 7-system-control-hardware-reset-and-early-startup-operation
functions: []
libraries: []
---

# 7 System Control Hardware / Reset and Early Startup Operation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the Amiga is turned on or externally reset, the memory map is in a
special state.  An additional copy of the system ROM responds starting at
memory location $00000000.  The system RAM that would normally be located
at this address is not available.  On some Amiga models, portions of the
RAM still respond.  On other models, no RAM responds.  Software must
assume that memory is not available.  The OVL bit in one of the 8520 Chips
disables the overlay (See  [Appendix F](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  for the bit location).

The Amiga System ROM contains an ID code as the first word.  The value of
the ID code may change in the future.  The second word of the ROM contains
a JMP instruction ($4ef9).  The next two words are used as the initial
program counter by the 680x0 processor.

The 68000 RESET instruction works much like external reset or power on.
All memory and AUTOCONFIG(TM) cards disappear, and the ROM image appears
at location $00000000.  The difference is that the CPU continues execution
with the next instruction.  Since RAM may not be available, special care
is needed to write reboot code that will reliably reboot all Amiga models.


```c
     [coldreboot.asm](hardware/hard-examples-coldreboot-asm.md) 
```
