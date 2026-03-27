---
title: 4 / / Control Registers / SPR0POS
manual: hardware
chapter: hardware
section: 4-control-registers-spr0pos
functions: []
libraries: []
---

# 4 / / Control Registers / SPR0POS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the sprite 0 position register. The  [word](hardware/4-building-the-data-structure-sprite-control-word-1-sprxpos.md)  written into this
register controls the position on the screen at which the upper left-hand
corner of the sprite is to be placed. The most significant bit of the
first  [data word](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  will be placed in this position on the screen.

   Sprite placement resolution.
   ----------------------------
   The sprites have a placement resolution on a full screen of 320 by
   200 NTSC (320 by 256 PAL). The sprite resolution is independent of
   the bitplane resolution.

Bit positions:

   *  Bits 15-8 specify the vertical start position, bits V7 - V0.
   *  Bits 7-0 specify the horizontal start position, bits H8 - H1.

   Warning:
   --------
   This register is normally only written by the sprite  [DMA channel](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md) 
   itself. See the details above regarding the organization of the
   sprite data.  This register is usually updated directly by DMA.

