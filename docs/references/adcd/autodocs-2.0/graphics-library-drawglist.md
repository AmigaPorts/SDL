---
title: graphics.library/DrawGList
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-drawglist
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/DrawGList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DrawGList -- [Process](autodocs-2.0/includes-dos-dosextens-h.md) the gel list, queueing VSprites, drawing Bobs.
```
SYNOPSIS

```c
    DrawGList(rp, vp)
              A1  A0

    void DrawGList(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *);
```
FUNCTION

```c
    Performs one pass of the current gel list.
       - If nextLine and lastColor are defined, these are
         initialized for each gel.
      - If it's a [VSprite](autodocs-2.0/includes-graphics-gels-h.md), build it into the copper list.
      - If it's a [Bob](autodocs-2.0/includes-graphics-gels-h.md), draw it into the current raster.
      - Copy the save values into the "old" variables,
         double-buffering if required.
```
INPUTS

```c
    rp = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) where Bobs will be drawn
    vp = pointer to the [ViewPort](autodocs-2.0/includes-graphics-view-h.md) for which VSprites will be created
```
RESULT

BUGS

    MUSTDRAW isn't implemented yet.
SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)  [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
