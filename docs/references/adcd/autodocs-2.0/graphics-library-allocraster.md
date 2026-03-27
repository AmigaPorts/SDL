---
title: graphics.library/AllocRaster
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-allocraster
functions: [FreeRaster]
libraries: [graphics.library]
---

# graphics.library/AllocRaster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AllocRaster -- Allocate space for a bitplane.
SYNOPSIS

```c
    planeptr = AllocRaster( width, height )
       d0                    d0:16  d1:16

    PLANEPTR AllocRaster(UWORD,UWORD);
```
FUNCTION

    This function calls the memory allocation routines
    to allocate memory space for a bitplane width bits
    wide and height bits high.
INPUTS

    width   - number of bits wide for bitplane
    height  - number of rows in bitplane
RESULT
    planeptr - pointer to first word in bitplane, or NULL if
               it was not possible to allocate the desired
               amount of memory.
BUGS

SEE ALSO

```c
    [FreeRaster()](autodocs-2.0/graphics-library-freeraster.md) [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)
```

---

## See Also

- [FreeRaster — graphics.library](../autodocs/graphics.library.md#freeraster)
