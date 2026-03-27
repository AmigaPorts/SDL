---
title: 27 / Display Routines and Structures / Characteristics of a Viewport
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-characteristics-of-a
functions: []
libraries: []
---

# 27 / Display Routines and Structures / Characteristics of a Viewport

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To describe a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) fully, you need to set the following parameters:
height, width, depth and display mode.

In addition to these parameters, you must tell the system the location in
memory from which the data for the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) display should be retrieved
(by associating with it a [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure) and how to position the final
ViewPort display on the screen. The ViewPort will take on the user's
default Workbench colors unless otherwise instructed with a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  See
the section called "[Preparing the ColorMap Structure](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md)" for more information.

