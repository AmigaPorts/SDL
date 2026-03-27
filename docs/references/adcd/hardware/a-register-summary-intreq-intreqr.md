---
title: A Register Summary / INTREQ, INTREQR
manual: hardware
chapter: hardware
section: a-register-summary-intreq-intreqr
functions: []
libraries: []
---

# A Register Summary / INTREQ, INTREQR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
INTREQ     09C      W       P   Interrupt request bits (clear or set)
INTREQR    01E      R       P   Interrupt request bits (read)


```c
                 This register contains interrupt request bits (or
                 flags).  These bits may be polled by the processor;
                 if enabled by the bits listed in the above register,
                 they may cause processor interrupts.  Both a set and
                 clear operation are required to load arbitrary data
                 into this register.  These status bits are not
                 automatically reset when the interrupt is serviced,
                 and must be reset when desired by writing to this
                 address.  The bit assignments are identical to the
                  [enable register](hardware/a-register-summary-intena-intenar.md) .
```
