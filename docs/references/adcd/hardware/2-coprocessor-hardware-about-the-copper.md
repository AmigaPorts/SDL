---
title: 2 Coprocessor Hardware / About the Copper
manual: hardware
chapter: hardware
section: 2-coprocessor-hardware-about-the-copper
functions: []
libraries: []
---

# 2 Coprocessor Hardware / About the Copper

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Copper is a general purpose coprocessor that resides in one of the
Amiga's custom chips. It retrieves its instructions via direct memory
access (DMA). The Copper can control nearly the entire graphics system,
freeing the 680x0 to execute program logic; it can also directly affect
the contents of most of the chip control registers. It is a very powerful
tool for directing mid-screen modifications in graphics displays and for
directing the register changes that must occur during the
 [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  periods.  Among other things, it can control register
updates, reposition sprites, change the color palette, update the audio
channels, and control the blitter.

One of the features of the Copper is its ability to  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for a specific
video beam position, then  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  data into a system register. During the
 [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  period, the Copper examines the contents of the video beam position
counter directly. This means that while the Copper is waiting for the beam
to reach a specific position, it does not use the memory bus at all.
Therefore, the bus is freed for use by the other DMA channels or by the
680x0.

When the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  condition has been satisfied, the Copper steals memory
cycles from either the blitter or the 680x0 to move the specified data
into the selected special-purpose register.

The Copper is a two-cycle processor that requests the bus only during
odd-numbered memory cycles. This prevents collision with audio, disk,
refresh, sprites, and most low resolution display DMA access, all of which
use only the even-numbered memory cycles. The Copper, therefore, needs
priority over only the 680x0 and the blitter (the DMA channel that handles
animation, line drawing, and polygon filling).

As with all the other DMA channels in the Amiga system, the Copper can
retrieve its instructions only from the chip RAM area of system memory.

