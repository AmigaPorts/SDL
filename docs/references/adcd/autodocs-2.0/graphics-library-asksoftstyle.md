---
title: graphics.library/AskSoftStyle
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-asksoftstyle
functions: [SetSoftStyle]
libraries: [graphics.library]
---

# graphics.library/AskSoftStyle

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AskSoftStyle -- Get the soft style bits of the current font.
SYNOPSIS

```c
    enable = AskSoftStyle(rp)
    D0                    A1

    ULONG AskSoftStyle(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    This function returns those style bits of the current font
    that are not intrinsic in the font itself, but
    algorithmically generated.  These are the bits that are
    valid to set in the enable mask for [SetSoftStyle()](autodocs-2.0/graphics-library-setsoftstyle.md).
```
INPUTS

```c
    rp - the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) from which the font and style    are extracted.
```
RESULTS

    enable - those bits in the style algorithmically generated.
             Style bits that are not defined are also set.
BUGS

SEE ALSO

```c
    [SetSoftStyle()](autodocs-2.0/graphics-library-setsoftstyle.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```

---

## See Also

- [SetSoftStyle — graphics.library](../autodocs/graphics.library.md#setsoftstyle)
