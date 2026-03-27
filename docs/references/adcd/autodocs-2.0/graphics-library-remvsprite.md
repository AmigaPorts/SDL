---
title: graphics.library/RemVSprite
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-remvsprite
functions: [InitGels, RemIBob]
libraries: [graphics.library]
---

# graphics.library/RemVSprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemVSprite -- Remove a [VSprite](autodocs-2.0/includes-graphics-gels-h.md) from the current gel list.
```
SYNOPSIS

```c
    RemVSprite(vs)
               A0

    void RemVSprite(struct [VSprite](autodocs-2.0/includes-graphics-gels-h.md) *);
```
FUNCTION

```c
    Unlinks the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) from the current gel list.
```
INPUTS

```c
    vs = pointer to the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) structure to be removed from the gel list
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [RemIBob()](autodocs-2.0/graphics-library-remibob.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
