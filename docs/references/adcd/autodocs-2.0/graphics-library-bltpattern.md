---
title: graphics.library/BltPattern
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-bltpattern
functions: []
libraries: []
---

# graphics.library/BltPattern

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    BltPattern --  Using standard drawing rules for areafill,
                                     blit through a mask.
SYNOPSIS

```c
    BltPattern(rp, mask, xl, yl, maxx, maxy, bytecnt)
              a1,  a0   d0  d1   d2   d3     d4

    void BltPattern
       (struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, void *, SHORT, SHORT, SHORT, SHORT, SHORT);
```
FUNCTION

```c
    Blit using drawmode,areafill pattern, and mask
    at position rectangle (xl,yl) (maxx,maxy).
```
INPUTS

```c
    rp    -  points to the destination [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) for the blit.
    mask  -  points to 2 dimensional mask if needed
             if mask == NULL then use a rectangle.
    xl,yl -  coordinates of upper left of rectangular region in [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    maxx,maxy - points to lower right of rectangular region in [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    bytecnt - BytesPerRow for mask
```
RESULT

SEE ALSO

```c
    [AreaEnd](autodocs-2.0/graphics-library-areaend.md)
```
