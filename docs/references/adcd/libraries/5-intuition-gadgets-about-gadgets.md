---
title: 5 Intuition Gadgets / About Gadgets
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-about-gadgets
functions: []
libraries: []
---

# 5 Intuition Gadgets / About Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two kinds of gadgets: system gadgets and application gadgets.
System gadgets are set up by Intuition to handle the positioning and depth
arranging of screens, and to handle the positioning, sizing, closing and
depth arranging of windows.  System gadgets always use the same imagery
and location giving the windows and screens of any application a basic set
of controls that are familiar and easy to operate.  In general,
applications do not have to do any processing for system gadgets;
Intuition does all the work.

Application gadgets are set up by an application program.  These may be
the basic gadget types described in this chapter, the pre-fabricated
gadgets supplied by the GadTools library, or special gadget types defined
through Intuition's [custom](libraries/5-string-gadget-type-custom-gadgets.md) gadget and BOOPSI facilities.  Application
gadgets can be placed anywhere within a window and can use just about any
image.  The action associated with an application gadget is carried out by
the application.

There are four basic types of application gadgets:

  * [Boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) (or button) gadgets elicit true/false or yes/no kinds of

    answers from the user.
  * [Proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadgets allow the user to select from a continuous range

    of options, such as volume or speed.
  * [String](libraries/5-intuition-gadgets-string-gadget-type.md) gadgets are used to get or display character based information

```c
    (a special class of string gadget allows entry of numeric data.)
```
  * [Custom](libraries/5-string-gadget-type-custom-gadgets.md) gadgets, a new, generalized form of gadget, provide

    flexibility to perform any type of function.
The way a gadget is used varies according to the type of gadget.  For a
[boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget, the user operates the gadget by simply clicking the mouse
select button.  For a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget, a cursor appears, allowing the user
to enter data from the keyboard.  For a [proportional](libraries/5-intuition-gadgets-proportional-gadget-type.md) gadget, the user can
either drag the [knob](libraries/5-proportional-gadget-components-the-knob.md) with the mouse or click in the gadget [container](libraries/5-proportional-gadget-components-the-container.md) to
move the knob by a set increment.

Gadgets are chosen by positioning the pointer within an area called the
select box, which is application defined, and pressing the mouse select
button (left mouse button).

When a gadget is selected, its imagery is changed to indicate that it is
activated.  The highlighting method for the gadget may be set by the
application.  Highlighting methods include alternate image, alternate
border, a box around the gadget and color complementing.


```c
     [Figure 5-1: System and Application Gadgets](libraries/lib-pics-5-1-pic.md) 
```
A gadget can be either enabled or disabled.  Disabled gadgets cannot be
operated and are indicated by ghosting the gadget, that is, overlaying its
image with a pattern of dots.  Gadgets may also be directly modified and
redrawn by first removing the gadget from the system.

 [System Gadgets](libraries/5-about-gadgets-system-gadgets.md)         [Adding and Removing Gadgets](libraries/5-about-gadgets-adding-and-removing-gadgets.md) 
 [Application Gadgets](libraries/5-about-gadgets-application-gadgets.md) 

