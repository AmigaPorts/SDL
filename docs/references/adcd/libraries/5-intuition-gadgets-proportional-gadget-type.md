---
title: 5 Intuition Gadgets / Proportional Gadget Type
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-proportional-gadget-type
functions: []
libraries: []
---

# 5 Intuition Gadgets / Proportional Gadget Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Proportional gadgets allow an application to get or display an amount,
level, or position by moving a slidable [knob](libraries/5-proportional-gadget-components-the-knob.md) within a track.  They are
called proportional gadgets because the size and position of the knob is
proportional to some application-defined quantity, for example the size of
a page, and how much and which part of the page is currently visible.

An example of using proportional gadgets is available in the "Intuition
Windows" chapter.  The SuperBitMap window example, [lines.c](libraries/lib-examples-lines-c.md), uses
proportional gadgets to control the position of the bitmap within the
window.

Proportional gadgets are made up of a [container](libraries/5-proportional-gadget-components-the-container.md), which is the full size of
the gadget, and a [knob](libraries/5-proportional-gadget-components-the-knob.md), that travels within the container.  Changing the
current value of the gadget is done by dragging the knob, or clicking in
the container around the knob.  Dragging the knob performs a smooth
transition from one value to the next, while clicking in the container
jumps to the next page or setting.  The [KNOBHIT](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag in the [PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md)
structure is available to allow the program to determine if the gadget was
changed by dragging the knob or by clicking in the container.  If the flag
is set, the user changed the value by dragging the knob.

Proportional gadgets allow display and control of fractional settings on
the vertical axis, the horizontal axis or both.  While the number of
settings has a theoretical limit of 65,536 positions, the actual
positioning of the gadget through sliding the [knob](libraries/5-proportional-gadget-components-the-knob.md) is limited by the
resolution of the screen.  Further control is available by clicking in the
[container](libraries/5-proportional-gadget-components-the-container.md), although this often is not convenient for the user.  Button or
arrow gadgets are often provided for fine tuning of the setting of the
gadget.

 [New 3D Look Proportional Gadgets](libraries/5-proportional-gadget-type-new-3d-look-proportional-gadgets.md) 
 [Logical Types of Proportional Gadgets](libraries/5-proportional-gadget-type-logical-types-of-proportional.md) 
 [Proportional Gadget Components](libraries/5-proportional-gadget-type-proportional-gadget-components.md) 
 [Initialization of a Proportional Gadget](libraries/5-proportional-gadget-initialization-of-a-proportional.md) 
 [Modifying an Existing Proportional Gadget](libraries/5-proportional-gadget-type-modifying-an-existing-gadget.md) 

