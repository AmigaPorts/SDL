---
title: graphics.library/InitArea
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initarea
functions: [AreaDraw, AreaEllipse, AreaEnd, AreaMove]
libraries: [graphics.library]
---

# graphics.library/InitArea

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    InitArea -- Initialize vector collection matrix
SYNOPSIS


```c
    InitArea( areainfo, buffer, maxvectors )
                a0          a1      d0

    void InitArea(struct [AreaInfo](autodocs-2.0/includes-graphics-rastport-h.md) *, void *, SHORT);
```
FUNCTION

```c
    This function provides initialization for the vector collection
    matrix such that it has a size of (max vectors ).  The size of the
    region pointed to by buffer (short pointer) should be five (5) times as
    large as maxvectors. This size is in bytes.  Areafills done by using
    [AreaMove](autodocs-2.0/graphics-library-areamove.md), [AreaDraw](autodocs-2.0/graphics-library-areadraw.md), and [AreaEnd](autodocs-2.0/graphics-library-areaend.md) must have enough space allocated in
    this table to store all the points of the largest fill. [AreaEllipse](autodocs-2.0/graphics-library-areaellipse.md)
    takes up two vectors for every call. If AreaMove/Draw/Ellipse detect
    too many vectors going into the buffer they will return -1.
```
INPUTS

```c
    areainfo - pointer to [AreaInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure
    buffer - pointer to chunk of memory to collect vertices
    maxvectors - max number of vectors this buffer can hold
```
RESULT

```c
    Pointers are set up to begin storage of vectors done by
    [AreaMove](autodocs-2.0/graphics-library-areamove.md), [AreaDraw](autodocs-2.0/graphics-library-areadraw.md), and [AreaEllipse](autodocs-2.0/graphics-library-areaellipse.md).
```
BUGS

SEE ALSO

```c
    [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [AreaMove()](autodocs-2.0/graphics-library-areamove.md) [AreaDraw()](autodocs-2.0/graphics-library-areadraw.md) [AreaEllipse()](autodocs-2.0/graphics-library-areaellipse.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaDraw — graphics.library](../autodocs/graphics.library.md#areadraw)
- [AreaEllipse — graphics.library](../autodocs/graphics.library.md#areaellipse)
- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [AreaMove — graphics.library](../autodocs/graphics.library.md#areamove)
