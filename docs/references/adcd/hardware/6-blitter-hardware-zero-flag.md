---
title: 6 Blitter Hardware / Zero Flag
manual: hardware
chapter: hardware
section: 6-blitter-hardware-zero-flag
functions: []
libraries: []
---

# 6 Blitter Hardware / Zero Flag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A blitter zero flag is provided that can be tested to determine if the
logic operation selected has resulted in zero bits for all destination
bits, even if those destination bits are not written due to the D
 [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  being disabled.  This feature is often useful for
 [collision detection](hardware/7-system-control-hardware-collision-detection.md) , by performing a logical "and" on two source images
to test for overlap. If the images do not overlap, the zero flag will stay
true.

The Zero flag is only valid after the blitter has completed its operation
and can be read from bit (13) DMAF_BLTNZERO of the  [DMACONR](hardware/7-system-control-hardware-dma-control.md)  register.

