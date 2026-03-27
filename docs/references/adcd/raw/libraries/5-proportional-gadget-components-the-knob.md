# 5 / / Proportional Gadget Components / The Knob


The knob may be manipulated by the user to quickly change the
[pot variables](../Libraries_Manual_guide/node015B.html).  The knob acts like a real-world proportional control.  For
instance, a knob restricted to movement on a single axis can be thought of
as a control such as the volume knob on a radio.  A knob that moves on
both axes is analogous to the control stick of an airplane.

The user can directly move the knob by dragging it on the vertical or
horizontal axis.  The knob may be indirectly moved by clicking within the
select box around the knob.  With each click, the [pot variable](../Libraries_Manual_guide/node015B.html) is
increased or decreased by one increment, defined by the settings of the
[body variables](../Libraries_Manual_guide/node015C.html).

The current position of the knob reflects the [pot value](../Libraries_Manual_guide/node015D.html). A pot value of
zero will place the knob in the top or leftmost position, a value of
[MAXPOT](../Libraries_Manual_guide/node015B.html#line8) will place the knob at the bottom or rightmost position.

The application can provide its own imagery for the knob or it may use
Intuition's auto-knob.  The auto-knob is a rectangle that changes its
width and height according to the current [body](../Libraries_Manual_guide/node015C.html) settings.  The auto-knob is
proportional to the size of the gadget.  Therefore, an auto-knob can be
used in a [proportional](../Libraries_Manual_guide/node0153.html) gadget whose size is relative to the size of the
window, and the knob will maintain the correct size, relative to the size
of the [container](../Libraries_Manual_guide/node0159.html).


```c
    Use Separate Imagery for Proportional Gadgets.
    ----------------------------------------------
    These [Image](../Libraries_Manual_guide/node01BA.html) structures may not be shared between [proportional](../Libraries_Manual_guide/node0153.html)
    gadgets, each must have its own. Again, do not share the Image
    structures between proportional gadgets. This does not work, either
    for auto-knob or custom imagery.

    Use Only One Image for the Knob.
    --------------------------------
    [Proportional](../Libraries_Manual_guide/node0153.html) gadget knob images may not be a list of images.  These
    must be a single image, initialized and ready to display if a custom
    image is used for the knob.
```
