---
title: 4 / Window Types / GimmeZeroZero Window Type
manual: libraries
chapter: libraries
section: 4-window-types-gimmezerozero-window-type
functions: [InstallClipRegion, OpenWindowTagList]
libraries: [intuition.library, layers.library]
---

# 4 / Window Types / GimmeZeroZero Window Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GimmeZeroZero windows provide a window border layer separate from the main
(inner) window layer.  This allows the application to freely render into
the window without worrying about the window border and its contents.

System gadgets and the window title are placed in the border layer.
Application gadgets go into the inner window by default, but may be placed
in the border.  To position application gadgets in the border layer, the
[GTYP_GZZGADGET](libraries/5-intuition-gadgets-gadget-structure.md) flag and the appropriate [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) border flag must be set in
the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the Gadget.

The top left coordinates of the inner window are always (0,0), regardless
of the size or contents of the border, thus the name "GimmeZeroZero."  The
application need not take the border size into account when rendering.
The inner window always begins at (0,0) and extends to
(GZZWidth,GZZHeight).  The GZZWidth and GZZHeight variables are available
in the [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure.

The [GZZMouseX and GZZMouseY](libraries/4-intuition-windows-the-window-structure.md) variables provide the position of the mouse
relative to the inner window.  Note that the mouse positions in
[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md) events are always relative to the total window, even for
GimmeZeroZero windows.

Requesters in a GimmeZeroZero window are also positioned relative to the
inner window.  See the chapter entitled "[Intuition Requesters and Alerts](libraries/7-true-requesters-requester-display-position.md),"
for more information about requester location.

To specify a GimmeZeroZero window, set the WFLG_GIMMEZEROZERO flag or the
[WA_GimmeZeroZero](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag in the [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.


```c
    WARNING!
    --------
    The GimmeZeroZero window uses more system resources than other window
    types because the window creates a separate layer for the border
    display.  Using multiple GimmeZeroZero windows will quickly degrade
    performance in the positioning and sizing of windows.

    Applications should consider using regions as an alternative to
    GimmeZeroZero windows.  See the "[Layers Library](libraries/30-layers-library-regions.md)" chapter,
    especially the [InstallClipRegion()](libraries/30-regions-installing-regions.md) function, for information on
    setting up regions to limit graphics display in the window.
```

---

## See Also

- [InstallClipRegion — layers.library](../autodocs/layers.library.md#installclipregion)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
