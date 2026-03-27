---
title: 15 / / The Kinds of GadTools Gadgets / Scroller Gadgets
manual: libraries
chapter: libraries
section: 15-the-kinds-of-gadtools-gadgets-scroller-gadgets
functions: []
libraries: []
---

# 15 / / The Kinds of GadTools Gadgets / Scroller Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Scrollers (SCROLLER_KIND) bear some similarity to sliders, but are used
for a quite different job: they allow the user to adjust the position of a
limited view into a larger area.  For example, Workbench's windows have
scrollers that allow the user to see icons that are outside the visible
portion of a window.  Another example is a scrolling list in a file
requester which has a scroller that allows the user to see different parts
of the whole list.

A scroller consists of a proportional gadget and usually also has a pair
of arrow buttons.

While the slider deals in minimum, maximum and current level, the scroller
understands Total, Visible and Top.  For a scrolling list, Total would be
the number of items in the entire list, Visible would be the number of
lines visible in the display area and Top would be the number of the first
line displayed in the visible part of the list.  Top would run from zero
to Total - Visible.  For an area-scroller such as those in Workbench's
windows, Total would be the height (or width) of the whole area, Visible
would be the visible height (or width) and Top would be the top (or left)
edge of the visible part.

Note that the position of a scroller should always represent the position
of the visible part of the project and never the position of a cursor or
insertion point.

Scrollers respect the following tags:

GTSC_Top (WORD)

```c
    The top line or position visible in the area that the scroller
    represents.  The default is zero.  (Create and set.)
```
GTSC_Total (WORD)

```c
    The total number of lines or positions that the scroller represents.
    The default is zero.  (Create and set.)
```
GTSC_Visible (WORD)

```c
    The visible number of lines or positions that the scroller
    represents.  The default is two.  (Create and set.)
```
GTSC_Arrows (UWORD)

```c
    Asks for arrow gadgets to be attached to the scroller.  The value
    supplied will be used as the width of each arrow button for a
    horizontal scroller or the height of each arrow button for a vertical
    scroller, the other dimension will be set by GadTools to match the
    scroller size.  It is generally recommend that arrows be provided.
    The default is no arrows.  (Create only.)
```
GA_Immediate (BOOL)

```c
    Set this to TRUE to receive an [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) when the
    user presses the mouse button over the scroller.  The default is
    FALSE.  (Create only.)
```
GA_RelVerify (BOOL)

```c
    Set this to TRUE to receive an [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md) [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md) when the
    user releases the mouse button after using the scroller.  The default
    is FALSE.  (Create only.)
```
PGA_Freedom

```c
    Specifies which direction the knob may move.  Set to LORIENT_VERT for
    a vertical scroller or LORIENT_HORIZ for a horizontal scroller.  The
    default is LORIENT_HORIZ.  (Create only.)
```
GA_Disabled (BOOL)

```c
    Set this attribute to TRUE to disable the scroller, to FALSE
    otherwise.  The default is FALSE.  (Create and set.)
```
The [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)s received for a scroller gadget are the same in nature as
those for a slider defined above, including the fact that messages are
only heard by the program when the knob moves far enough for the Top value
to actually change. The [Code](libraries/9-using-the-idcmp-intuimessages.md) field of the IntuiMessage will contain the
new Top value of the scroller.

If the user clicks on an arrow gadget, the scroller moves by one unit.  If
the user holds the button down over an arrow gadget, it repeats.

If the user clicks in the container next to the knob, the scroller will
move by one page, which is the visible amount less one.  This means that
when the user pages through a scrolling list, any pair of successive views
will overlap by one line.  This helps the user understand the continuity
of the list.  If the program is using a scroller to pan through an area
then there will be an overlap of one unit between successive views.  It is
recommended that Top, Visible and Total be scaled so that one unit
represents about five to ten percent of the visible amount.

