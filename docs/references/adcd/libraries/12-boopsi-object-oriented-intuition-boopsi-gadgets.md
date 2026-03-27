---
title: 12 Boopsi--Object Oriented Intuition / Boopsi Gadgets
manual: libraries
chapter: libraries
section: 12-boopsi-object-oriented-intuition-boopsi-gadgets
functions: []
libraries: []
---

# 12 Boopsi--Object Oriented Intuition / Boopsi Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One of the major enhancements to Intuition for Release 2 is the
implementation of customizable Boopsi gadgets.  Boopsi gadgets are not
limited by dependencies upon Intuition [Image](libraries/8-creating-images-image-structure.md) and [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structures.
Unlike Release 1.3 gadgets, which were handled exclusively by Intuition,
Boopsi gadgets handle their own rendering and their own user input.

Since Boopsi gadgets draw themselves, there is almost no restriction on
what they can look like.  A Boopsi gadget can use graphics.library
[RastPort](libraries/27-drawing-routines-the-rastport-structure.md) drawing functions to draw vector-based imagery which the gadget
can scale to any dimension.  Instead of just a two-state Boolean gadget, a
Boopsi gadget can have any number of states, each of which has its own
imagery.  If a programmer wanted to he could even make a Boopsi gadget
that uses the animation system to render itself.

Because Boopsi gadgets handle their own input, they see all the user's
input, which the gadget is free to interpret.  While the user has a Boopsi
gadget selected, the gadget can track mouse moves, process mouse and
keyboard key presses, or watch the timer events.

The power of a Boopsi gadget is not limited to its ability to handle its
own rendering and user input.  Boopsi gadgets are also Boopsi objects so
the gain all the benefits Boopsi provides.  This means all Boopsi gadgets
inherit the methods and attributes from their superclasses.  Boopsi
gadgets can use Boopsi images to take care of rendering their imagery.  A
Boopsi gadget could be a "composite" gadget that is composed of several
Boopsi gadgets, images, and models.

 [The Boopsi Gadget Methods](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md)    [The Active Gadget](libraries/12-boopsi-gadgets-the-active-gadget.md) 

