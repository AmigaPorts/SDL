---
title: 27 / / / Effect of Display Overscan on the Viewing Area
manual: libraries
chapter: libraries
section: 27-effect-of-display-overscan-on-the-viewing-area
functions: []
libraries: []
---

# 27 / / / Effect of Display Overscan on the Viewing Area

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To assure that the picture entirely fills the monitor (or television)
screen, the manufacturer of the video display device usually creates a
deliberate overscan.  That is, the video beam is swept across an area that
is larger than the viewable region of the monitor.

The video beam actually covers 262 vertical lines (312 for PAL).  The
user, however, sees only the portion of the picture that is within the
center region of the display, typically surrounded by a border as
illustrated in the figure below.  The center region is nominally about 200
lines high on an NTSC machine (256 lines for PAL).  Overscan also limits
the amount of video data that can appear on each display line.  The width
of the center region is nominally, about 320 pixels for both PAL and NTSC.

        ___________________
       |                   |
       |       ____________|____________
       |      |           \|/           |
       |      |·························|
       |      |- - - - - - - - - - - - -|   Overscan Region
       |      |- -*******************- -| / ---------------
       |      |- -*- - - - - - - - -*- -|/  Generally Graphics are
       |      |- -*- - - - - - - - -*- -/   not displayed in this area
       |      |   *                 *  /|
              |   *                 *   |
   Vertical   |   *                 *\  |
   Blanking   |   *                 * \ |
   Interval   |   *                 *  \|


```c
              |   *                 *   \
       |      |   *                 *   |\
       |      |- -*- - - - - - - - -*- -| \ Viewable Region
       |      |- -*- - - - - - - - -*- -|   ---------------
       |      |- -*******************- -|   Contains approximately
       |      |- - - - - - - - - - - - -|   200 video lines (256 PAL)
       |      |·························|   and 320 pixels across.
       |      |____________|____________|
       |                   |
       |___________________|


       Figure 27-2: Display Overscan Restricts Usable Picture Area
```
The flexibility of the Amiga graphics subsystem allows the overscan
region, which normally forms the border of the display, to be used for
application graphics instead.  So the nominal dimensions given above can
be enlarged.

The time during which the video beam is below the bottom line of the
viewable region and above the first line is called the vertical blanking
interval.  The recommended minimum to allow for this interval is 21 lines
for NTSC (29 lines for PAL).  So, for applications that take full
advantage of the overscan area, a maximum of 241 usable lines in NTSC (283
in PAL) can be achieved.  The display resolution can also be changed by
changing the Amiga display mode as discussed in the [sections below](libraries/27-introduction-low-high-and-super-high-resolution-modes.md).

