---
title: 4 / / Building the Data Structure / Sprite Control Word 2 : SPRxCTL
manual: hardware
chapter: hardware
section: 4-building-the-data-structure-sprite-control-word-2-sprxctl
functions: []
libraries: []
---

# 4 / / Building the Data Structure / Sprite Control Word 2 : SPRxCTL

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This word contains the vertical stopping position of the sprite on the
screen (i.e., the line AFTER the last displayed row of the sprite). It
also contains some data having to do with  [sprite attachment](hardware/4-sprite-hardware-attached-sprites.md) , which is
described later on.



```c
                                [SPRxCTL](hardware/4-control-registers-spr0ctl.md) 
                               ---------
          Bits 15-8       The low eight bits of VSTOP
          Bit 7           (Used in attachment)
          Bits 6-3        Unused (make zero)
          Bit 2           The VSTART high bit
          Bit 1           The VSTOP high bit
          Bit 0           The HSTART low bit
```
The value (VSTOP - VSTART) defines how many scan lines high the sprite
will be when it is displayed.

