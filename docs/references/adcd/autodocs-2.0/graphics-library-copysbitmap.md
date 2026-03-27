---
title: graphics.library/CopySBitMap
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-copysbitmap
functions: [LockLayerRom, SyncSBitMap]
libraries: [graphics.library]
---

# graphics.library/CopySBitMap

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CopySBitMap --   Syncronize [Layer](autodocs-2.0/includes-graphics-clip-h.md) window with contents of
                                            Super [BitMap](autodocs-2.0/includes-graphics-gfx-h.md)
```
SYNOPSIS

```c
    CopySBitMap( layer )
                 a0

    void CopySBitMap(struct [Layer](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    This is the inverse of [SyncSBitMap](autodocs-2.0/graphics-library-syncsbitmap.md).
    Copy all bits from SuperBitMap to [Layer](autodocs-2.0/includes-graphics-clip-h.md) bounds.
    This is used for those functions that do not
    want to deal with the [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) structures but do want
    to be able to work with a SuperBitMap [Layer](autodocs-2.0/includes-graphics-clip-h.md).
```
INPUTS

```c
    layer - pointer to a SuperBitMap [Layer](autodocs-2.0/includes-graphics-clip-h.md)
        The [Layer](autodocs-2.0/includes-graphics-clip-h.md) must already be locked by the caller.
```
BUGS

SEE ALSO

```c
    [LockLayerRom()](autodocs-2.0/graphics-library-locklayerrom.md) [SyncSBitMap()](autodocs-2.0/graphics-library-syncsbitmap.md)
```

---

## See Also

- [LockLayerRom — graphics.library](../autodocs/graphics.library.md#locklayerrom)
- [SyncSBitMap — graphics.library](../autodocs/graphics.library.md#syncsbitmap)
