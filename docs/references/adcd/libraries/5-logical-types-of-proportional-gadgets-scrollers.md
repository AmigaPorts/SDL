---
title: 5 / / Logical Types of Proportional Gadgets / Scrollers
manual: libraries
chapter: libraries
section: 5-logical-types-of-proportional-gadgets-scrollers
functions: []
libraries: []
---

# 5 / / Logical Types of Proportional Gadgets / Scrollers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The scroller controls and represents a limited window used to display a
large amount of data.  For instance, a text editor may be operating on a
file with hundreds of lines, but is only capable of displaying twenty or
thirty lines at a time.

In a scroller, the [container](libraries/5-proportional-gadget-components-the-container.md) of the gadget is analogous to the total
amount of data, while the [knob](libraries/5-proportional-gadget-components-the-knob.md) represents the window.  (Note that window
here is used as an abstract concept and does not necessarily mean
Intuition window.  It just means a display area reserved for viewing the
data.)

The size of the [knob](libraries/5-proportional-gadget-components-the-knob.md) with respect to its [container](libraries/5-proportional-gadget-components-the-container.md) is proportional to the
size of the window with respect to the total data.  Thus, if the window
can display half the data, the knob should be half the size of the
container.  When the amount of data is smaller than the window size, the
knob should be as large as its container.

The position of the [knob](libraries/5-proportional-gadget-components-the-knob.md) with respect to its [container](libraries/5-proportional-gadget-components-the-container.md) is also
proportional to the position of the window with respect to the total data.
Thus, if the knob starts half way down the container, the top of the
window should display information half way into the data.

Scrollers may be one or two dimensional.  One dimensional scrollers are
used to control linear data; such as a text file, which can be viewed as a
linear array of strings.  Such scrollers only slide on a single axis.

Two dimensional scrollers are used to control two dimensional data, such
as a large graphic image.  Such a scroller can slide on both the
horizontal and vertical axes, and the [knob](libraries/5-proportional-gadget-components-the-knob.md)'s horizontal and vertical size
and position should be proportional to the window's size and position in
the data set.

Multi-dimensional data may also be controlled by a number of one
dimensional scrollers, one for each axis.  The Workbench windows provide
an example of this, where one scroller is used for control of the x-axis
of the window and another scroller is used for control of the y-axis of
the window.  In this case, the size and position of the [knob](libraries/5-proportional-gadget-components-the-knob.md) is
proportional to the size and position of the axis represented by the
gadget.

If the window has a sizing gadget and has a [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget is the
right or bottom border, the sizing gadget is usually placed into the
border containing the proportional gadget, as the border has already been
expanded to contain the gadget.  If the window has proportional gadgets in
both the right and the bottom borders, place the sizing gadget into both
borders.  This creates evenly sized borders that match the height and
width of the sizing gadget, i.e. it is only done for visual effect.

