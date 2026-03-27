---
title: 8 / Creating Text / Linking Text Strings
manual: libraries
chapter: libraries
section: 8-creating-text-linking-text-strings
functions: [PrintIText]
libraries: [intuition.library]
---

# 8 / Creating Text / Linking Text Strings

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [NextText](libraries/8-creating-text-intuitext-structure.md) field can point to another instance of an [IntuiText](libraries/8-creating-text-intuitext-structure.md)
structure.  This allows the application to create a complex object which
has several distinct groups of characters, each with its own color, font,
location, and drawing mode.  This can be used to create multiple lines of
text, to position characters in the text very accurately and to change the
color or font of the text.  Each list of IntuiText objects may be drawn
with one call to [PrintIText()](libraries/8-creating-text-directly-drawing-the-intuitext.md), or attached to a gadget, menu or requester
as a single object.

---

## See Also

- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
