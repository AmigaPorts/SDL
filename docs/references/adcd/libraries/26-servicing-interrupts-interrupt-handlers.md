---
title: 26 / Servicing Interrupts / Interrupt Handlers
manual: libraries
chapter: libraries
section: 26-servicing-interrupts-interrupt-handlers
functions: []
libraries: []
---

# 26 / Servicing Interrupts / Interrupt Handlers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As [described above](libraries/26-exec-interrupts-servicing-interrupts.md), an interrupt handler is a system routine that
exclusively handles all processing related to a particular 4703 interrupt.
There can only be one handler per 4703 interrupt.  Every interrupt handler
consists of an [Interrupt](libraries/26-servicing-interrupts-interrupt-data-structure.md) structure (as defined above) and a single
assembly code routine.  Optionally, a data structure pointer may also be
provided.  This is particularly useful for ROM-resident interrupt code.

An interrupt handler is passed control as if it were a subroutine of Exec.
Once the handler has finished its business, it must return to Exec by
executing an RTS (return from subroutine) instruction rather than an RTE
(return from exception) instruction. Interrupt handlers should be kept
very short to minimize service-time overhead and thus minimize the
possibilities of interrupt overruns. As [described above](libraries/26-servicing-interrupts-environment.md), an interrupt
handler has the normal scratch registers at its disposal.  In addition, A5
and A6 are free for use.  These registers are saved by Exec as part of the
interrupt initiation cycle.

For the sake of efficiency, Exec passes certain register parameters to the
handler (see the [list below](libraries/26-interrupt-handlers-interrupt-handler-register-usage.md)).  These register values may be utilized to
trim a few microseconds off the execution time of a handler.  All of the
following registers (D0/D1/A0/A1/A5/A6) may be used as scratch registers
by an interrupt handler, and need not be restored prior to returning.


```c
    Don't Make Assumptions About Registers.
    ---------------------------------------
    Interrupt servers have different register usage rules (see the
    "[Interrupt Servers](libraries/26-servicing-interrupts-interrupt-servers.md)" section).
```
 [Interrupt Handler Register Usage](libraries/26-interrupt-handlers-interrupt-handler-register-usage.md) 

