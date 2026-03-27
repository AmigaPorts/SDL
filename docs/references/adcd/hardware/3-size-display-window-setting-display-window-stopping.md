---
title: 3 / / Size Display Window / Setting Display Window Stopping Position
manual: hardware
chapter: hardware
section: 3-size-display-window-setting-display-window-stopping
functions: []
libraries: []
---

# 3 / / Size Display Window / Setting Display Window Stopping Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You also need to set the display window stopping position, which is the
lower right-hand corner of the display window. If you select high
resolution or interlaced mode, the stopping position does not change. Like
the starting position, it is interpreted in low resolution, non-interlaced
mode.

The register  [DIWSTOP](hardware/3-picture-is-larger-than-window-selecting-the-stopping.md)  (for Display Window Stop) controls the display window
stopping position. This register contains both the horizontal and vertical
components of the display window stopping positions, known respectively as
HSTOP and VSTOP. The instructions below show how to set HSTOP and VSTOP
for the basic playfield, assuming a starting position of ($81,$2C). Note
that the HSTOP value you write is the actual value minus 256 ($100). The
HSTOP position is restricted to the right-hand side of the screen. The
normal HSTOP value is ($1C1) but is written as ($C1). HSTOP is the same
both for NTSC and for PAL.

The VSTOP position is restricted to the lower half of the screen. This is
accomplished in the hardware by forcing the MSB of the stop position to be
the complement of the next MSB. This allows for a VSTOP position greater
than 256 ($100) using only 8 bits. Normally, the VSTOP is set to ($F4) for
NTSC, ($2C) for PAL.

   The normal NTSC  [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md)  is ($2C81).
   The normal NTSC DIWSTOP is ($F4C1).

   The normal PAL  [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md)  is ($2C81).
   The normal PAL DIWSTOP is ($2CC1).

The following example sets DIWSTOP for a basic playfield to $F4 for the
vertical position and $C1 for the horizontal position.

  LEA     CUSTOM,a0               ; Get base address of custom hardware...
  MOVE.W  #$F4C1,DIWSTOP(a0)      ; Display window stop register...


```c
            Table 3-9:  [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md)  and DIWSTOP Summary


                  Nominal Values            Possible Values
                  --------------            ---------------

                 NTSC          PAL          MIN          MAX
                 ----          ---          ---          ---
    [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md) :
```
   ----------


```c
       VSTART    $2C           $2C          $00          $FF
       HSTART    $81           $81          $00          $FF
     DIWSTOP:
     --------
        VSTOP    $F4           $2C (=$12C)  $80          $7F (=$17F)
        HSTOP    $C1           $C1          $00 (=$100)  $FF (=$1FF)
```
The minimum and maximum values for display windows have been extended
in the enhanced version of the Amiga's custom chip set (ECS).  See
Appendix C, Enhanced Chip Set for more information about the
 [display window registers](hardware/c-ecs-hardware-and-graphics-library-display-window.md) .

