---
title: A Register Summary / DSKDAT, DSKDATR
manual: hardware
chapter: hardware
section: a-register-summary-dskdat-dskdatr
functions: []
libraries: []
---

# A Register Summary / DSKDAT, DSKDATR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKDAT     026      W       P     Disk DMA data write
DSKDATR    008      ER      P     Disk DMA data read (early read dummy

```c
                                      address)

                 This register is the disk DMA data buffer. It
                 contains two bytes of data that are either sent
                 (written) to or received (read) from the disk.
                 The write mode is enabled by bit 14 of the LENGTH
                 register. The DMA controller automatically
                 transfers data to or from this register and RAM,
                 and when the DMA data is finished (length=0) it
                 causes a disk block interrupt. See interrupts below.
```
