---
title: 8 / / Timing / DSKBYTR - Disk Data Byte and Status Read (read-only)
manual: hardware
chapter: hardware
section: 8-timing-dskbytr-disk-data-byte-and-status-read-read-only
functions: []
libraries: []
---

# 8 / / Timing / DSKBYTR - Disk Data Byte and Status Read (read-only)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This register is the disk-microprocessor data buffer. In read mode, data
from the disk is placed into this register one byte at a time.  As each
byte is received into the register, the DSKBYT bit is set true. DSKBYT is
cleared when the DSKBYTR register is read.

DSKBYTR may be used to synchronize the processor to the disk rotation
before issuing a read or write under DMA control.



```c
                 Table 8-7: DSKBYTR Register

     Bit
     Number  Name       Function
     ------  ----       --------
     15      DSKBYT     When set, indicates that this register contains
                        a valid byte of data (reset by reading this
                        register).

     14      DMAON      Indicates when DMA is actually enabled.  All the
                        various DMA bits must be true.  This means the
                        DMAEN bit in  [DSKLEN](hardware/8-disk-subsystem-timing-dsklen-length-direction-dma-enable.md) , and the DSKEN & DMAEN bits
                        in  [DMACON](hardware/7-system-control-hardware-dma-control.md) .

     13      DISKWRITE  The disk write bit (in  [DSKLEN](hardware/8-disk-subsystem-timing-dsklen-length-direction-dma-enable.md) ) is enabled.

     12      WORDEQUAL  Indicates the  [DSKSYNC](hardware/8-disk-subsystem-timing-dsksync-disk-input-synchronizer.md)  register equals the disk
                        input stream.  This bit is true only while the
                        input stream matches the sync register (as
                        little as two microseconds).

     11-8               Currently unused; don't depend on read value.

     7-0     DATA       Disk byte data.
```
