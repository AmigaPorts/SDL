---
title: 6 / Line Mode / Register Summary for Line Mode
manual: hardware
chapter: hardware
section: 6-line-mode-register-summary-for-line-mode
functions: []
libraries: []
---

# 6 / Line Mode / Register Summary for Line Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Preliminary setup:

   The line goes from (x1,y1) to (x2,y2).

   dx = max(abs(x2 - x1), abs(y2 - y1)) ;
   dy = min(abs(x2 - x1), abs(y2 - y1)) ;

Register setup:

   [BLTADAT](hardware/6-blitter-hardware-dma-channels.md)  = $8000
   [BLTBDAT](hardware/6-blitter-hardware-dma-channels.md)  = line texture pattern ($FFFF for a solid line)

   [BLTAFWM](hardware/6-blitter-hardware-shifts-and-masks.md)  = $FFFF
   [BLTALWM](hardware/6-blitter-hardware-shifts-and-masks.md)  = $FFFF

   [BLTAMOD](hardware/6-blitter-hardware-dma-channels.md)  = 4 * (dy - dx)
   [BLTBMOD](hardware/6-blitter-hardware-dma-channels.md)  = 4 * dy
   [BLTCMOD](hardware/6-blitter-hardware-dma-channels.md)  = width of the bitplane in bytes
   [BLTDMOD](hardware/6-blitter-hardware-dma-channels.md)  = width of the bitplane in bytes

   [BLTAPT](hardware/6-blitter-hardware-dma-channels.md)   = (4 * dy) - (2 * dx)
   [BLTBPT](hardware/6-blitter-hardware-dma-channels.md)   = unused
   [BLTCPT](hardware/6-blitter-hardware-dma-channels.md)   = word containing the first pixel of the line
   [BLTDPT](hardware/6-blitter-hardware-dma-channels.md)   = word containing the first pixel of the line

   [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)  bits 15-12 = x1 modulo 15
   [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)  bits SRCA, SRCC, and SRCD = 1
   [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  SRCB = 0

```c
            If exclusive-or line mode:                  _   _
                     then BLTCON0  [LF control byte](hardware/6-blitter-hardware-function-generator.md)  = ABC + AC
                                                           _
                     else BLTCON0  [LF control byte](hardware/6-blitter-hardware-function-generator.md)  = AB + AC
```
   [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  [LINEMODE](hardware/6-blitter-hardware-line-mode.md)  = 1
   [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  [OVFLAG](hardware/6-blitter-hardware-line-mode.md)  = 0
   [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bits 4-2 =  [octant number](hardware/6-blitter-hardware-line-mode.md)  from table
   [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bits 15-12 = start bit for line texture (0 = last significant

```c
            If (((4 * dy) - (2 * dx)) < 0):                bit)
                     then  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  [SIGNFLAG](hardware/6-blitter-hardware-line-mode.md)  = 1
                     else  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  [SIGNFLAG](hardware/6-blitter-hardware-line-mode.md)  = 0
            If one pixel/row:
                     then  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  [ONEDOT](hardware/6-blitter-hardware-line-mode.md)  = 1
                     else  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  bit  [ONEDOT](hardware/6-blitter-hardware-line-mode.md)  = 0
```
   [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md)  bits 15-6 = dx + 1
   [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md)  bits  5-0 = 2

   Warning:
   --------
   You must set the  [BLTSIZE](hardware/6-blitter-hardware-dma-channels.md)  register last as it starts the blit.

