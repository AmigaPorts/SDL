---
title: 8 / Floppy Disk Controller / Disk Interrupts
manual: hardware
chapter: hardware
section: 8-floppy-disk-controller-disk-interrupts
functions: []
libraries: []
---

# 8 / Floppy Disk Controller / Disk Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The disk controller can issue three kinds of interrupts:

   *   [DSKSYNC](hardware/7-setting-and-clearing-bits-disk-interrupt.md)  (level 5,  [INTREQ](hardware/a-register-summary-intreq-intreqr.md)  bit 12) -- input stream matches the
                                             DSKSYNC register.
   *   [DSKBLK](hardware/7-setting-and-clearing-bits-disk-interrupt.md)  (level 1,  [INTREQ](hardware/a-register-summary-intreq-intreqr.md)  bit 1) -- disk DMA has completed.
   *   [INDEX](hardware/f-8520-complex-interface-adapters-port-signal-assignments.md)  (level 6, 8520 Flag pin) -- index sensor triggered.

Interrupts are explained further in the section
 [Length, Direction, DMA Enable](hardware/8-disk-subsystem-timing-dsklen-length-direction-dma-enable.md) .

See Chapter 7, "System Control Hardware," for more information about
  [interrupts](hardware/7-system-control-hardware-interrupts.md) .

See  [Appendix F](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md)  for more information on the 8520.

