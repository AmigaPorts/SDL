---
title: 30 / / Creating and Using New Layers / Creating a Viewing Workspace
manual: libraries
chapter: libraries
section: 30-creating-and-using-new-layers-creating-a-viewing
functions: [InitVPort, InitView, LoadView, MakeVPort, MrgCop]
libraries: [graphics.library]
---

# 30 / / Creating and Using New Layers / Creating a Viewing Workspace

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A viewing workspace may be created by using the primitives [InitVPort()](libraries/27-forming-a-basic-display-preparing-the-viewport-structure.md),
[InitView()](libraries/27-forming-a-basic-display-preparing-the-view-structure.md), [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md), [MrgCop()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md), and [LoadView()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md). Please reference the
"[Graphics Primitives](libraries/27-graphics-primitives-display-routines-and-structures.md)" chapter for details on creating a low-level graphics
display.  Do not create Layers directly on Intuition screens.  Windows are
the only supported method of creating a layer on a screen.

---

## See Also

- [InitVPort — graphics.library](../autodocs/graphics.library.md#initvport)
- [InitView — graphics.library](../autodocs/graphics.library.md#initview)
- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
