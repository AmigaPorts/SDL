---
title: E / Release 2 Changes That Can Affect Compatibility / Fonts
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-fonts
functions: []
libraries: []
---

# E / Release 2 Changes That Can Affect Compatibility / Fonts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Some font format changes (old format supported).

  * Private format of .font files has changed (use FixFonts to create).

  * Default fonts may be larger, proportional.

  * Topaz is now sans-serif.

  * Any size font will be created via scaling as long as [TextAttr.Flags](libraries/29-the-text-function-choosing-the-font.md)

```c
    [FPF_DESIGNED](libraries/29-the-text-function-choosing-the-font.md) bit is not set.  If you were asking for an extreme size,
    like size 1 to get smallest available, or 999 to get largest
    available, you will get a big (or very very small) surprise now.
```
  * Do not use -1 for [TextAttr.Flags](libraries/29-the-text-function-choosing-the-font.md) or [Styles](libraries/29-the-text-function-choosing-the-font.md), nor as the flags for

```c
    [AvailFonts](autodocs-2.0/includes-libraries-diskfont-h.md) (one high bit now causes AvailFonts to return different
    structures).  Only set what you know you want.  A kludge has been
    added to the OS to protect applications which currently pass -1 for
    AvailFonts flags.
```
