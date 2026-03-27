---
title: 6 / Setting Up Menus / Changing Menu Strips
manual: libraries
chapter: libraries
section: 6-setting-up-menus-changing-menu-strips
functions: [ClearMenuStrip, CloseWindow, OpenWindowTagList, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# 6 / Setting Up Menus / Changing Menu Strips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Direct changes to a menu strip attached to a window may be made only after
the menu strip has been removed from the window.  Use the [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md)
function to remove the menu strip.  It may be added back to the window
after the changes are complete.

Major changes include such things as adding or removing menus, items and
sub-items; changing text or image data; and changing the placement of the
data.  These changes require the system to completely re-layout the menus.

An additional function, [ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md), is available to let the
application make small changes to the menus without the overhead of
[SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).  Only two things in the menu strip may be changed before a
call to ResetMenuStrip(), they are: changing the [CHECKED](libraries/6-menu-data-structures-menuitem-flags.md) flag to turn
checkmarks on or off, and changing the [ITEMENABLED](libraries/6-menu-data-structures-menuitem-flags.md) flag to enable/disable
menus, items or sub-items.


```c
    BOOL ResetMenuStrip( struct Window *window, struct Menu *menu );
```
[ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md) is called in place of [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md), and may only be
called on menus that were previously initialized with a call to
SetMenuStrip().  As with SetMenuStrip(), the menu strip must be removed
from the window before calling ResetMenuStrip().  Note that the window
used in the ResetMenuStrip() call does not have to be the same window to
which the menu was previously attached.  The window, however, must be on a
screen of the same mode to prevent the need for recalculating the layout
of the menu.

If the application wishes to attach a different menu strip to a window
that already has an existing menu strip, the application must call
[ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) before calling [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) with the new menu strip.

The flow of events for menu operations should be:


```c
     1. [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md).

     2. [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).

     3. Zero or more iterations of [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) and
        [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md)/[ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md).

     4. [ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).

     5. [CloseWindow()](libraries/4-basic-window-structures-and-functions-closing-windows.md).
```

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
