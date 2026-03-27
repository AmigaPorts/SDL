---
title: graphics.library/ClipBlit
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-clipblit
functions: [BltBitMap]
libraries: [graphics.library]
---

# graphics.library/ClipBlit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ClipBlit  --  Calls [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md) after accounting for windows
```
SYNOPSIS

```c
    ClipBlit(Src, SrcX, SrcY, Dest, DestX, DestY, XSize, YSize, Minterm)
             A0   D0    D1    A1    D2     D3     D4     D5     D6

    void ClipBlit
         (struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD,
          WORD, WORD, UBYTE);
```
FUNCTION

```c
    Performs the same function as [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md), except that it
    takes into account the Layers and ClipRects of the layer library,
    all of which are (and should be) transparent to you.  So, whereas
    [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md) requires pointers to BitMaps, ClipBlit requires pointers to
    the RastPorts that contain the Bitmaps, Layers, etcetera.

    If you are going to blit blocks of data around via the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) of your
    Intuition [Window](autodocs-2.0/includes-intuition-intuition-h.md), you must call this routine (rather than [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md)).

    Either the Src [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), the Dest [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), both, or neither, can have
    Layers. This routine takes care of all cases.

    See [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md) for a thorough explanation.
```
INPUTS

```c
    Src          = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) of the source for your blit
    SrcX, SrcY   = the topleft offset into Src for your data
    Dest         = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to receive the blitted data
    DestX, DestY = the topleft offset into the destination [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    XSize        = the width of the blit
    YSize        = the height of the blit
    Minterm      = the boolean blitter function, where SRCB is
                   associated with the Src [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) and SRCC goes to the
                   Dest [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULT

BUGS

SEE ALSO

```c
    BltBitMap();
```

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
