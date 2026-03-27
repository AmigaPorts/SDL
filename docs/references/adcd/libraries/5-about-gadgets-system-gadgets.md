---
title: 5 / About Gadgets / System Gadgets
manual: libraries
chapter: libraries
section: 5-about-gadgets-system-gadgets
functions: []
libraries: []
---

# 5 / About Gadgets / System Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

System gadgets are predefined gadgets provided by Intuition to support
standard operations of windows and screens.  System gadgets have a
standard image and location in the borders of screens or windows.
Intuition manages the operation of all system gadgets except the close
gadget.

The drag and depth gadgets are automatically attached to each screen in
the system.  The application cannot control the creation of these gadgets,
but can control their display and operation.  Screens may be opened
"quiet", without any of the gadget imagery displayed.  Applications should
avoid covering the screen's gadgets with windows as this may prevent the
user from freely positioning the screen.  See the "[Intuition Screens](libraries/3-types-of-screens-screen-components.md)"
chapter for more information on the positioning and use of system gadgets
for screens.

The drag, depth, close, sizing and zoom gadgets are available to be
attached to each window.  These gadgets are not provided automatically,
the application must specify which gadgets it requires.  See the
"[Intuition Windows](libraries/4-about-windows-window-system-gadgets.md)" chapter for more information on the positioning and
use of system gadgets for windows.

