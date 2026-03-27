---
title: 4 / Basic Window Structures and Functions / Window Border Dimensions
manual: libraries
chapter: libraries
section: 4-basic-window-structures-and-functions-window-border
functions: []
libraries: []
---

# 4 / Basic Window Structures and Functions / Window Border Dimensions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition automatically draws a border around a window unless directed
otherwise, such as by setting the [WFLG_BORDERLESS](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag.  [Borderless](libraries/4-window-types-borderless-window-type.md)
windows may not have a window title or gadgets in the border (this
includes the standard system gadgets).  Otherwise they won't come out
properly borderless.

The size of the border of an open window is available in the [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md)
structure variables [BorderLeft, BorderTop, BorderRight and BorderBottom](libraries/4-intuition-windows-the-window-structure.md).
Intuition fills these in when the window is opened.  To calculate the
window border sizes before the window is opened you use information in the
[Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure as shown in the next listing.



    Gadgets Can Change Border Sizes.
    --------------------------------
    The following calculations do not take application border gadgets
    into account. If the program adds gadgets into the window's borders,
    Intuition will expand the borders to hold the gadgets.
if (NULL != (screen = LockPubScreen(NULL)))

```c
    {
    top_border    = screen->WBorTop + screen->Font->ta_YSize + 1;
    left_border   = screen->WBorLeft;
    right_border  = screen->WBorRight;
    bottom_border = screen->WBorBottom;

    UnlockPubScreen(NULL,screen);
    }
```
/* if the sizing gadget is specified, then the border size must
** be adjusted for the border containing the gadget.  This may
** be the right border, the bottom border or both.
**
** We are using fixed values.  There is currently no system-approved
** method of finding this information before the window is opened.
** If you need to know these sizes BEFORE your window is opened,
** use the fixed values below.  Otherwise, use Window->BorderRight,
** etc. AFTER you have opened your window.
*/

/* values for non-lo-res screen */
right_border  = 18;  /* if sizing gadget in right border  */
bottom_border = 10;  /* if sizing gadget in bottom border */

/* values for lo-res screen */
right_border  = 13;  /* if sizing gadget in right border  */
bottom_border = 11;  /* if sizing gadget in bottom border */


Use the border sizes to position visual elements within the window.
Coordinates may be offset into the window by the size of the top and left
borders, for instance (x, y) becomes (x + [BorderLeft](libraries/4-intuition-windows-the-window-structure.md), y + [BorderTop](libraries/4-intuition-windows-the-window-structure.md)).
This may look clumsy, but it offers a way of avoiding a [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md)
window, which, although much more convenient to use, requires extra memory
and degrades performance.

The right and bottom border values specify the width of these borders.
The area within the borders of a window is defined as ([BorderLeft](libraries/4-intuition-windows-the-window-structure.md),
[BorderTop](libraries/4-intuition-windows-the-window-structure.md)) to ([Width](libraries/4-intuition-windows-the-window-structure.md) - 1 - [BorderRight](libraries/4-intuition-windows-the-window-structure.md), [Height](libraries/4-intuition-windows-the-window-structure.md) - 1 - [BorderBottom](libraries/4-intuition-windows-the-window-structure.md)).  The
calculations subtract one from the height and width of the windows as
positions count from zero, but dimensions count from one.

The window title bar is only available if one or more of the following is
specified:  window title, window drag gadget, window depth gadget, window
close gadget or window zoom gadget.  If none of these are specified, the
top border will be much narrower.

Application gadgets may be added to the window border by setting a flag in
the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  A special flag must additionally be set to place
gadgets into the borders of [GimmeZeroZero](libraries/4-window-types-gimmezerozero-window-type.md) windows.  See the chapter
"[Intuition Gadgets](libraries/5-gadget-size-and-position-positioning-gadgets-in-window.md)," for more information about gadgets and their
positioning.  ([Borderless](libraries/4-window-types-borderless-window-type.md) windows have no visible border outlines and
gadgets should not be placed in their borders.)

