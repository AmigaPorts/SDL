---
title: graphics.library/DrawEllipse
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-drawellipse
functions: []
libraries: []
---

# graphics.library/DrawEllipse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DrawEllipse -- Draw an ellipse centered at cx,cy with vertical
       and horizontal radii of a,b respectively.
SYNOPSIS

```c
    DrawEllipse( rp, cx, cy, a, b )
                 a1  d0  d1  d2 d3

    void DrawEllipse( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, SHORT, SHORT, SHORT, SHORT);
```
FUNCTION
   Creates an elliptical outline within the rectangular region

    specified by the parameters, using the current foreground pen color.
INPUTS

```c
    rp - pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) into which the ellipse will be drawn.
    cx - x coordinate of the centerpoint relative to the rastport.
    cy - y coordinate of the centerpoint relative to the rastport.
    a - the horizontal radius of the ellipse (note: a must be > 0)
    b - the vertical radius of the ellipse (note: b must be > 0)
```
BUGS

NOTES

    this routine does not clip the ellipse to a non-layered rastport.
SEE ALSO

```c
    DrawCircle(), [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```
