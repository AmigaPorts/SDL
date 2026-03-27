---
title: 8 / / Disk Subsystem Timing / DSKSYNC - Disk Input Synchronizer
manual: hardware
chapter: hardware
section: 8-disk-subsystem-timing-dsksync-disk-input-synchronizer
functions: []
libraries: []
---

# 8 / / Disk Subsystem Timing / DSKSYNC - Disk Input Synchronizer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The DSKSYNC register is used to synchronize the input stream.  This is
highly useful when reading disks. If the WORDSYNC bit is enabled in
 [ADKCON](hardware/8-timing-adkcon-and-adkconr-audio-and-disk-control-register.md) , no data is transferred until a word is found in the input stream
that matches the word in the DSKSYNC register.  On read, DMA will start
with the following word from the disk.  During disk read DMA, the
controller will resync every time the word match is found.  Typically the
DSKSYNC will be set to the magic MFM sync mark value, $4489.

In addition, the DSKSYNC bit in  [INTREQ](hardware/a-register-summary-intreq-intreqr.md)  is set when the input stream
matches the DSKSYNC register. The DSKSYNC bit in  [INTREQ](hardware/a-register-summary-intreq-intreqr.md)  is independent
of the WORDSYNC enable.

