# 5 / Proportional Gadget Type / New 3D Look Proportional Gadgets


Set the [PROPNEWLOOK](../Libraries_Manual_guide/node0161.html#line32) flag in the [PropInfo](../Libraries_Manual_guide/node0161.html) [Flags](../Libraries_Manual_guide/node0161.html#line16) field to get the new 3D
look.  The new 3D look [proportional](../Libraries_Manual_guide/node0153.html) gadgets have a dithered pattern in the
[container](../Libraries_Manual_guide/node0159.html) and updated [knob](../Libraries_Manual_guide/node015A.html) imagery.  The knob dimensions are also slightly
changed for those proportional gadgets with a border.

Set the [PROPBORDERLESS](../Libraries_Manual_guide/node0161.html#line19) flag in the [PropInfo](../Libraries_Manual_guide/node0161.html) Flags field if no border
around the [container](../Libraries_Manual_guide/node0159.html) is desired.  Setting this flag with [PROPNEWLOOK](../Libraries_Manual_guide/node0161.html#line32) will
provide a 3D [knob](../Libraries_Manual_guide/node015A.html).


```c
    Proportional gadgets and the New 3D Look.
    -----------------------------------------
    To create prop gadgets that have the same look as the rest of the
    system, set the [PROPNEWLOOK](../Libraries_Manual_guide/node0161.html#line32) flag and clear the [PROPBORDERLESS](../Libraries_Manual_guide/node0161.html#line19) flag.
    It is recommended that applications follow this guideline to maintain
    a compatible look and feel for all gadgets in the system.
```
New look [proportional](../Libraries_Manual_guide/node0153.html) gadgets placed in the border of a window will change
to an inactive display state when the window is deactivated.  This only
happens to gadgets that have the [PROPNEWLOOK](../Libraries_Manual_guide/node0161.html#line32) flag set and are in the
window border.  In the inactive state, the [knob](../Libraries_Manual_guide/node015A.html) is filled with
[BACKGROUNDPEN](../Libraries_Manual_guide/node00EC.html#line88).

