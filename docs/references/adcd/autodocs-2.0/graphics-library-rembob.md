---
title: graphics.library/RemBob
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-rembob
functions: [DrawGList, RemIBob]
libraries: [graphics.library]
---

# graphics.library/RemBob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemBob -- Macro to remove a [Bob](autodocs-2.0/includes-graphics-gels-h.md) from the gel list.
```
SYNOPSIS

```c
    RemBob(bob)

    RemBob(struct [Bob](autodocs-2.0/includes-graphics-gels-h.md) *);
```
FUNCTION

```c
    Marks a [Bob](autodocs-2.0/includes-graphics-gels-h.md) as no-longer-required.  The gels internal code then
    removes the [Bob](autodocs-2.0/includes-graphics-gels-h.md) from the list of active gels the next time
    [DrawGList](autodocs-2.0/graphics-library-drawglist.md) is executed. This is implemented as a macro.
    If the user is double-buffering the [Bob](autodocs-2.0/includes-graphics-gels-h.md), it could take two
    calls to [DrawGList](autodocs-2.0/graphics-library-drawglist.md) before the [Bob](autodocs-2.0/includes-graphics-gels-h.md) actually disappears from
    the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
INPUTS

```c
    [Bob](autodocs-2.0/includes-graphics-gels-h.md) = pointer to the [Bob](autodocs-2.0/includes-graphics-gels-h.md) to be removed
```
RESULT

BUGS

SEE ALSO

```c
    [RemIBob()](autodocs-2.0/graphics-library-remibob.md)  [DrawGList()](autodocs-2.0/graphics-library-drawglist.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)  [graphics/gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md)
```

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
