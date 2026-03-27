---
title: 4 / Summary of Sprite Registers / Pointers
manual: hardware
chapter: hardware
section: 4-summary-of-sprite-registers-pointers
functions: []
libraries: []
---

# 4 / Summary of Sprite Registers / Pointers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Pointers are registers that are used by the system to point to the current
data being used. During a screen display, the registers are incremented to
point to the data being used as the screen display progresses. Therefore,
pointer registers must be freshly written during the start of the
 [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  period.

 [SPR0PTH and SPR0PTL](hardware/4-pointers-spr0pth-and-spr0ptl.md) 

