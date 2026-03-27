---
title: 2 / The WAIT Instruction / Horizontal Beam Position
manual: hardware
chapter: hardware
section: 2-the-wait-instruction-horizontal-beam-position
functions: []
libraries: []
---

# 2 / The WAIT Instruction / Horizontal Beam Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The horizontal beam position has a value of $0 to $E2. The least
significant bit is not used in the comparison, so there are 113 positions
available for Copper operations. This corresponds to 4 pixels in low
resolution and 8 pixels in high resolution. Horizontal blanking falls in
the range of $0F to $35. The standard screen (320 pixels wide) has an
unused horizontal portion of $04 to $47 (during which only the background
color is displayed).

All lines are not the same length in NTSC. Every other line is a long line
(228  [color clocks](hardware/6-blitter-hardware-blitter-operations-and-system-dma.md) , 0-$E3), with the others being 227  [color clocks](hardware/6-blitter-hardware-blitter-operations-and-system-dma.md) 
long. In PAL, they are all 227 long. The display sees all these lines as
227 1/2  [color clocks](hardware/6-blitter-hardware-blitter-operations-and-system-dma.md)  long, while the Copper sees alternating long and
short lines.

