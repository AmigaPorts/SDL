# 12 / / The Active Gadget / RKMButtonclass.c


The following example is a sample Boopsi gadget, RKMButClass.c.  While the
user has the RKMButton selected, the gadget sends an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message to
its [ICA_TARGET](../Libraries_Manual_guide/node020B.html#line20) for every timer event the button sees.  The gadget sends
notification about its RKMBUT_Pulse attribute, which is the horizontal
distance in screen pixels the mouse is from the center of the button.  The
gadget takes care of rendering all of its imagery (as opposed to using a
Boopsi image to do it).  The gadget's imagery is scalable to any
dimensions and can be set (using [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5)) while the gadget is in
place.

One possible use for such a gadget is as buttons for a prop gadget. If the
user has the prop gadget's RKMButton selected, while the mouse is to the
left of the button's center, the knob on the prop gadget moves left.
While the mouse is to the right of the button's center, the knob on the
prop gadget moves right.  The speed at which the knob moves is
proportional to the horizontal distance from the mouse to the active
RKMButton.


```c
     [RKMButClass.c](../Libraries_Manual_guide/node0580.html) 
```
