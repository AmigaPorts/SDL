---
title: graphics.library/OpenFont
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-openfont
functions: [CloseFont, SetFont]
libraries: [graphics.library]
---

# graphics.library/OpenFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OpenFont -- Get a pointer to a system font.
SYNOPSIS

```c
    font = OpenFont(textAttr)
    D0              A0

    struct [TextFont](autodocs-2.0/includes-graphics-text-h.md) *OpenFont(struct [TextAttr](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

```c
    This function searches the system font space for the graphics
    text font that best matches the attributes specified.  The
    pointer to the font returned can be used in subsequent
    [SetFont](autodocs-2.0/graphics-library-setfont.md) and [CloseFont](autodocs-2.0/graphics-library-closefont.md) calls.  It is important to match this
    call with a corresponding [CloseFont](autodocs-2.0/graphics-library-closefont.md) call for effective
    management of ram fonts.
```
INPUTS

```c
    textAttr - a [TextAttr](autodocs-2.0/includes-graphics-text-h.md) or [TTextAttr](autodocs-2.0/includes-graphics-text-h.md) structure that describes the
               text font attributes desired.
```
RESULT

    font is zero if the desired font cannot be found.  If the named
    font is found, but the size and style specified are not
    available, a font with the nearest attributes is returned.
SEE ALSO

```c
    [CloseFont()](autodocs-2.0/graphics-library-closefont.md)  [SetFont()](autodocs-2.0/graphics-library-setfont.md)
    [diskfont.library/OpenDiskFont](autodocs-2.0/diskfont-library-opendiskfont.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```

---

## See Also

- [CloseFont — graphics.library](../autodocs/graphics.library.md#closefont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
