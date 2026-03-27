---
title: graphics.library/AddFont
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-addfont
functions: [RemFont, SetFont]
libraries: [graphics.library]
---

# graphics.library/AddFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddFont -- add a font to the system list
SYNOPSIS

```c
    AddFont(textFont)
            A1

    void AddFont(struct [TextFont](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

    This function adds the text font to the system, making it
    available for use by any application.  The font added must be
    in public memory, and remain until successfully removed.
INPUTS

```c
    textFont - a [TextFont](autodocs-2.0/includes-graphics-text-h.md) structure in public ram.
```
RESULT

BUGS

SEE ALSO

```c
    [SetFont()](autodocs-2.0/graphics-library-setfont.md)  [RemFont()](autodocs-2.0/graphics-library-remfont.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```

---

## See Also

- [RemFont — graphics.library](../autodocs/graphics.library.md#remfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
