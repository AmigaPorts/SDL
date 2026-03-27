---
title: 12 / / The Active Gadget / RKMButtonclass.c
manual: libraries
chapter: libraries
section: 12-the-active-gadget-rkmbuttonclass-c
functions: []
libraries: []
---

# 12 / / The Active Gadget / RKMButtonclass.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following example is a sample Boopsi gadget, RKMButClass.c.  While the
user has the RKMButton selected, the gadget sends an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message to
its [ICA_TARGET](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md) for every timer event the button sees.  The gadget sends
notification about its RKMBUT_Pulse attribute, which is the horizontal
distance in screen pixels the mouse is from the center of the button.  The
gadget takes care of rendering all of its imagery (as opposed to using a
Boopsi image to do it).  The gadget's imagery is scalable to any
dimensions and can be set (using [SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md)) while the gadget is in
place.

One possible use for such a gadget is as buttons for a prop gadget. If the
user has the prop gadget's RKMButton selected, while the mouse is to the
left of the button's center, the knob on the prop gadget moves left.
While the mouse is to the right of the button's center, the knob on the
prop gadget moves right.  The speed at which the knob moves is
proportional to the horizontal distance from the mouse to the active
RKMButton.


```c
     [RKMButClass.c](libraries/lib-examples-rkmbutclass-c.md) 
```
