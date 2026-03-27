---
title: layers.library/SwapBitsRastPortClipRect
manual: autodocs-2.0
chapter: autodocs-2.0
section: layers-library-swapbitsrastportcliprect
functions: [WaitBlit]
libraries: [graphics.library]
---

# layers.library/SwapBitsRastPortClipRect

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SwapBitsRastPortClipRect -- Swap bits between common bitmap
                                and obscured [ClipRect](autodocs-2.0/includes-graphics-clip-h.md)
```
SYNOPSIS

```c
    SwapBitsRastPortClipRect( rp, cr )
                              a0  a1

    void SwapBitsRastPortClipRect( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) *);
```
FUNCTION

```c
    Support routine useful for those that need to do some
    operations not done by the layer library.  Allows programmer
    to swap the contents of a small [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) with a subsection of
    the display. This is accomplished without using extra memory.
    The bits in the display [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) are exchanged with the
    bits in the ClipRect's [BitMap](autodocs-2.0/includes-graphics-gfx-h.md).

    Note: the [ClipRect](autodocs-2.0/includes-graphics-clip-h.md) structures which the layer library allocates are
    actually a little bigger than those described in the [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
    include file.  So be warned that it is not a good idea to have
    instances of cliprects in your code.
```
INPUTS

    rp - pointer to rastport
    cr - pointer to cliprect to swap bits with
NOTE

```c
    Because the blit operation started by this function is done
    asynchronously, it is imperative that a [WaitBlit()](autodocs-2.0/graphics-library-waitblit.md) be performed before
    releasing or using the processor to modify any of the associated
    structures.
```
BUGS

SEE ALSO

```c
    [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md), [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md), [graphics/clip.h](autodocs-2.0/includes-graphics-clip-h.md)
```

---

## See Also

- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
