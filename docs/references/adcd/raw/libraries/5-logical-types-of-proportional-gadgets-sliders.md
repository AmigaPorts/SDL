# 5 / / Logical Types of Proportional Gadgets / Sliders


The slider is used to pick a specific value within a set.  Usually the set
is ordered, but this is not required.  An example of this would be
choosing the volume of a sound, the speed of an animation or the
brightness of a color.  Sliders can move on either the vertical or
horizontal axis.  A slider that moves on both the horizontal and the
vertical axis could be created to choose two values at once.

An example slider which picks an integer between one and ten, should have
the following attributes:

  * It should slide on only one axis.

  * Values should be evenly distributed over the length of the slider.

  * Clicking in the [container](../Libraries_Manual_guide/node0159.html) to either side of the [knob](../Libraries_Manual_guide/node015A.html) should increase

```c
    (or decrease) the value by one unit.
```
Stylistically, sliding the [knob](../Libraries_Manual_guide/node015A.html) to the right or top should increase the
value, while sliding it to the left or down should decrease the value.
Note that the orientation of [proportional](../Libraries_Manual_guide/node0153.html) gadgets is correct for [scrollers](../Libraries_Manual_guide/node0156.html)
(where the minimum value is topmost or leftmost), but is vertically
inverted for sliders.  Thus, well-behaved vertical sliders need to invert
their value somewhere in the calculations (or else the maximum will end up
at the bottom).

