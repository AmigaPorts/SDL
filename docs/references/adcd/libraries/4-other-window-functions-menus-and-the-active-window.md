---
title: 4 / Other Window Functions / Menus and the Active Window
manual: libraries
chapter: libraries
section: 4-other-window-functions-menus-and-the-active-window
functions: [ClearMenuStrip, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# 4 / Other Window Functions / Menus and the Active Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menus for the active window will be displayed when the user presses the
menu button on the mouse.  Menus may be disabled for the window by not
providing a menu strip, or by clearing the menus with [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).
Similarly, if the active window has [WFLG_RMBTRAP](libraries/4-window-attributes-boolean-window-attribute-tags.md) set, the menu button will
not bring up the menus.

Two other functions, [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) and [ResetMenuStrip()](libraries/6-setting-up-menus-changing-menu-strips.md), are used to
attach or update the menu strip for a window.


```c
    void ClearMenuStrip( struct Window *window );
    BOOL SetMenuStrip( struct Window *window, struct Menu *menu );
    BOOL ResetMenuStrip( struct Window *window, struct Menu *menu );
```
If [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) has been called for a window, [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) must be
called before closing the window.  After ClearMenuStrip() has been called,
the user can no longer access menus for this window.  See the chapter
"[Intuition Menus](libraries/6-intuition-menus-setting-up-menus.md)," for complete information about setting up menus.

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
