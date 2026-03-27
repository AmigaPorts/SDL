---
title: 27 / / The RastPort Structure / RastPort Pen Position and Size
manual: libraries
chapter: libraries
section: 27-the-rastport-structure-rastport-pen-position-and-size
functions: []
libraries: []
---

# 27 / / The RastPort Structure / RastPort Pen Position and Size

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The graphics drawing routines keep the current position of the drawing pen
in the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) fields [cp_x](libraries/27-drawing-routines-the-rastport-structure.md) and [cp_y](libraries/27-drawing-routines-the-rastport-structure.md), for the horizontal and vertical
positions, respectively. The coordinate location 0,0 is in the upper left
corner of the drawing area.  The x value increases proceeding to the
right; the y value increases proceeding toward the bottom of the drawing
area.

The variables [RastPort.PenWidth](libraries/27-drawing-routines-the-rastport-structure.md) and [RastPort.PenHeight](libraries/27-drawing-routines-the-rastport-structure.md) are not currently
implemented.  These fields should not be read or written by applications.

