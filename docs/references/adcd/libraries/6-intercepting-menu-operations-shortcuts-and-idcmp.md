---
title: 6 / / Intercepting Menu Operations / Shortcuts and IDCMP_MENUVERIFY
manual: libraries
chapter: libraries
section: 6-intercepting-menu-operations-shortcuts-and-idcmp
functions: []
libraries: []
---

# 6 / / Intercepting Menu Operations / Shortcuts and IDCMP_MENUVERIFY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The idea behind [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) is to synchronize the program with
Intuition's menu handling sessions.  The motive was to allow a program to
arbitrate access to a custom screen's bitmap, so that Intuition would not
render menus before the application was prepared for them.

Some programs use [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) to permit them to intercept the right
mouse button for their own purposes.  Other programs use it to delay menu
operations while they recover from unusual events such as illegible colors
of the screen or double buffering and related [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) operations.

Menu shortcut keystrokes, for compatibility, also respect
[IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md).  They are always paired with an [IDCMP_MENUPICK](libraries/9-event-message-classes-and-flags-menu-flags.md) message
so that the program knows the menu operation is over.  This is true even
if the menu event is cancelled.

