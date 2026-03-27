---
title: 7 System Control Hardware / DMA Control
manual: hardware
chapter: hardware
section: 7-system-control-hardware-dma-control
functions: []
libraries: []
---

# 7 System Control Hardware / DMA Control

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Many different direct memory access (DMA) functions occur during system
operation. There is a read address as well as a write address to the DMA
control register so you can tell which DMA channels are enabled.

The address names for the DMA registers are as follows:

   DMACONR - Direct Memory Access Control - read-only.
   DMACON  - Direct Memory Access Control - write-only.

The contents of this register are shown in Table 7-6 (bit on if enabled).


   Bit
  Number     Name      Function
  ------     ----      --------


```c
    15      SET/CLR    The set/reset control bit. See
                        [description of bit 15](hardware/7-setting-and-clearing-bits-set-and-clear.md) .


    14      [BBUSY](hardware/6-blitter-hardware-blitter-done-flag.md)      Blitter busy status - read-only

    13      [BZERO](hardware/6-blitter-hardware-zero-flag.md)      Blitter zero status - read-only. Remains 1 if,
                       during a blitter operation, the blitter output
                       was always zero.

    12, 11             Unassigned

    10      [BLTPRI](hardware/6-blitter-hardware-blitter-operations-and-system-dma.md)     Blitter priority.  Also known as "blitter-nasty."
                       When this is a 1, the blitter has full (instead
                       of partial) priority over the 680x0.

    9       DMAEN      DMA enable.  This is a master DMA enable bit.
                       It enables the DMA for all of the channels at
                       bits 8-0.

    8       [BPLEN](hardware/3-basic-playfield-displaying-and-redisplaying-the-playfield.md)      Bitplane DMA enable

    7       [COPEN](hardware/2-starting-and-stopping-the-copper-stopping-the-copper.md)      Coprocessor DMA enable

    6       BLTEN      Blitter DMA enable

    5       SPREN      Sprite DMA enable

    4       DSKEN       [Disk DMA enable](hardware/8-disk-subsystem-timing-dsklen-length-direction-dma-enable.md) 

    3-0     [AUDxEN](hardware/5-forming-and-playing-a-sound-playing-the-waveform.md)     Audio DMA enable for channels 3-0 (x = 3 - 0).


            Table 7-6: Contents of DMA Control Register
```
For more information on using the DMA, see the following chapters:

   Copper     Chapter 2: Coprocessor Hardware
   Bitplanes  Chapter 3: Playfield Hardware
   Sprites    Chapter 4: Sprite Hardware
   Audio      Chapter 5: Audio Hardware
   Blitter    Chapter 6: Blitter Hardware
   Disk       Chapter 8: Interface Hardware

Processor Access To Chip Memory
-------------------------------
The Amiga chips access Chip memory directly via DMA, rather than utilizing
traditional bus arbitration mechanisms. Therefore, processor supplied
features for multiprocessor support, such as the 68000 TAS (test and set)
instruction, cannot serve their intended purpose and are not supported by
the Amiga architecture.

