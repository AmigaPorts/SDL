---
title: 6 / Setting Up Menus / Disabling Menu Operations
manual: libraries
chapter: libraries
section: 6-setting-up-menus-disabling-menu-operations
functions: []
libraries: []
---

# 6 / Setting Up Menus / Disabling Menu Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If an application does not use menus at all, it may set the [WFLG_RMBTRAP](libraries/4-window-attributes-boolean-window-attribute-tags.md)
flag, which allows the program to trap right mouse button events for its
own use.

By setting the [WFLG_RMBTRAP](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag with the [WA_Flags](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag when the window is
opened, the program indicates that it does not want any menu operations at
all for the window.  Whenever the user presses the right button while this
window is active, the program will receive right button events as normal
[IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) events.

