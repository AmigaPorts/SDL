---
title: 27 / Introduction / Interlaced and Non-Interlaced Modes
manual: libraries
chapter: libraries
section: 27-introduction-interlaced-and-non-interlaced-modes
functions: []
libraries: []
---

# 27 / Introduction / Interlaced and Non-Interlaced Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In producing the complete display (262 lines in NTSC, 312 in PAL), the
video display device produces the top line, then the next lower line, then
the next, until it reaches the bottom of the screen.  When it reaches the
bottom, it returns to the top to start a new scan of the screen.  Each
complete set of lines is called a display field.  It takes about 1/60th of
a second to produce a complete NTSC display field (1/50th of a second for
PAL).

The Amiga has two vertical display modes: interlaced and non-interlaced.
In non-interlaced mode, the video display produces the same picture for
each successive display field.  A non-interlaced NTSC display normally has
about 200 lines in the viewable area (up to a maximum of 241 lines with
overscan) while a PAL display will normally show 256 lines (up to a
maximum of 283 with overscan).

With interlaced mode, the amount of information in the viewable area can
be doubled.  On an NTSC display this amounts to 400 lines (482 with
overscan), while on a PAL display it amounts to 512 lines (566 with
overscan).

For interlaced mode, the video beam scans the screen at the same rate
(1/60th of a second per complete NTSC video display field); however, it
takes two display fields to form a complete video display picture and
twice as much display memory to store line data.  During the first of each
pair of display fields, the system hardware shows the odd-numbered lines
of an interlaced display (1, 3, 5, and so on).  During the second display
field, it shows the even-numbered lines (2, 4, 6 and so on).  The second
field is positioned slightly lower so that the lines in the second field
are "interlaced" with those of the first field, giving the higher vertical
resolution of this mode.



                 _______________________________________
                |                                       |
                |  Data as Displayed     Data In Memory |
                |  -----------------     -------------- |
                | Odd field - Line 1        Line 1      |
                | Even field - Line 1       Line 2      |
                | Odd field - Line 2        Line 3      |
                | Even field - Line 2       Line 4      |
                |           ·                  ·        |
                |           ·                  ·        |
                |           ·                  ·        |
                | Odd field - Line 200      Line 399    |
                | Even field - Line 200     Line 400    |
                |_______________________________________|


    Figure 27-3: Interlaced Mode -- Display Fields and Data in Memory
The following figure shows a display formed as display lines 1, 2, 3, 4,
... 400.  The 400-line interlaced display uses the same physical display
area as a 200-line non-interlaced display.

           _____________________
  line 1 _|_____________________|_
```c
          |_____________________| \
          |      _________      |  \
          |      _________      |   \
          |                     |    \
          |      Odd Field      |     \   _____________________
          |      _________      |      \_|_____________________|_ Line 1
          |      _________      |       _|_|___________________|_ Line 2
          |_____________________|      / |                     |
          |_____________________|     /  | |                   |
          |_____________________|    /   |    Video Display    |
                                    /    | | (400 lines NTSC   |
           _____________________   /     |    512 lines PAL)   |
```
  line 2 _|_____________________|_/      | |                   |


```c
          |_____________________|        |                     |
          |      _________      |        |\|/                  |
          |      _________      |        |_____________________|
          |                     |
          |      Even Field     |      Same physical space as used
          |      _________      |       by a 200-line (256) PAL),
          |      _________      |         noninterlaced display.
          |_____________________|
          |_____________________|
          |_____________________|


         Figure 27-4: Interlaced Mode Doubles Vertical Resolution
```
During an interlaced display, it appears that both display fields are
present on the screen at the same time and form one complete picture.
However, interlaced displays will appear to flicker if adjacent (odd and
even) scan lines have contrasting brightness.  Choosing appropriate colors
for your display will reduce this flicker considerably.  This phenomenon
can also be reduced by using a long-persistence monitor, or alleviated
completely with a hardware de-interlacer.

