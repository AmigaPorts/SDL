---
title: 7 / / Setting and Clearing Bits / Disk Interrupt
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-disk-interrupt
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Disk Interrupt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bits 12 and 1 of the  [interrupt registers](hardware/7-interrupts-interrupt-control-registers.md)  are assigned to disk interrupts.

Bit 12, DSKSYN, indicates that the  [sync register](hardware/8-disk-subsystem-timing-dsksync-disk-input-synchronizer.md)  matches disk data. This
bit generates a  [level 5 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

Bit 1, DSKBLK, indicates "disk block finished." It is used to indicate
that the specified disk DMA task that you have requested has been
completed. This bit generates a  [level 1 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

More information about disk data transfer and  [interrupts](hardware/8-floppy-disk-controller-disk-interrupts.md)  may be found
in Chapter 8, "Interface Hardware."

