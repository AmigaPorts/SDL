---
title: Preferences
manual: amiga-mail
chapter: amiga-mail
section: preferences
functions: [GetScreenData]
libraries: [intuition.library]
---

# Preferences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

* Some old struct Preferences fields are now ignored by SetPrefs (for
  example FontHeight).  SetPrefs also stops listening to the pointer
  fields as soon as a new-style pointer is passed to Intuition (new-style
  pointers can be taller or deeper).

* Preferences ViewX/YOffset only applies to the default mode.  You
  cannot use these fields to move the position of all modes.

* The Preferences LACEWB bit is not necessarily correct when Workbench
  is in a new display mode (akin to GetScreenData()).

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
