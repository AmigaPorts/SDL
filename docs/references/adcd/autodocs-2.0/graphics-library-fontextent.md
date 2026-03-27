---
title: graphics.library/FontExtent
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-fontextent
functions: [TextExtent]
libraries: [graphics.library]
---

# graphics.library/FontExtent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FontExtent -- get the font attributes of the current font (V36)
```
SYNOPSIS

```c
    FontExtent(font, fontExtent)
               A0    A1

    void FontExtent(struct [TextFont](autodocs-2.0/includes-graphics-text-h.md) *, struct [TextExtent](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

```c
    This function fills the text extent structure with a bounding
    (i.e. maximum) extent for the characters in the specified font.
```
INPUTS

```c
    font       - the [TextFont](autodocs-2.0/includes-graphics-text-h.md) from which the font metrics are extracted.
    fontExtent - the [TextExtent](autodocs-2.0/includes-graphics-text-h.md) structure to be filled.
```
RESULT

    fontExtent is filled.
NOTES

```c
    The [TextFont](autodocs-2.0/includes-graphics-text-h.md), not the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), is specified -- unlike
    [TextExtent()](autodocs-2.0/graphics-library-textextent.md), effect of algorithmic enhancements is not
    included, nor does te_Width include any effect of
    rp_TxSpacing.  The returned te_Width will be negative only
    when FPF_REVPATH is set in the tf_Flags of the font -- the
    effect of left-moving characters is ignored for the width of
    a normal font, and the effect of right-moving characters is
    ignored if a REVPATH font.  These characters will, however,
    be reflected in the bounding extent.
```
SEE ALSO

```c
    [TextExtent()](autodocs-2.0/graphics-library-textextent.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```

---

## See Also

- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)
