---
title: 5 / Gadget Size and Position / Positioning Gadgets in Window Borders
manual: libraries
chapter: libraries
section: 5-gadget-size-and-position-positioning-gadgets-in-window
functions: [AddGList, RemoveGList]
libraries: [intuition.library]
---

# 5 / Gadget Size and Position / Positioning Gadgets in Window Borders

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Gadgets may be placed in the borders of a window.  To do this, set one or
more of the border flags in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure and position the gadget
in the window border.  Setting these flags also tells Intuition to adjust
the size of the window's borders to accommodate the gadget.

Borders are adjusted only when the window is opened.  Although the
application can add and remove gadgets with [AddGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) and [RemoveGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md)
after the window is opened, Intuition does not readjust the borders.

A gadget may be placed into two borders by setting multiple border flags.
If a gadget is to be placed in two borders, it only makes sense to put the
gadget into adjoining borders.  Setting both side border flags or both the
top and bottom border flags for a particular gadget, will create a window
that is all border.

See the SuperBitMap example, [lines.c](libraries/lib-examples-lines-c.md), in the "Intuition Windows" chapter
for an example of creating [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets that are positioned within
a window's borders.

There are circumstances where the border size will not adjust properly so
that the gadget has the correct visual appearance.  One way to correct
this problem is to place a "hidden" gadget into the border, which forces
the border to the correct size.  Such a gadget would have no imagery and
would not cause any IDCMP messages to be sent on mouse button activity.
The gadget should be placed at the end of the gadget list of the window,
so that it does not cover up any other border gadgets.

Sometimes the sizing gadget can be used to adjust the width of the
borders, as in the case of [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets in the right or bottom
border.  The proportional gadget will only increase the width of the
border by enough so that the select box of the gadget fits within the
border, no space is reserved between the gadget and the inner edge of the
window.  By placing the size gadget in both borders (using the window
flags [WFLG_SIZEBRIGHT](libraries/4-window-attributes-boolean-window-attribute-tags.md) and [WFLG_SIZEBBOTTOM](libraries/4-window-attributes-boolean-window-attribute-tags.md)), the prop gadget sizes can be
adjusted so that there is an even margin on all sides.  This technique is
used in the lines.c example mentioned above.




    size gadget in        size gadget in        size gadget in
     both borders         bottom border          side border
    --------------        --------------        --------------

          |     |                    ||               |     |
          |     |                    ||               |     |
          |     |                    ||               |     |
          |     |                    ||               |     |
          |     |                    ||               |     |
     _____|_____|          __________||               |_____|
          |     |               |     |               |     |
          |   /||               |   /||               |   /||
          |  / ||               |  / ||               |  / ||
          | /__||               | /__||          _____| /__||
     _____|_____|          _____|_____|          _____|_____|
   Figure 5-2: Size Gadget in Various Window Border Combinations


The border flags [GACT_RIGHTBORDER](libraries/5-gadget-structure-gadget-activation-flags.md), [GACT_LEFTBORDER](libraries/5-gadget-structure-gadget-activation-flags.md), [GACT_TOPBORDER](libraries/5-gadget-structure-gadget-activation-flags.md) and
[GACT_BOTTOMBORDER](libraries/5-gadget-structure-gadget-activation-flags.md) which are set in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure declare that the gadget will be positioned in the border.
Gadgets which are declared to be in the border are automatically refreshed
by Intuition whenever the window borders need to be redrawn.  This
prevents the gadget imagery from being obliterated.

Some applications forgot to declare some of their gadgets as being in the
border.  While they looked fine prior to V36, they would have had some
gadget imagery overwritten by the new style of window borders introduced
with that release.  To ensure compatibility with such applications,
Intuition attempts to identify gadgets that are substantially in the
border but do not have the appropriate border flags set.  Such gadgets are
marked for the same refresh treatment as explicit border gadgets.
Applications should not rely on this behavior, but should instead declare
their border gadgets properly.

Gadgets that are not declared to be in the border, and whose dimensions
are 1 x 1 or smaller are never marked by Intuition as being effectively in
the border.  This is because some applications tuck a small non-selectable
gadget (of size 0x0 or 1x1) into the window border, and attach imagery for
the window to that gadget.  The application does this to get automatic
refresh of that imagery, since Intuition refreshes gadget imagery when
window damage occurs.

Beginning with V36, Intuition attempts to locate gadgets within the border
that do not have the appropriate flags set.  This may cause gadgets to
appear in the border when the application has not set any of the border
flags.  Applications should not rely on this behavior, nor should they
place non-border gadgets fully or partially within the window's borders.

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
