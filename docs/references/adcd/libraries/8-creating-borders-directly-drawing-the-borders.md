---
title: 8 / Creating Borders / Directly Drawing the Borders
manual: libraries
chapter: libraries
section: 8-creating-borders-directly-drawing-the-borders
functions: [DrawBorder]
libraries: [intuition.library]
---

# 8 / Creating Borders / Directly Drawing the Borders

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Borders may be directly drawn by the application by calling the function
[DrawBorder()](autodocs-2.0/intuition-library-drawborder.md).


```c
    void DrawBorder( struct RastPort *rp, struct Border *border,
                     long leftOffset, long topOffset );
```
The rp argument is a pointer to the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) into which the border should
be drawn.  This rastport may come from a [Window](libraries/4-intuition-windows-the-window-structure.md) or [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.

The border argument is a pointer to a list of [Border](libraries/8-creating-borders-border-structure-definition.md) structures which are
to be rendered.  The list may contain a single Border structure.

The leftOffset and topOffset arguments are the external component, or base
position, for this list of [Border](libraries/8-creating-borders-border-structure-definition.md)s.  The [LeftEdge](libraries/8-creating-borders-border-structure-definition.md) and [TopEdge](libraries/8-creating-borders-border-structure-definition.md) values of
each Border structure are added to these to determine the Border position.

Borders may also be indirectly drawn by attaching them to gadgets, menus
or requesters.

---

## See Also

- [DrawBorder — intuition.library](../autodocs/intuition.library.md#drawborder)
