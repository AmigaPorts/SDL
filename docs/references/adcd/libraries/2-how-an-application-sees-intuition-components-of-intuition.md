---
title: 2 / How an Application Sees Intuition / Components of Intuition
manual: libraries
chapter: libraries
section: 2-how-an-application-sees-intuition-components-of-intuition
functions: []
libraries: []
---

# 2 / How an Application Sees Intuition / Components of Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The types of data objects that the Intuition library functions create and
control fall into six broad categories.  These are the main components an
application uses to build and operate a graphic user interface on the
Amiga.

```c
                Table 2-2: [GUI](libraries/2-user-interfaces-elements-of-the-graphical-user-interface.md) Components of Intuition
```
  ____________________________________________________________________
 |                                                                    |
 |  [Screens](libraries/2-how-an-application-sees-intuition-screens-and-windows.md)       The display environment. Sets the resolution and    |
 |                number of colors.                                   |
 |                                                                    |
 |  [Windows](libraries/2-how-an-application-sees-intuition-screens-and-windows.md)       A graphic rectangle within a screen representing a  |
 |                working context.                                    |
 |                                                                    |
 |  [Menus](libraries/2-gadgets-menus-and-requesters-menus.md)         A list of choices displayed at the top of a screen  |
 |                that can be selected with the mouse.                |
 |                                                                    |
 |  [Gadgets](libraries/2-gadgets-menus-and-requesters-gadgets.md)       A control symbolized by a graphic image that can be |
 |                operated with the mouse or keyboard.                |
 |                                                                    |
 |  [Requesters](libraries/2-gadgets-menus-and-requesters-requesters.md)    Sub-windows for confirming actions, accessing files |
 |                and other special options.                          |
 |                                                                    |
 |  [Input events](libraries/2-gadgets-menus-and-requesters-the-intuition-input-event.md)  Mouse, keyboard or other input activity.            |
 |____________________________________________________________________|

