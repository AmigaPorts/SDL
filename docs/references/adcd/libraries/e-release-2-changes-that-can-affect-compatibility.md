---
title: E / Release 2 Changes That Can Affect Compatibility / Preferences
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility
functions: [GetScreenData, SetPrefs]
libraries: [intuition.library]
---

# E / Release 2 Changes That Can Affect Compatibility / Preferences

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * Some old struct [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) fields are now ignored by [SetPrefs()](libraries/13-preferences-in-1-3-and-older-versions-setting-1-3.md) (for

```c
    example [FontHeight](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md)). SetPrefs() also stops listening to the pointer
    fields as soon as a new-style pointer is passed to Intuition
    (new-style pointers can be taller or deeper).
```
  * [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) [ViewX/YOffset](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) only applies to the default mode. You

    cannot use these fields to move the position of all modes.
  * The [Preferences](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) [LaceWB](libraries/13-preferences-1-3-older-versions-preferences-structure-in.md) bit is not necessarily correct when Workbench

```c
    is in a new display mode (akin to [GetScreenData()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md)).
```

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [SetPrefs — intuition.library](../autodocs/intuition.library.md#setprefs)
