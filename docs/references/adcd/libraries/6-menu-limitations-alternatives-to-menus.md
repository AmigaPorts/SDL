---
title: 6 / / Menu Limitations / Alternatives to Menus
manual: libraries
chapter: libraries
section: 6-menu-limitations-alternatives-to-menus
functions: []
libraries: []
---

# 6 / / Menu Limitations / Alternatives to Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You may want to use a requester or a window as an alternative to menus.  A
requester can function as a "super menu" using gadgets to provide the
commands and options of a menu but with fewer restrictions on their
placement, size and layout.  See the chapter entitled
"[Intuition Requesters and Alerts](libraries/7-intuition-requesters-and-alerts-true-requesters.md)," for more information.

A window, also, could be substituted for a menu where an application has
special requirements.  Unlike menus, windows allow layered operations so
that commands and options can be presented without forcing all other
window output in the active screen to halt.

Windows may be sized, positioned and depth arranged.  This positioning
flexibility allows the user to make other parts of the screen and other
windows visible while they are entering data or selecting operations.  The
ability to access or view other data may be important in the user's choice
of actions or attributes.  See the "[Intuition Windows](libraries/4-intuition-windows.md)" chapter for more
details.

