---
title: 3 / Color Selection / Color Selection in Extra Half Brite (EHB) Mode
manual: hardware
chapter: hardware
section: 3-color-selection-color-selection-in-extra-half-brite-ehb
functions: []
libraries: []
---

# 3 / Color Selection / Color Selection in Extra Half Brite (EHB) Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga has a special mode called Extra Half Brite or EHB mode which
doubles the maximum number of colors that can be displayed at one time. To
use EHB mode, you must set up six bitplanes.  Then set  [BPU](hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md) =6 (bits 12,
13 and 14) in the  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md)  register. Set  [HOMOD](hardware/3-advanced-topics-hold-and-modify-mode.md) =0 (bit 11) and  [DBLPF](hardware/3-forming-a-dual-playfield-display-activating-dual.md) =0
(bit 10) in  [BPLCON0](hardware/3-playfield-hardware-summary-of-playfield-registers.md) .  In this mode, the information in bitplane 6
controls an intensity reduction in the other 5 bitplanes. The color
register output selected by the first five bitplanes is shifted to
half-intensity by the sixth bitplane. This allows 64 colors to be
displayed at one time instead of the usual 32.

   ECS playfield registers.
   -----------------------
   For  [information](hardware/c-enhanced-chip-set-ecs-hardware-and-the-graphics-library.md)  concerning the playfield hardware and the Enhanced
   Chip Set, see Appendix C.

