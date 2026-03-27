---
title: graphics.library/DoCollision
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-docollision
functions: [InitGels, SortGList]
libraries: [graphics.library]
---

# graphics.library/DoCollision

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    DoCollision -- Test every gel in gel list for collisions.
SYNOPSIS

```c
    DoCollision(rp)
                A1

    void DoCollision(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Tests each gel in gel list for boundary and gel-to-gel collisions.
    On detecting one of these collisions, the appropriate collision-
    handling routine is called. See the documentation for a thorough
    description of which collision routine is called. This routine
    expects to find the gel list correctly sorted in Y,X order.
    The system routine [SortGList](autodocs-2.0/graphics-library-sortglist.md) performs this function for the user.
```
INPUTS

```c
    rp = pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [SortGList()](autodocs-2.0/graphics-library-sortglist.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [SortGList — graphics.library](../autodocs/graphics.library.md#sortglist)
