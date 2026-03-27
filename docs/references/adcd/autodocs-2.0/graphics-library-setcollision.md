---
title: graphics.library/SetCollision
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setcollision
functions: [InitGels]
libraries: [graphics.library]
---

# graphics.library/SetCollision

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetCollision -- Set a pointer to a user collision routine.
SYNOPSIS

```c
    SetCollision(num, routine, GInfo)
                 D0   A0       A1

    void SetCollision(ULONG, VOID (*)(), struct [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Sets a specified entry (num) in the user's collision vectors table
    equal to the address of the specified collision routine.
```
INPUTS

```c
    num     = collision vector number
    routine = pointer to the user's collision routine
    GInfo   = pointer to a [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](autodocs-2.0/graphics-library-initgels.md)  [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [InitGels — graphics.library](../autodocs/graphics.library.md#initgels)
