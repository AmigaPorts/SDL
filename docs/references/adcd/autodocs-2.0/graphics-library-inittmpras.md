---
title: graphics.library/InitTmpRas
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-inittmpras
functions: [AreaEnd, Flood, Text]
libraries: [graphics.library]
---

# graphics.library/InitTmpRas

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    InitTmpRas -- Initialize area of local memory for usage by
                    areafill, floodfill, text.
SYNOPSIS

```c
    InitTmpRas(tmpras, buffer, size)
                a0       a1     d0

    void InitTmpRas( struct [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md) *, void *, ULONG );
```
FUNCTION

```c
    The area of memory pointed to by buffer is set up to be used
    by [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) routines that may need to get some memory for
    intermediate operations in preparation to putting the graphics
    into the final [BitMap](autodocs-2.0/includes-graphics-gfx-h.md).
    Tmpras is used to control the usage of buffer.
```
INPUTS

```c
    tmpras - pointer to a [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md) structure to be linked into
            a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    buffer - pointer to a contguous piece of chip memory.
    size - size in bytes of buffer
```
RESULT

```c
    makes buffer available for users of [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
BUGS

```c
    Would be nice if RastPorts could share one [TmpRas](autodocs-2.0/includes-graphics-rastport-h.md).
```
SEE ALSO

```c
    [AreaEnd()](autodocs-2.0/graphics-library-areaend.md) [Flood()](autodocs-2.0/graphics-library-flood.md) [Text()](autodocs-2.0/graphics-library-text.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [AreaEnd — graphics.library](../autodocs/graphics.library.md#areaend)
- [Flood — graphics.library](../autodocs/graphics.library.md#flood)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
