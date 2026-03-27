# 2 / How an Application Sees Intuition / Components of Intuition


The types of data objects that the Intuition library functions create and
control fall into six broad categories.  These are the main components an
application uses to build and operate a graphic user interface on the
Amiga.

```c
                Table 2-2: [GUI](../Libraries_Manual_guide/node00C8.html) Components of Intuition
```
  ____________________________________________________________________
 |                                                                    |
 |  [Screens](../Libraries_Manual_guide/node00CF.html)       The display environment. Sets the resolution and    |
 |                number of colors.                                   |
 |                                                                    |
 |  [Windows](../Libraries_Manual_guide/node00CF.html)       A graphic rectangle within a screen representing a  |
 |                working context.                                    |
 |                                                                    |
 |  [Menus](../Libraries_Manual_guide/node00D2.html)         A list of choices displayed at the top of a screen  |
 |                that can be selected with the mouse.                |
 |                                                                    |
 |  [Gadgets](../Libraries_Manual_guide/node00D1.html)       A control symbolized by a graphic image that can be |
 |                operated with the mouse or keyboard.                |
 |                                                                    |
 |  [Requesters](../Libraries_Manual_guide/node00D3.html)    Sub-windows for confirming actions, accessing files |
 |                and other special options.                          |
 |                                                                    |
 |  [Input events](../Libraries_Manual_guide/node00D4.html)  Mouse, keyboard or other input activity.            |
 |____________________________________________________________________|

