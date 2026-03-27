---
title: 6 / Setting Up Menus / Submitting and Removing Menu Strips
manual: libraries
chapter: libraries
section: 6-setting-up-menus-submitting-and-removing-menu-strips
functions: [ClearMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# 6 / Setting Up Menus / Submitting and Removing Menu Strips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once the application has set up the proper menu structures, linked them
into a list and attached the list to a window, the menu system completely
handles the menu display.  The menu strip is submitted to Intuition and
attached to the window by calling the function [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md).


```c
    BOOL SetMenuStrip( struct Window *window, struct Menu *menu );
```
[SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md) always returns TRUE.  This function can also be used to
attach a single menu strip to multiple windows by calling SetMenuStrip()
for each window ([see below](libraries/6-setting-up-menus-sharing-menu-strips.md)).

Any menu strip attached to a window must be removed before the window is
closed.  To remove the menu strip, call [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md).


```c
    void ClearMenuStrip( struct Window *window );
```
The menu example below demonstrates how to use these functions with a
simple menu strip.

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
