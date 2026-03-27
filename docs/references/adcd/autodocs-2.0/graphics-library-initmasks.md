---
title: graphics.library/InitMasks
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initmasks
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/InitMasks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitMasks -- Initialize the BorderLine and CollMask masks of a [VSprite](autodocs-2.0/includes-graphics-gels-h.md).
```
SYNOPSIS

```c
    InitMasks(vs)
              A0

    void InitMasks(struct [VSprite](autodocs-2.0/includes-graphics-gels-h.md) *);
```
FUNCTION

```c
    Creates the appropriate BorderLine and CollMask masks of the [VSprite](autodocs-2.0/includes-graphics-gels-h.md).
    Correctly detects if the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) is actually a [Bob](autodocs-2.0/includes-graphics-gels-h.md) definition, handles
    the image data accordingly.
```
INPUTS

```c
    vs = pointer to the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
