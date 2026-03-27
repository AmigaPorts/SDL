---
title: graphics.library/ExtendFont
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-extendfont
functions: []
libraries: []
---

# graphics.library/ExtendFont

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ExtendFont -- ensure tf_Extension has been built for a font (V36)
```
SYNOPSIS

```c
    success = ExtendFont(font, fontTags)
    D0                   A0    A1

    ULONG ExtendFont(struct [TextFont](autodocs-2.0/includes-graphics-text-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);
```
SEE ALSO

```c
    [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)
```
