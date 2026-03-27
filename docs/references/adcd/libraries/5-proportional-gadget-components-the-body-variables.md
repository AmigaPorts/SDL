---
title: 5 / / Proportional Gadget Components / The Body Variables
manual: libraries
chapter: libraries
section: 5-proportional-gadget-components-the-body-variables
functions: []
libraries: []
---

# 5 / / Proportional Gadget Components / The Body Variables

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The HorizBody and VertBody variables describe the standard increment by
which the [pot variables](libraries/5-proportional-gadget-components-the-pot-variables.md) change and the relative size of the [knob](libraries/5-proportional-gadget-components-the-knob.md) when
[auto-knob](libraries/5-proportional-gadget-components-the-knob.md) is used.  The increment, or typical step value, is the value
added to or subtracted from the internal knob position when the user clicks
in the [container](libraries/5-proportional-gadget-components-the-container.md) around the knob.  For example, a [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget for
color mixing might allow the user to add or subtract 1/16 of the full value
each time, thus the body variable should be set to MAXBODY / 16.

Body variables are also used in conjunction with the [auto-knob](libraries/5-proportional-gadget-components-the-knob.md) (described
above) to display for the user how much of the total quantity of data is
displayed.  Additionally, the user can tell at a glance that clicking in
the [container](libraries/5-proportional-gadget-components-the-container.md) around the [knob](libraries/5-proportional-gadget-components-the-knob.md) will advance the position by an amount
proportional to the size of the knob.

For instance, if the data is a fifteen line text file, and five lines are
visible in the display, then the body variable should be set to one third
of MAXBODY.  In this case, the [auto-knob](libraries/5-proportional-gadget-components-the-knob.md) will fill one third of the
[container](libraries/5-proportional-gadget-components-the-container.md), and clicking in the container ahead of the [knob](libraries/5-proportional-gadget-components-the-knob.md) will advance
the position in the file by one third.

For a [slider](libraries/5-logical-types-of-proportional-gadgets-sliders.md), the body variables are usually set such that the full
percentage increment is represented.  This is not always so for a
[scroller](libraries/5-logical-types-of-proportional-gadgets-scrollers.md).  With a scroller, some overlap is often desired between
successive steps.  For example, when paging through a text editor, one or
two lines are often left on screen from the previous page, making the
transition easier on the user.

The two body variables may be set to the same or different increments.
When the user clicks in the [container](libraries/5-proportional-gadget-components-the-container.md), the [pot variables](libraries/5-proportional-gadget-components-the-pot-variables.md) are adjusted by
an amount derived from the body variables.

