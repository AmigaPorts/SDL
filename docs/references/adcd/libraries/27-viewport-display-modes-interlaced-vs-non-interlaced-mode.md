---
title: 27 / / Viewport Display Modes / Interlaced vs. Non-interlaced Mode
manual: libraries
chapter: libraries
section: 27-viewport-display-modes-interlaced-vs-non-interlaced-mode
functions: []
libraries: []
---

# 27 / / Viewport Display Modes / Interlaced vs. Non-interlaced Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In interlaced mode, there are twice as many lines available as in
non-interlaced mode, providing better vertical resolution in the same
display area.


  -----------------------------------------
  -----------------------------------------
  ------------                -------------
  ----------- 200 lines define ------------  [ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) = 0
  -----------  a full screen   ------------
  ------------                -------------
  -----------------------------------------
  -----------------------------------------


  =========================================
  =========================================
  ============                =============
  =========== 400 lines define ============  [ViewPort.Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) = LACE
  ===========  a full screen   ============
  ============                =============
  =========================================
  =========================================



            Figure 27-15: How LACE Affects Vertical Resolution
If the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure does not specify [LACE](libraries/27-display-routines-and-structures-viewport-display-modes.md), and the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) specifies
LACE, only the top half of the ViewPort data will be displayed. If the
View structure specifies LACE and the ViewPort is non-interlaced, the same
ViewPort data will be repeated in both fields.  The height of the ViewPort
display is the height specified in the ViewPort structure. If both the
View and the ViewPort are interlaced, the ViewPort will be built with
double the normal vertical resolution.  That means it will need twice as
much data space in memory as a non-interlaced picture to fill the display.

