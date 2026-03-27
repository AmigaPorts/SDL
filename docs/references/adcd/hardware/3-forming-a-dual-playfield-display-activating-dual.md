---
title: 3 / Forming a Dual-playfield Display / Activating Dual-Playfield Mode
manual: hardware
chapter: hardware
section: 3-forming-a-dual-playfield-display-activating-dual
functions: []
libraries: []
---

# 3 / Forming a Dual-playfield Display / Activating Dual-Playfield Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Writing a 1 to bit 10 (called DBLPF) of the bitplane control register
 [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  selects dual-playfield mode. Selecting dual-playfield mode changes
both the way the hardware groups the bitplanes for color interpretation --
all odd-numbered bitplanes are grouped together and all even-numbered
bitplanes are grouped together, and the way hardware can move the
bitplanes on the screen.

