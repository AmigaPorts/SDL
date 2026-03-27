---
title: graphics.library/ScrollRaster
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-scrollraster
functions: []
libraries: []
---

# graphics.library/ScrollRaster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
    ScrollRaster -- Push bits in rectangle in raster around by
                    dx,dy towards 0,0 inside rectangle.
SYNOPSIS

```c
    ScrollRaster(rp, dx, dy, xmin, ymin, xmax, ymax)
                 A1  D0  D1  D2    D3    D4    D5

    void ScrollRaster
         (struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD, WORD, WORD, WORD, WORD);
```
FUNCTION

```c
    Move the bits in the raster by (dx,dy) towards (0,0)
    The space vacated is RectFilled with BGPen.
    Limit the scroll operation to the rectangle defined
    by (xmin,ymin)(xmax,ymax). Bits outside will not be
    affected. If xmax,ymax is outside the rastport then use
    the lower right corner of the rastport.
    If you are dealing with a SimpleRefresh layered [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) you
    should check rp->Layer->Flags & LAYER_REFRESH to see if
    there is any damage in the damage list.  If there is you should
    call the appropriate BeginRefresh(Intuition) or BeginUpdate(graphics)
    routine sequence.
```
INPUTS

```c
    rp - pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
    dx,dy are integers that may be postive, zero, or negative
    xmin,ymin - upper left of bounding rectangle
    xmax,ymax - lower right of bounding rectangle
```
EXAMPLE

```c
    ScrollRaster(rp,0,1)    /* shift raster up by one row */
    ScrollRaster(rp,-1,-1)  /* shift raster down and to the right */
                            /* by 1 pixel                         */
```
BUGS

```c
    In 1.2/V1.3 if you ScrollRaster a SUPERBITMAP exactly left or
    right, and there is no [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md) attached to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), the system
    will allocate one for you, but will never free it or record its
    location. This bug has been fixed for V1.4.  The workaround for
    1.2/1.3 is to attach a valid [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md) of size at least
    MAXBYTESPERROW to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) before the call.

    Begining with V1.4 ScrollRaster adds the shifted areas into the
    damage list for SIMPLE_REFRESH windows. Due to unacceptable
    system overhead, the decision was made NOT to propagate this
    shifted area damage for SMART_REFRESH windows.
```
SEE ALSO

```c
    [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```
