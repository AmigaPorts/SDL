---
title: graphics.library/AddVSprite
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-addvsprite
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/AddVSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddVSprite -- Add a [VSprite](autodocs-2.0/includes-graphics-gels-h.md) to the current gel list.
```
SYNOPSIS

```c
    AddVSprite(vs, rp)
               A0  A1

    void AddVSprite(struct [VSprite](autodocs-2.0/includes-graphics-gels-h.md) *, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Sets up the system [VSprite](autodocs-2.0/includes-graphics-gels-h.md) flags
    Links this [VSprite](autodocs-2.0/includes-graphics-gels-h.md) into the current gel list using its Y,X
```
INPUTS

```c
    vs = pointer to the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) structure to be added to the gel list
    rp = pointer to a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
