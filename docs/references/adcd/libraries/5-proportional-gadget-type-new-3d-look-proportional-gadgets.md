---
title: 5 / Proportional Gadget Type / New 3D Look Proportional Gadgets
manual: libraries
chapter: libraries
section: 5-proportional-gadget-type-new-3d-look-proportional-gadgets
functions: []
libraries: []
---

# 5 / Proportional Gadget Type / New 3D Look Proportional Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Set the [PROPNEWLOOK](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag in the [PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) [Flags](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) field to get the new 3D
look.  The new 3D look [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets have a dithered pattern in the
[container](libraries/5-proportional-gadget-components-the-container.md) and updated [knob](libraries/5-proportional-gadget-components-the-knob.md) imagery.  The knob dimensions are also slightly
changed for those proportional gadgets with a border.

Set the [PROPBORDERLESS](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag in the [PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) Flags field if no border
around the [container](libraries/5-proportional-gadget-components-the-container.md) is desired.  Setting this flag with [PROPNEWLOOK](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) will
provide a 3D [knob](libraries/5-proportional-gadget-components-the-knob.md).


```c
    Proportional gadgets and the New 3D Look.
    -----------------------------------------
    To create prop gadgets that have the same look as the rest of the
    system, set the [PROPNEWLOOK](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag and clear the [PROPBORDERLESS](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag.
    It is recommended that applications follow this guideline to maintain
    a compatible look and feel for all gadgets in the system.
```
New look [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets placed in the border of a window will change
to an inactive display state when the window is deactivated.  This only
happens to gadgets that have the [PROPNEWLOOK](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag set and are in the
window border.  In the inactive state, the [knob](libraries/5-proportional-gadget-components-the-knob.md) is filled with
[BACKGROUNDPEN](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md).

