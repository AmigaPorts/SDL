---
title: Fonts
manual: amiga-mail
chapter: amiga-mail
section: fonts
functions: []
libraries: []
---

# Fonts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Some font format changes (old format supported).

* Private format of .font files has changed (use FixFonts to create).

* Default fonts may be larger, proportional.

* Topaz is now sans-serif.

* Any size font will be created via scaling as long as TextAttr.Flags
  FPF_DESIGNED bit is not set.  If you were asking for an extreme size,
  like size 1 to get smallest available, or 999 to get largest available,
  you will get a big (or very very small) surprise now.

* Do not use -1 for TextAttr.Flags or Styles, nor as the flags for
  AvailFonts (one high bit now causes AvailFonts to return different
  structures).  Only set what you know you want.  A kludge has been added
  to the OS to protect applications which currently pass -1 for AvailFonts
  flags.

