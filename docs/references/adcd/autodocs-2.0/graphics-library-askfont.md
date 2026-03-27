---
title: graphics.library/AskFont
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-askfont
functions: []
libraries: []
---

# graphics.library/AskFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AskFont -- get the text attributes of the current font
SYNOPSIS

```c
    AskFont(rp, textAttr)
            A1  A0

    void AskFont(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [TextAttr](autodocs-2.0/includes-graphics-text-h.md) *);
```
FUNCTION

```c
    This function fills the text attributes structure with the
    attributes of the current font in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
INPUTS

```c
    rp       - the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) from which the text attributes are
               extracted
    textAttr - the [TextAttr](autodocs-2.0/includes-graphics-text-h.md) structure to be filled.  Note that
               there is no support for a [TTextAttr](autodocs-2.0/includes-graphics-text-h.md).
```
RESULT

    The textAttr structure is filled with the RastPort's text
    attributes.
BUGS

SEE ALSO

```c
    [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```
