---
title: graphics.library/BltTemplate
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-blttemplate
functions: [BltBitMap]
libraries: [graphics.library]
---

# graphics.library/BltTemplate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    BltTemplate -- Cookie cut a shape in a rectangle to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    BltTemplate(SrcTemplate, SrcX, SrcMod, rp,
                A0           D0:16  D1:16  A1
        DstX,  DstY, SizeX, SizeY)
        D2:16  D3:16 D4:16  D5:16

    void BltTemplate(UWORD *, WORD, WORD, struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *,
         WORD, WORD, WORD, WORD);
```
FUNCTION

```c
    This function draws the image in the template into the
    [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) in the current color and drawing mode at the
    specified position.  The template is assumed not to overlap
    the destination.
    If the template falls outside the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) boundary, it is
    truncated to that boundary.

    Note: the SrcTemplate pointer should point to the "nearest" word
       (rounded down) of the template mask. Fine alignment of the mask
       is acheived by setting the SrcX bit offseet within the range
       of 0 to 15 decimal.
```
INPUTS

```c
    SrcTemplate  - pointer to the first (nearest) word of the template
                   mask.
    SrcX         - x bit offset into the template mask (range 0..15).
    SrcMod       - number of bytes per row in template mask.
    rp           - pointer to destination [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
    DstX, DstY   - x and y coordinates of the upper left
                   corner of the destination for the blit.
    SizeX, SizeY - size of the rectangle to be used as the
                   template.
```
NOTES

    o   This function may use the blitter.
SEE ALSO

```c
    [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
