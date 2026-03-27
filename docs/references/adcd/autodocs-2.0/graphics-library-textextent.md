---
title: graphics.library/TextExtent
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-textextent
functions: [Text, TextFit, TextLength]
libraries: [graphics.library]
---

# graphics.library/TextExtent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    [TextExtent](autodocs-2.0/includes-graphics-text-h.md) -- Determine raster extent of text data. (V36)
```
SYNOPSIS

```c
    TextExtent(rp, string, count, textExtent)
               A1  A0      D0:16  A2

    void TextExtent(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, STRPTR, WORD,
         struct [TextExtent](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

```c
    This function determines a more complete metric of the space
    that a text string would render into than the [TextLength()](autodocs-2.0/graphics-library-textlength.md)
    function.
```
INPUTS

```c
    rp     - a pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) which describes where the
             text attributes reside.
    string - the address of the string to determine the length of.
    count  - the number of characters in the string.
            If zero, there are no characters in the string.
    textExtent - a structure to hold the result.
```
RESULTS

```c
    textExtent is filled in as follows:
        te_Width  - same as [TextLength()](autodocs-2.0/graphics-library-textlength.md) result: the rp_cp_x
                    advance that rendering this text would cause.
        te_Height - same as tf_YSize.  The height of the
                    font.
        te_Extent.MinX - the offset to the left side of the
                    rectangle this would render into.  Often zero.
        te_Extent.MinY - same as -tf_Baseline.  The offset
                    from the baseline to the top of the rectangle
                    this would render into.
        te_Extent.MaxX - the offset of the left side of the
                    rectangle this would render into.  Often the
                    same as te_Width-1.
        te_Extent.MaxY - same as tf_YSize-tf_Baseline-1.
                    The offset from the baseline to the bottom of
                    the rectanangle this would render into.
```
SEE ALSO

```c
    [TextLength()](autodocs-2.0/graphics-library-textlength.md)  [Text()](autodocs-2.0/graphics-library-text.md)  [TextFit()](autodocs-2.0/graphics-library-textfit.md)
    [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextFit — graphics.library](../autodocs/graphics.library.md#textfit)
- [TextLength — graphics.library](../autodocs/graphics.library.md#textlength)
