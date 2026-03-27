---
title: graphics.library/AddBob
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-addbob
functions: [AddVSprite, InitGels]
libraries: [graphics.library]
---

# graphics.library/AddBob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddBob -- Adds a [Bob](autodocs-2.0/includes-graphics-gels-h.md) to current gel list.
```
SYNOPSIS

```c
    AddBob(Bob, rp)
           A0   A1

    void AddBob(struct [Bob](autodocs-2.0/includes-graphics-gels-h.md) *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Sets up the system [Bob](autodocs-2.0/includes-graphics-gels-h.md) flags, then links this gel into the list
    via [AddVSprite](autodocs-2.0/graphics-library-addvsprite.md).
```
INPUTS

```c
    [Bob](autodocs-2.0/includes-graphics-gels-h.md) = pointer to the [Bob](autodocs-2.0/includes-graphics-gels-h.md) structure to be added to the gel list
    rp  = pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [AddVSprite()](autodocs-2.0/graphics-library-addvsprite.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AddVSprite — graphics.library](../autodocs/graphics.library.md#addvsprite)
- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
