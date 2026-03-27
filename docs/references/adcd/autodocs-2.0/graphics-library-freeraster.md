---
title: graphics.library/FreeRaster
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freeraster
functions: [AllocRaster]
libraries: [graphics.library]
---

# graphics.library/FreeRaster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME


    FreeRaster -- Release an allocated area to the system free memory pool.
SYNOPSIS

```c
    FreeRaster( p, width, height)
               a0   d0:16  d1:16

    void FreeRaster( PLANEPTR, USHORT, USHORT);
```
FUNCTION

    Return the memory associated with this PLANEPTR of size
    width and height to the MEMF_CHIP memory pool.
INPUTS

```c
    p  =  a pointer to a memory space  returned  as  a
          result of a call to [AllocRaster](autodocs-2.0/graphics-library-allocraster.md).

    width - the width in bits of the bitplane.
    height - number of rows in bitplane.
```
BUGS

NOTES

```c
    Width and height should be the same values with which you
    called [AllocRaster](autodocs-2.0/graphics-library-allocraster.md) in the first place.
```
SEE ALSO

```c
    [AllocRaster()](autodocs-2.0/graphics-library-allocraster.md) [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)
```

---

## See Also

- [AllocRaster — graphics.library](../autodocs/graphics.library.md#allocraster)
