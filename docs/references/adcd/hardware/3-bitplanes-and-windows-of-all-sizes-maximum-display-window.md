---
title: 3 / Bitplanes and Windows of All Sizes / Maximum Display Window Size
manual: hardware
chapter: hardware
section: 3-bitplanes-and-windows-of-all-sizes-maximum-display-window
functions: []
libraries: []
---

# 3 / Bitplanes and Windows of All Sizes / Maximum Display Window Size

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The maximum size of a playfield display is determined by the maximum
number of lines and the maximum number of columns. Vertically, the
restrictions are simple. No data can be displayed in the
 [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  area. The following table shows the allowable vertical
display area.




```c
                              NTSC                 PAL
                              ----                 ---

     Vertical Blank Start     0                    0
      Vertical Blank Stop     $15 (21)             $1D (29)


                              NTSC     NTSC        PAL      PAL
                              Normal   Interlaced  Normal   Interlaced
                              ------   ----------  ------   ----------
        Displayable lines
          of screen video     241      483         283      567
                                       =525-(21*2)          =625-(29*2)


        Table 3-13: Maximum Allowable Vertical Screen Video
```
Horizontally, the situation is similar. Strictly speaking, the hardware
sets a rightmost limit to  [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  of ($D8) and a leftmost limit to
 [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  of ($18). This gives a maximum of 25 words fetched in low
resolution mode. In high resolution mode the maximum here is 49 words,
because the rightmost limit remains ($D8) and only one word is fetched at
this limit. However, horizontal blanking actually limits the displayable
video to 368 low resolution pixels (23 words). These numbers are the same
both for NTSC and for PAL. In addition, it should be noted that using a
data-fetch start earlier than ($38) will disable some  [sprites](hardware/4-sprite-hardware-creating-additional-sprites.md) .




```c
        Table 3-14: Maximum Allowable Horizontal Screen Video

                                   Lores            Hires
                                   -----            -----
         [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  (standard)       $0038            $003C
         [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  (standard)       $00D0            $00D4

         [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  (hw limits)      $0018            $0018
         [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md)  (hw limits)      $00D8            $00D8

         max words fetched         25               49
         max display pixels        368 (low res)
```
The limits on the display window starting and stopping positions described
in this section apply to the Amiga's original custom chip set. In the
Enhanced Chip Set (ECS), the limits for playfield display windows have
been changed.  For more information on  [ECS and playfield display windows](hardware/c-ecs-hardware-and-graphics-library-display-window.md) 
refer to Appendix C, Enhanced Chip Set.

