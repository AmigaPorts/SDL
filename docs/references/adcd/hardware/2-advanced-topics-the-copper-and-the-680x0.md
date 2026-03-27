---
title: 2 / Advanced Topics / The Copper and the 680x0
manual: hardware
chapter: hardware
section: 2-advanced-topics-the-copper-and-the-680x0
functions: []
libraries: []
---

# 2 / Advanced Topics / The Copper and the 680x0

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

On those occasions when the Copper's instructions do not suffice, you can
interrupt the 680x0 and use its instruction set instead. The 680x0 can
poll for interrupt flags set in the  [INTREQ](hardware/7-interrupts-interrupt-control-registers.md)  register by various devices.
To interrupt the 680x0, use the Copper  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  instruction to store a 1
into the following bits of  [INTREQ](hardware/7-interrupts-interrupt-control-registers.md) :




```c
               Table 2-1: Interrupting the 680x0


     Bit Number      Name      Function
     ----------      ----      --------
        15          [SET/CLR](hardware/7-setting-and-clearing-bits-set-and-clear.md)    Set/Clear control bit.  Determines
                               if bits written with a 1 get set
                               or cleared.

         4           [COPEN](hardware/2-starting-and-stopping-the-copper-stopping-the-copper.md)     Coprocessor interrupting 680x0.
```
See Chapter 7, "System Control Hardware," for more information about
 [interrupts](hardware/7-system-control-hardware-interrupts.md) .

