---
title: 4 Intuition Windows / Window Types
manual: libraries
chapter: libraries
section: 4-intuition-windows-window-types
functions: []
libraries: []
---

# 4 Intuition Windows / Window Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are three special window types:  Backdrop, Borderless and
GimmeZeroZero.  Backdrop windows stay anchored to the back of the display.
Borderless windows have no borders rendered by Intuition. GimmeZeroZero
windows provide clipping to protect the borders from graphics rendered
into the window.

These window types can be combined, although the combinations are not
always useful.  For instance, a borderless, backdrop window can be
created; however, a borderless, GimmeZeroZero window does not make sense.
A window is not required to be any of these types.

 [Backdrop Window Type](libraries/4-window-types-backdrop-window-type.md)      [GimmeZeroZero Window Type](libraries/4-window-types-gimmezerozero-window-type.md) 
 [Borderless Window Type](libraries/4-window-types-borderless-window-type.md) 

