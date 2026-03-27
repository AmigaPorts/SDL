---
title: 7 / / Setting and Clearing Bits / Blitter Interrupt
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-blitter-interrupt
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Blitter Interrupt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bit 6, BLIT, signals "blitter finished." If this bit is a 1, it indicates
that the blitter has completed the requested data transfer. The blitter is
now ready to accept another task. This bit generates a  [level 3 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) .

