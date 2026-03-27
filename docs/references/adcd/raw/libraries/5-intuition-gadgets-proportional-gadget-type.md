# 5 Intuition Gadgets / Proportional Gadget Type


Proportional gadgets allow an application to get or display an amount,
level, or position by moving a slidable [knob](../Libraries_Manual_guide/node015A.html) within a track.  They are
called proportional gadgets because the size and position of the knob is
proportional to some application-defined quantity, for example the size of
a page, and how much and which part of the page is currently visible.

An example of using proportional gadgets is available in the "Intuition
Windows" chapter.  The SuperBitMap window example, [lines.c](../Libraries_Manual_guide/node05BD.html), uses
proportional gadgets to control the position of the bitmap within the
window.

Proportional gadgets are made up of a [container](../Libraries_Manual_guide/node0159.html), which is the full size of
the gadget, and a [knob](../Libraries_Manual_guide/node015A.html), that travels within the container.  Changing the
current value of the gadget is done by dragging the knob, or clicking in
the container around the knob.  Dragging the knob performs a smooth
transition from one value to the next, while clicking in the container
jumps to the next page or setting.  The [KNOBHIT](../Libraries_Manual_guide/node0161.html#line37) flag in the [PropInfo](../Libraries_Manual_guide/node0161.html)
structure is available to allow the program to determine if the gadget was
changed by dragging the knob or by clicking in the container.  If the flag
is set, the user changed the value by dragging the knob.

Proportional gadgets allow display and control of fractional settings on
the vertical axis, the horizontal axis or both.  While the number of
settings has a theoretical limit of 65,536 positions, the actual
positioning of the gadget through sliding the [knob](../Libraries_Manual_guide/node015A.html) is limited by the
resolution of the screen.  Further control is available by clicking in the
[container](../Libraries_Manual_guide/node0159.html), although this often is not convenient for the user.  Button or
arrow gadgets are often provided for fine tuning of the setting of the
gadget.

 [New 3D Look Proportional Gadgets](../Libraries_Manual_guide/node0154.html) 
 [Logical Types of Proportional Gadgets](../Libraries_Manual_guide/node0155.html) 
 [Proportional Gadget Components](../Libraries_Manual_guide/node0158.html) 
 [Initialization of a Proportional Gadget](../Libraries_Manual_guide/node0160.html) 
 [Modifying an Existing Proportional Gadget](../Libraries_Manual_guide/node0163.html) 

