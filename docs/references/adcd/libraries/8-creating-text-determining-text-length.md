---
title: 8 / Creating Text / Determining Text Length
manual: libraries
chapter: libraries
section: 8-creating-text-determining-text-length
functions: [IntuiTextLength]
libraries: [intuition.library]
---

# 8 / Creating Text / Determining Text Length

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To determine the pixel length of a given [IntuiText](libraries/8-creating-text-intuitext-structure.md) string, call the
[IntuiTextLength()](autodocs-2.0/intuition-library-intuitextlength.md) function.


```c
    LONG IntuiTextLength( struct IntuiText *iText );
```
Set the iText argument to point to the [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure whose length is
to be found.  This function will return the length of the iText text
string in pixels.  Note that if the [ITextFont](libraries/8-creating-text-intuitext-structure.md) field of the given IntuiText
is set to NULL, or Intuition cannot access the specified font, then
[GfxBase->DefaultFont](autodocs-2.0/includes-graphics-gfxbase-h.md) will be used in determining the length of the text.
This may not be the same as the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) font with which the text would be
printed.

---

## See Also

- [IntuiTextLength — intuition.library](../autodocs/intuition.library.md#intuitextlength)
