---
title: 3 Playfield Hardware / Moving (Scrolling) Playfields
manual: hardware
chapter: hardware
section: 3-playfield-hardware-moving-scrolling-playfields
functions: []
libraries: []
---

# 3 Playfield Hardware / Moving (Scrolling) Playfields

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you want a background display that moves, you can design a playfield
larger than the display window and scroll it. If you are using dual
playfields, you can scroll them separately.

In vertical scrolling, the playfield appears to move smoothly up or down
on the screen. All you need do for vertical scrolling is progressively
increase or decrease the starting address for the bitplane pointers by the
size of a horizontal line in the playfield. This has the effect of showing
a lower or higher part of the picture each field time.

In horizontal scrolling the playfield appears to move from right-to-left
or left-to-right on the screen. Horizontal scrolling works differently
from vertical scrolling -- you must arrange to fetch one more word of data
for each display line and delay the display of this data.

For either type of scrolling, resetting of pointers or data-fetch
registers can be handled by the Copper during the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) 
interval.

 [Vertical Scrolling](hardware/3-moving-scrolling-playfields-vertical-scrolling.md) 
 [Horizontal Scrolling](hardware/3-moving-scrolling-playfields-horizontal-scrolling.md) 
 [Scrolling Playfield Summary](hardware/3-moving-scrolling-playfields-scrolling-playfield-summary.md) 

