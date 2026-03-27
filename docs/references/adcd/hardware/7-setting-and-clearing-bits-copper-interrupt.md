---
title: 7 / / Setting and Clearing Bits / Copper Interrupt
manual: hardware
chapter: hardware
section: 7-setting-and-clearing-bits-copper-interrupt
functions: []
libraries: []
---

# 7 / / Setting and Clearing Bits / Copper Interrupt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bit 4, COPER, is used by the Copper to issue a  [level 3 interrupt](hardware/7-setting-and-clearing-bits-figure-7-4-interrupt-priorities.md) . The
Copper can change the content of any of the bits of this register, as it
can write any value into most of the machine registers. However, this bit
has been reserved for specifically identifying the Copper as the interrupt
source.

Generally, you use this bit when you want to sense that the display beam
has reached a specific position on the screen, and you wish to change
something in memory based on this occurrence.

