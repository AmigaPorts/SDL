---
title: graphics.library/SyncSBitMap
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-syncsbitmap
functions: [CopySBitMap]
libraries: [graphics.library]
---

# graphics.library/SyncSBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SyncSBitMap --   Syncronize Super [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) with whatever is
                     in the standard [Layer](autodocs-2.0/includes-graphics-clip-h.md) bounds.
```
SYNOPSIS

```c
    SyncSBitMap( layer )
                  a0

    void SyncSBitMap( struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) * );
```
FUNCTION

```c
    Copy all bits from ClipRects in [Layer](autodocs-2.0/includes-graphics-clip-h.md) into Super [BitMap](autodocs-2.0/includes-graphics-gfx-h.md)
    [BitMap](autodocs-2.0/includes-graphics-gfx-h.md).  This is used for those functions that do not
    want to deal with the [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) structures but do want
    to be able to work with a SuperBitMap [Layer](autodocs-2.0/includes-graphics-clip-h.md).
```
INPUTS

```c
    layer - pointer to a [Layer](autodocs-2.0/includes-graphics-clip-h.md) that has a SuperBitMap
            The [Layer](autodocs-2.0/includes-graphics-clip-h.md) should already be locked by the caller.
```
RESULT

```c
    After calling this function, the programmer can manipulate
    the bits in the superbitmap associated with the layer.
    Afterwards, the programmer should call [CopySBitMap](autodocs-2.0/graphics-library-copysbitmap.md) to
    copy the bits back into the onscreen layer.
```
BUGS

SEE ALSO

```c
    [CopySBitMap()](autodocs-2.0/graphics-library-copysbitmap.md) [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```

---

## See Also

- [CopySBitMap — graphics.library](../autodocs/graphics.library.md#copysbitmap)
