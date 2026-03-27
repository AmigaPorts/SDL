---
title: 5 / / Proportional Gadget Components / The Knob
manual: libraries
chapter: libraries
section: 5-proportional-gadget-components-the-knob
functions: []
libraries: []
---

# 5 / / Proportional Gadget Components / The Knob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The knob may be manipulated by the user to quickly change the
[pot variables](libraries/5-proportional-gadget-components-the-pot-variables.md).  The knob acts like a real-world proportional control.  For
instance, a knob restricted to movement on a single axis can be thought of
as a control such as the volume knob on a radio.  A knob that moves on
both axes is analogous to the control stick of an airplane.

The user can directly move the knob by dragging it on the vertical or
horizontal axis.  The knob may be indirectly moved by clicking within the
select box around the knob.  With each click, the [pot variable](libraries/5-proportional-gadget-components-the-pot-variables.md) is
increased or decreased by one increment, defined by the settings of the
[body variables](libraries/5-proportional-gadget-components-the-body-variables.md).

The current position of the knob reflects the [pot value](libraries/5-proportional-gadget-components-using-the-body-and-pot.md). A pot value of
zero will place the knob in the top or leftmost position, a value of
[MAXPOT](libraries/5-proportional-gadget-components-the-pot-variables.md) will place the knob at the bottom or rightmost position.

The application can provide its own imagery for the knob or it may use
Intuition's auto-knob.  The auto-knob is a rectangle that changes its
width and height according to the current [body](libraries/5-proportional-gadget-components-the-body-variables.md) settings.  The auto-knob is
proportional to the size of the gadget.  Therefore, an auto-knob can be
used in a [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget whose size is relative to the size of the
window, and the knob will maintain the correct size, relative to the size
of the [container](libraries/5-proportional-gadget-components-the-container.md).


```c
    Use Separate Imagery for Proportional Gadgets.
    ----------------------------------------------
    These [Image](libraries/8-creating-images-image-structure.md) structures may not be shared between [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md)
    gadgets, each must have its own. Again, do not share the Image
    structures between proportional gadgets. This does not work, either
    for auto-knob or custom imagery.

    Use Only One Image for the Knob.
    --------------------------------
    [Proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget knob images may not be a list of images.  These
    must be a single image, initialized and ready to display if a custom
    image is used for the knob.
```
