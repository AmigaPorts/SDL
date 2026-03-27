---
title: graphics.library/InitGMasks
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initgmasks
functions: [InitMasks]
libraries: [graphics.library]
---

# graphics.library/InitGMasks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitGMasks -- Initialize all of the masks of an [AnimOb](autodocs-2.0/includes-graphics-gels-h.md).
```
SYNOPSIS

```c
    InitGMasks(anOb)
               A0

    void InitGMasks(struct [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) *);
```
FUNCTION

```c
    For every sequence of every component call [InitMasks](autodocs-2.0/graphics-library-initmasks.md).
```
INPUTS

```c
    anOb = pointer to the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md)
```
BUGS

SEE ALSO

```c
    [InitMasks()](autodocs-2.0/graphics-library-initmasks.md) [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [InitMasks — graphics.library](../autodocs/graphics.library.md#initmasks)
