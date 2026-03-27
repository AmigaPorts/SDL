---
title: graphics.library/SortGList
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-sortglist
functions: [DoCollision, DrawGList, InitGels]
libraries: [graphics.library]
---

# graphics.library/SortGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SortGList -- Sort the current gel list, ordering its y,x coordinates.
SYNOPSIS

```c
    SortGList(rp)
              A1

    void SortGList(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Sorts the current gel list according to the gels' y,x coordinates.
    This sorting is essential before calls to [DrawGList](autodocs-2.0/graphics-library-drawglist.md) or [DoCollision](autodocs-2.0/graphics-library-docollision.md).
```
INPUTS

```c
    rp = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure containing the [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [DoCollision()](autodocs-2.0/graphics-library-docollision.md)  [DrawGList()](autodocs-2.0/graphics-library-drawglist.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [DoCollision — graphics.library](../autodocs/graphics.library.md#docollision)
- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
