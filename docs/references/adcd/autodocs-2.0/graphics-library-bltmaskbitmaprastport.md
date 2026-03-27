---
title: graphics.library/BltMaskBitMapRastPort
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-bltmaskbitmaprastport
functions: [BltBitMapRastPort]
libraries: [graphics.library]
---

# graphics.library/BltMaskBitMapRastPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    BltMaskBitMapRastPort -- blit from source bitmap to destination
    rastport with masking of source image.
SYNOPSIS

```c
    BltMaskBitMapRastPort
        (srcbm, srcx, srcy, destrp, destX, destY, sizeX, sizeY,
         A0     D0    D1    A1      D2     D3     D4     D5
         minterm, bltmask)
         D6       A2

    void BltMaskBitMapRastPort
         (struct [BitMap](autodocs-2.0/includes-graphics-gfx-h.md) *, WORD, WORD, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD,
          WORD, WORD, UBYTE, APTR);
```
FUNCTION

    Blits from source bitmap to position specified in destination rastport
    using bltmask to determine where source overlays destination, and
    minterm to determine whether to copy the source image "as is" or
    to "invert" the sense of the source image when copying. In either
    case, blit only occurs where the mask is non-zero.
INPUTS

```c
    srcbm   - a pointer to the source bitmap
    srcx    - x offset into source bitmap
    srcy    - y offset into source bitmap
    destrp  - a pointer to the destination rastport
    destX   - x offset into dest rastport
    destY   - y offset into dest rastport
    sizeX   - width of blit in pixels
    sizeY   - height of blit in rows
    minterm - either (ABC|ABNC|ANBC) if copy source and blit thru mask
              or     (ANBC)          if invert source and blit thru mask
    bltmask - pointer to the single bit-plane mask, which must be the
              same size and dimensions as the planes of the
              source bitmap.
```
RESULT

BUGS

SEE ALSO

```c
    [BltBitMapRastPort()](autodocs-2.0/graphics-library-bltbitmaprastport.md) [graphics/gfx.h](autodocs-2.0/includes-graphics-gfx-h.md) [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [BltBitMapRastPort — graphics.library](../autodocs/graphics.library.md#bltbitmaprastport)
