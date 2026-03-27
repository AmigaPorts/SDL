# 15 GadTools Library / GadTools Gadgets


The heart of GadTools is in its ability to easily create and manipulate a
sophisticated and varied array of gadgets.  GadTools supports the
following kinds of gadgets:


  Table 15-1: Standard Gadget Types Supported by the GadTools Library



    Gadget Type         Description or Example Usage
    -----------         ----------------------------
    Button              Familiar action gadgets, such as "OK" or "Cancel".
    String              For text entry.
    Integer             For numeric entry.
    Checkboxes          For on/off items.
    Mutually exclusive  Radio buttons, select one choice among several.
    Cycle               Multiple-choice, pick one of a small number of
                        choices.
    Sliders             To indicate a level within a range.
    Scrollers           To indicate a position in a list or area.
    Listviews           Scrolling lists of text.
    Palette             Color selection.
    Text-display        Read-only text.
    Numeric-display     Read-only numbers.
GadTools gadget handling consists of a body of routines to create, manage
and delete any of the 12 kinds of standard gadgets listed in table 15-1,
such as buttons, sliders, mutually exclusive buttons and scrolling lists.

To illustrate the flexibility, power and simplicity that GadTools offers,
consider the GadTools slider gadget.  This gadget is used to indicate and
control the level of something, for example volume, speed or color
intensity.  Without GadTools, applications have to deal directly with
Intuition proportional and their arcane variables, such as [HorizBody](../Libraries_Manual_guide/node015C.html) to
control the slider knob's size and [HorizPot](../Libraries_Manual_guide/node015B.html) to control the knob's
position.  Using the GadTools slider allows direct specification of the
minimum and maximum levels of the slider, as well as its current level.
For example, a color slider might have a minimum level of 0, a maximum
level of 15 and a current level of 11.

To simplify event-processing for the slider, GadTools only sends the
application a message when the knob has moved far enough to cause the
slider level, as expressed in application terms, to change.  If a user
were to slowly drag the knob of this color slider all the way to the
right, the program will only hear messages for levels 12, 13, 14 and 15,
with an optional additional message when the user releases the
mouse-button.

Changing the current level of the slider from within the program is as
simple as specifying the new level in a function call.  For instance, the
application might set the slider's value to 5.

As a final point, the slider is very well-behaved.  When the user releases
the mouse-button, the slider immediately snaps to the centered position
for the level.  If a user sets their background color to light gray, which
might have red = green = blue = 10, all three color sliders will have
their knobs at precisely the same relative position, instead of anywhere
in the range that means "ten".

 [The NewGadget Structure](../Libraries_Manual_guide/node0259.html) 
 [Creating Gadgets](../Libraries_Manual_guide/node025A.html) 
 [Handling Gadget Messages](../Libraries_Manual_guide/node025B.html) 
 [IDCMP Flags](../Libraries_Manual_guide/node025C.html) 
 [Freeing Gadgets](../Libraries_Manual_guide/node025D.html) 
 [Simple GadTools Gadget Example](../Libraries_Manual_guide/node0599.html) 
 [Modifying Gadgets](../Libraries_Manual_guide/node025E.html) 
 [The Kinds of GadTools Gadgets](../Libraries_Manual_guide/node025F.html) 
 [Functions for Setting Up GadTools Menus and Gadgets](../Libraries_Manual_guide/node026B.html) 
 [Creating Gadget Lists](../Libraries_Manual_guide/node026E.html) 
 [Gadget Refresh Functions](../Libraries_Manual_guide/node026F.html) 
 [Other GadTools Functions](../Libraries_Manual_guide/node0270.html) 
 [Gadget Keyboard Equivalents](../Libraries_Manual_guide/node0273.html) 
 [Complete GadTools Gadget Example](../Libraries_Manual_guide/node0598.html) 
 [Restrictions on GadTools Gadgets](../Libraries_Manual_guide/node0276.html) 
 [Documented Side-Effects](../Libraries_Manual_guide/node0277.html) 

