---
title: 4 / / Building the Data Structure / Sprite Control Word 1 : SPRxPOS
manual: hardware
chapter: hardware
section: 4-building-the-data-structure-sprite-control-word-1-sprxpos
functions: []
libraries: []
---

# 4 / / Building the Data Structure / Sprite Control Word 1 : SPRxPOS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This word ( [SPR?POS](hardware/4-control-registers-spr0pos.md) ) contains the vertical (VSTART) and horizontal
(HSTART) starting position for the sprite. This is where the topmost line
of the sprite will be positioned.


          Bits 15-8 contain the low 8 bits of VSTART
          Bits 7-0 contain the high 8 bits of HSTART
