---
title: 6 / / Intercepting Menu Operations / A Warning on the MENUSTATE Flag
manual: libraries
chapter: libraries
section: 6-intercepting-menu-operations-a-warning-on-the-menustate
functions: []
libraries: []
---

# 6 / / Intercepting Menu Operations / A Warning on the MENUSTATE Flag

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The MENUSTATE flag is set by Intuition in [Window](libraries/4-intuition-windows-the-window-structure.md).Flags when the menus of
that window are in use.  Beware: in typical event driven programming, such
a state variable is not on the same timetable as the application's input
message handling, and should not be used to draw profound conclusions in
any program.  Use [IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) to synchronize with the menu handling.

