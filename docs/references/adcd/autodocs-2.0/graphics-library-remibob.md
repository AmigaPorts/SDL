---
title: graphics.library/RemIBob
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-remibob
functions: [InitGels, RemVSprite]
libraries: [graphics.library]
---

# graphics.library/RemIBob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemIBob -- Immediately remove a [Bob](autodocs-2.0/includes-graphics-gels-h.md) from the gel list and the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    RemIBob(bob, rp, vp)
            A0   A1  A2

    void RemIBob(struct [Bob](autodocs-2.0/includes-graphics-gels-h.md) *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *);
```
FUNCTION

```c
    Removes a [Bob](autodocs-2.0/includes-graphics-gels-h.md) immediately by uncoupling it from the gel list and
    erases it from the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
INPUTS

```c
    bob = pointer to the [Bob](autodocs-2.0/includes-graphics-gels-h.md) to be removed
    rp  = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) if the [Bob](autodocs-2.0/includes-graphics-gels-h.md) is to be erased
    vp  = pointer to the [ViewPort](autodocs-2.0/includes-graphics-view-h.md) for beam-synchronizing
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [RemVSprite()](autodocs-2.0/graphics-library-remvsprite.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [RemVSprite — graphics.library](../autodocs/graphics.library.md#remvsprite)
