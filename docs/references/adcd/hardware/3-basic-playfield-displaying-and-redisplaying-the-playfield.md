---
title: 3 / Basic Playfield / Displaying and Redisplaying the Playfield
manual: hardware
chapter: hardware
section: 3-basic-playfield-displaying-and-redisplaying-the-playfield
functions: []
libraries: []
---

# 3 / Basic Playfield / Displaying and Redisplaying the Playfield

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You start playfield display by making certain that the bitplane pointers
are set and bitplane DMA is turned on. You turn on bitplane DMA by writing
a 1 to bit BPLEN in the  [DMACON](hardware/7-system-control-hardware-dma-control.md)  (for DMA control) register. See Chapter
7, System Control Hardware, for instructions on setting this register.

Each time the playfield is redisplayed, you have to reset the bitplane
pointers. Resetting is necessary because the pointers have been
incremented to point to each successive word in memory and must be
repointed to the first word for the next display. You write
 [Copper instructions](hardware/2-coprocessor-hardware-putting-together-a-copper.md)  to handle the redisplay or perform this operation as
part of a  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  task.

