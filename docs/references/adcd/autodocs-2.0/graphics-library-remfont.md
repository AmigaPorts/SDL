---
title: graphics.library/RemFont
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-remfont
functions: [AddFont, SetFont]
libraries: [graphics.library]
---

# graphics.library/RemFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemFont -- Remove a font from the system list.
SYNOPSIS

```c
    RemFont(textFont)
            A1

    void RemFont(struct [TextFont](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

```c
    This function removes a font from the system, ensuring that
    access to it is restricted to those applications that
    currently have an active pointer to it: i.e. no new [SetFont](autodocs-2.0/graphics-library-setfont.md)
    requests to this font are satisfied.
```
INPUTS

```c
    textFont - the [TextFont](autodocs-2.0/includes-graphics-text-h.md) structure to remove.
```
RESULT

BUGS

SEE ALSO

```c
    [SetFont()](autodocs-2.0/graphics-library-setfont.md)  [AddFont()](autodocs-2.0/graphics-library-addfont.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```

---

## See Also

- [AddFont — graphics.library](../autodocs/graphics.library.md#addfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
