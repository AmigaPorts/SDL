---
title: graphics.library/SetFont
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-setfont
functions: [OpenDiskFont, OpenFont, SetFont, StripFont]
libraries: [diskfont.library, graphics.library]
---

# graphics.library/SetFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SetFont -- Set the text font and attributes in a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    SetFont(rp, font)
            A1   A0

    void SetFont(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [TextFont](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

```c
    This function sets the font in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to that described
    by font, and updates the text attributes to reflect that
    change.  This function clears the effect of any previous
    soft styles.
```
INPUTS

```c
    rp   - the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) in which the text attributes are to be changed
    font - pointer to a [TextFont](autodocs-2.0/includes-graphics-text-h.md) structure returned from [OpenFont()](autodocs-2.0/graphics-library-openfont.md)
           or [OpenDiskFont()](autodocs-2.0/diskfont-library-opendiskfont.md)
```
RESULT

NOTES

```c
    This function had previously been documented that it would
    accept a null font.  This practice is discouraged.
    o   Use of a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) with a null font with text routines has
        always been incorrect and risked the guru.
    o   Keeping an obsolete font pointer in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) is no more
        dangerous than keeping a zero one there.
    o   SetFont(rp, 0) causes spurious low memory accesses under
        some system software releases.

    As of V36, the following Amiga font variants are no longer
    directly supported:
        fonts with NULL tf_CharSpace and non-NULL tf_CharKern.
        fonts with non-NULL tf_CharSpace and NULL tf_CharKern.
        fonts with NULL tf_CharSpace and NULL tf_CharKern with
            a tf_CharLoc size component greater than tf_XSize.
    Attempts to SetFont these one of these font variants will
    cause the system to modify your font to make it acceptable.
```
BUGS

```c
    Calling SetFont() on in-code TextFonts (ie fonts not
    OpenFont()ed) will result in a loss of 24 bytes from
    the system as of V36.
    This can be resolved by calling [StripFont()](autodocs-2.0/graphics-library-stripfont.md).
```
SEE ALSO

```c
    [OpenFont()](autodocs-2.0/graphics-library-openfont.md)  [StripFont()](autodocs-2.0/graphics-library-stripfont.md)
    [diskfont.library/OpenDiskFont()](autodocs-2.0/diskfont-library-opendiskfont.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```

---

## See Also

- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [StripFont — graphics.library](../autodocs/graphics.library.md#stripfont)
