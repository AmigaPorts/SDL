---
title: A Register Summary / DSKBYTR
manual: hardware
chapter: hardware
section: a-register-summary-dskbytr
functions: []
libraries: []
---

# A Register Summary / DSKBYTR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKBYTR    01A      R       P     Disk data byte and status read


```c
                 This register is the disk-microprocessor data
                 buffer.  Data from the disk (in read mode) is
                 loaded into this register one byte at a time, and
                 bit 15 (DSKBYT) is set true.

                 BIT#
                 ----  ---------  --------------------------------
                 15    DSKBYT     Disk byte ready (reset on read)
                 14    DMAON      Mirror of bit 15 (DMAEN) in  [DSKLEN](hardware/a-register-summary-dsklen.md) ,
                                  ANDed with Bit09 (DMAEN) in  [DMACON](hardware/a-register-summary-dmacon-dmaconr.md) 
                 13    DISKWRITE  Mirror of bit 14 (WRITE) in  [DSKLEN](hardware/a-register-summary-dsklen.md) 
                 12    WORDEQUAL  This bit true only while the
                                   [DSKSYNC](hardware/a-register-summary-dsksync.md)  register equals the data
                                  from disk.
                 11-08  X         Not used
                 07-00 DATA       Disk byte data
```
