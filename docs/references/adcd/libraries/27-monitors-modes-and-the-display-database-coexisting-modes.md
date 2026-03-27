---
title: 27 / / Monitors, Modes and the Display Database / Coexisting Modes
manual: libraries
chapter: libraries
section: 27-monitors-modes-and-the-display-database-coexisting-modes
functions: []
libraries: []
---

# 27 / / Monitors, Modes and the Display Database / Coexisting Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each display mode specifies (among other things) a pixel resolution and a
monitor scan rate.  Though the Amiga has the unique ability to change
pixel resolutions on the fly, it is not possible to change the speed of a
monitor beam in mid-frame. Therefore, if you set up a display of two or
more [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s in different display modes requiring different scan rates,
at least one of the ViewPorts will be displayed with the wrong scan rate.

Such [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s can be coerced into a different mode designed for the scan
rate currently in effect.  You can do this in a couple of ways,
introducing or removing interlace to adjust the vertical dimension, and
changing to faster or slower pixels (higher or lower resolution) for the
horizontal dimension.

The disadvantage of introducing interlace is flicker.  The disadvantage of
increasing resolution is the lessening of the video bus bandwidth and
possibly a reduction in the number of colors or palette resolution.

Under Intuition, the frontmost screen determines which of the conflicting
modes will take precedence.  With the graphics library, the Modes field of
the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) and its frontmost [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) or, in Release 2, the [MonitorSpec](autodocs-2.0/includes-graphics-monitor-h.md) of
the [ViewExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) determine the scan rate.  For some monitors (such as the
A2024), simultaneous display is excluded.  This is a requirement only
because the A2024 modes require very special and intricate display Copper
list management.

