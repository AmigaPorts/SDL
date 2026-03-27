---
title: 4 / / Control Registers / SPR0CTL
manual: hardware
chapter: hardware
section: 4-control-registers-spr0ctl
functions: []
libraries: []
---

# 4 / / Control Registers / SPR0CTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This register is normally used only by the sprite  [DMA channel](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md) . It
contains control information that is used to control the sprite data-fetch
process. Bit positions:

   *  Bits 15-8 specify vertical stop position for a sprite image,

      bits V7 - V0.
   *  Bit 7 is the attach bit. This bit is valid only for odd-numbered

```c
      sprites. It indicates that sprites 0, 1 (or 2,3 or 4,5 or 6,7)
      will, for color interpretation, be considered as paired, and as
      such will be called four bits deep. The odd-numbered (higher
      number) sprite contains bits with the higher binary significance.

      During attach mode, the  [attached sprites](hardware/4-sprite-hardware-attached-sprites.md)  are normally moved
      horizontally and vertically together under processor control.
      This allows a greater selection of colors within the boundaries
      of the sprite itself. The sprites, although attached, remain
      capable of independent motion, however, and they will assume
      this larger color set only when their edges overlay one another.
```
   *  Bits 6-3 are reserved for future use (make zero).
   *  Bit 2 is bit V8 of vertical start.
   *  Bit 1 is bit V8 of vertical stop.
   *  Bit 0 is bit H0 of horizontal start.

Position and control registers for the other sprites work the same way as
described above for sprite 0.  The register names for the other sprites
are:


                    SPR1POS    SPR1CTL
                    SPR2POS    SPR2CTL
                    SPR3POS    SPR3CTL
                    SPR4POS    SPR4CTL
                    SPR5POS    SPR5CTL
                    SPR6POS    SPR6CTL
                    SPR7POS    SPR7CTL
