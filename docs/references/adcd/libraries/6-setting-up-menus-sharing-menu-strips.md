---
title: 6 / Setting Up Menus / Sharing Menu Strips
manual: libraries
chapter: libraries
section: 6-setting-up-menus-sharing-menu-strips
functions: [ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# 6 / Setting Up Menus / Sharing Menu Strips

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A single menu strip may be attached to multiple windows in an application
by calling [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) for each window.  All of the windows must be on
the same screen for this to work.  Since menus are always associated with
the active window on a given screen, and since only one window may be
active on a screen at a time, only one window may display the shared menu
strip at any given time.

When multiple windows share a single menu strip, they will all "see" the
same state of the menus, that is, changes made to the menu strip from one
window will still exist when a new window is activated.  If the
application wishes to share menu strips but to have a different flag and
enabled status for each window, the program may watch [IDCMP_ACTIVEWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md)
for the windows and modify the menu strip to match the active window's
requirements at that point.  In addition, the application must also set
[IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) to insure that the user can't access the menus of a newly
activated window before the application can process the IDCMP_ACTIVEWINDOW
message.

[ResetMenuStrip()](libraries/6-setting-up-menus-changing-menu-strips.md) may also be used to set the menus for the multiple
windows as long as [SetMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md) is used first to attach the menu strip
to any one window and no major changes are made to the menu strip before
the calls to ResetMenuStrip() on subsequent windows.

---

## See Also

- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
