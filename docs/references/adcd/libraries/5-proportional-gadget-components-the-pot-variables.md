---
title: 5 / / Proportional Gadget Components / The Pot Variables
manual: libraries
chapter: libraries
section: 5-proportional-gadget-components-the-pot-variables
functions: []
libraries: []
---

# 5 / / Proportional Gadget Components / The Pot Variables

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The HorizPot and VertPot variables contain the actual proportional values
entered into or displayed by the gadget. The word pot is short for
potentiometer, which is an electrical analog device used to adjust a value
within a continuous range.

The [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget pots allow the program to set the current position
of the [knob](libraries/5-proportional-gadget-components-the-knob.md) within the [container](libraries/5-proportional-gadget-components-the-container.md), or to read the knob's current location.

The pot variable is a 16-bit, unsigned variable that contains a value
ranging from zero to 0xFFFF. For clarity, the constant MAXPOT is
available, which is equivalent to 0xFFFF. A similar constant [MAXBODY](libraries/5-proportional-gadget-components-the-body-variables.md) is
available for the [body variables](libraries/5-proportional-gadget-components-the-body-variables.md). As the pot variables are only 16 bits,
the resolution of the [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets has a maximum of 65,536
positions (zero to 65,535).

The values represented in the pot variables are usually translated or
converted to a range of numbers more useful to the application.  For
instance, if a [slider](libraries/5-logical-types-of-proportional-gadgets-sliders.md) covered the range one to three, pot values of zero
to 16,383 would represent one, values of 16,384 to 49,151 would represent
two and values of 49,152 to 65,535 would represent three.  The method of
deriving these numbers is fairly complex, refer to the [sample code](libraries/5-proportional-gadget-components-functions-for-using-a.md) below
for more information.

There are two pot variables, as [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets are adjustable on the
horizontal axis, the vertical axis or both.  The two pot variables are
independent and may be initialized to any 16-bit, unsigned value.

Pot values change while the user is manipulating the gadget.  The program
may read the values in the pots at any time after it has submitted the
gadget to the user via Intuition.  The values always have the current
settings as adjusted by the user.

