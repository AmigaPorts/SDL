---
title: 7 / Interrupts / Interrupt Control Registers
manual: hardware
chapter: hardware
section: 7-interrupts-interrupt-control-registers
functions: []
libraries: []
---

# 7 / Interrupts / Interrupt Control Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two interrupt registers, interrupt enable (mask) and interrupt
request (status). Each register has both a read and a write address.  The
names of the interrupt addresses are:


```c
    [INTENA](hardware/a-register-summary-intena-intenar.md) 
      Interrupt0 enable (mask) - write only. Sets or clears specific
      bits of INTENA.

    [INTENAR](hardware/a-register-summary-intena-intenar.md) 
      Interrupt enable (mask) read - read only. Reads contents of INTENA.

    [INTREQ](hardware/a-register-summary-intreq-intreqr.md) 
      Interrupt request (status) - write only. Used by the processor
      to force a certain kind of interrupt to be processed (software
      interrupt). Also used to clear interrupt request flags once the
      interrupt process is completed.

    [INTREQR](hardware/a-register-summary-intreq-intreqr.md) 
      Interrupt request (status) read - read only. Contains the bits
      that define which items are requesting interrupt service.

      The bit positions in the interrupt request register correspond
      directly to those same positions in the interrupt enable
      register. The only difference between the read-only and the
      write-only addresses shown above is that  [bit 15](hardware/7-setting-and-clearing-bits-set-and-clear.md)  has no meaning
      in the read-only addresses.
```
