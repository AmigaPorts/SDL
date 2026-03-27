---
title: A Register Summary / DSKLEN
manual: hardware
chapter: hardware
section: a-register-summary-dsklen
functions: []
libraries: []
---

# A Register Summary / DSKLEN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
DSKLEN     024      W       P     Disk length


```c
                 This register contains the length (number of words)
                 of disk DMA data. It also contains two control
                 bits, a DMA enable bit, and a DMA direction
                 (read/write) bit.

                 BIT#  FUNCTION      DESCRIPTION
                 ----  -----------   --------------------------------
                 15    DMAEN         Disk DMA enable
                 14    WRITE         Disk write (RAM to disk) if 1
                 13-0  LENGTH        Length (# of words) of DMA data.
```
