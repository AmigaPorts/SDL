---
title: graphics.library/TextLength
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-textlength
functions: [Text, TextExtent, TextFit, Write]
libraries: [dos.library, graphics.library]
---

# graphics.library/TextLength

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    TextLength -- Determine raster length of text data.
SYNOPSIS

```c
    length = TextLength(rp, string, count)
    D0                  A1  A0      D0:16

    WORD TextLength(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, STRPTR, WORD);
```
FUNCTION

```c
    This graphics function determines the length that text data
    would occupy if output to the specified [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) with the
    current attributes.  The length is specified as the number of
    raster dots: to determine what the current position would be
    after a [Write()](autodocs-2.0/dos-library-write.md) using this string, add the length to cp_x
    (cp_y is unchanged by [Write()](autodocs-2.0/dos-library-write.md)).  Use the newer [TextExtent()](autodocs-2.0/graphics-library-textextent.md) to
    get more information.
```
INPUTS

```c
    rp     - a pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) which describes where the
             text attributes reside.
    string - the address of string to determine the length of
    count  - the string length.  If zero, there are no characters
             in the string.
```
RESULTS

    length - the number of pixels in x this text would occupy, not
             including any negative kerning that may take place at
             the beginning of the text string, nor taking into
             account the effects of any clipping that may take
             place.
NOTES

    Prior to V36, the result length occupied only the low word of
    d0 and was not sign extended into the high word.
BUGS

    A length that would overflow single word arithmatic is not
    calculated correctly.
SEE ALSO

```c
    [TextExtent()](autodocs-2.0/graphics-library-textextent.md)  [Text()](autodocs-2.0/graphics-library-text.md)  [TextFit()](autodocs-2.0/graphics-library-textfit.md)
    [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)
- [TextFit — graphics.library](../autodocs/graphics.library.md#textfit)
- [Write — dos.library](../autodocs/dos.library.md#write)
