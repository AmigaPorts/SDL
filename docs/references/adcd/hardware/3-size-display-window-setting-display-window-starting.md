---
title: 3 / / Size Display Window / Setting Display Window Starting Position
manual: hardware
chapter: hardware
section: 3-size-display-window-setting-display-window-starting
functions: []
libraries: []
---

# 3 / / Size Display Window / Setting Display Window Starting Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A horizontal starting position of approximately $81 and a vertical
starting position of approximately $2C centers the display on most
standard television screens. If you select high resolution mode (640
pixels horizontally) or interlaced mode (400 lines NTSC, 512 PAL) the
starting position does not change. The starting position is always
interpreted in low resolution, non-interlaced mode. In other words, you
select a starting position that represents the correct coordinates in low
resolution, non-interlaced mode.

The register  [DIWSTRT](hardware/3-picture-larger-selecting-the-display-window-starting.md)  (for "Display Window Start") controls the display
window starting position. This register contains both the horizontal and
vertical components of the display window starting positions, known
respectively as HSTART and VSTART. The following example sets DIWSTRT for
a basic playfield. You write $2C for VSTART and $81 for HSTART.


```c
     LEA     CUSTOM,a0            ; Get base address of custom hardware...
     MOVE.W  #$2C81,DIWSTRT(a0)   ; Display window start register...
```
