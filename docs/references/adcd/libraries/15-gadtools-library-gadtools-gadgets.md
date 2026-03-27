---
title: 15 GadTools Library / GadTools Gadgets
manual: libraries
chapter: libraries
section: 15-gadtools-library-gadtools-gadgets
functions: []
libraries: []
---

# 15 GadTools Library / GadTools Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
Intuition proportional and their arcane variables, such as [HorizBody](libraries/5-proportional-gadget-components-the-body-variables.md) to
control the slider knob's size and [HorizPot](libraries/5-proportional-gadget-components-the-pot-variables.md) to control the knob's
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

 [The NewGadget Structure](libraries/15-gadtools-gadgets-the-newgadget-structure.md) 
 [Creating Gadgets](libraries/15-gadtools-gadgets-creating-gadgets.md) 
 [Handling Gadget Messages](libraries/15-gadtools-gadgets-handling-gadget-messages.md) 
 [IDCMP Flags](libraries/15-gadtools-gadgets-idcmp-flags.md) 
 [Freeing Gadgets](libraries/15-gadtools-gadgets-freeing-gadgets.md) 
 [Simple GadTools Gadget Example](libraries/lib-examples-simplegtgadget-c.md) 
 [Modifying Gadgets](libraries/15-gadtools-gadgets-modifying-gadgets.md) 
 [The Kinds of GadTools Gadgets](libraries/15-gadtools-gadgets-the-kinds-of-gadtools-gadgets.md) 
 [Functions for Setting Up GadTools Menus and Gadgets](libraries/15-gadtools-functions-for-setting-up-gadtools-menus-and.md) 
 [Creating Gadget Lists](libraries/15-gadtools-gadgets-creating-gadget-lists.md) 
 [Gadget Refresh Functions](libraries/15-gadtools-gadgets-gadget-refresh-functions.md) 
 [Other GadTools Functions](libraries/15-gadtools-gadgets-other-gadtools-functions.md) 
 [Gadget Keyboard Equivalents](libraries/15-gadtools-gadgets-gadget-keyboard-equivalents.md) 
 [Complete GadTools Gadget Example](libraries/lib-examples-gadtoolsgadgets-c.md) 
 [Restrictions on GadTools Gadgets](libraries/15-gadtools-gadgets-restrictions-on-gadtools-gadgets.md) 
 [Documented Side-Effects](libraries/15-gadtools-gadgets-documented-side-effects.md) 

