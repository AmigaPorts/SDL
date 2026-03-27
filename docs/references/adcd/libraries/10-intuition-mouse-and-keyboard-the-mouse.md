---
title: 10 Intuition Mouse and Keyboard / The Mouse
manual: libraries
chapter: libraries
section: 10-intuition-mouse-and-keyboard-the-mouse
functions: []
libraries: []
---

# 10 Intuition Mouse and Keyboard / The Mouse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga mouse is a small, hand-held input device connected to the Amiga
by a flexible cable.  The user can input horizontal and vertical
coordinates with the mouse by sliding it around on a smooth surface.  This
movement causes the repositioning of a pointer on the display; whenever
the mouse is moved the pointer moves, and in the same direction.

The mouse also provides two or three input keys, called mouse buttons,
that allow the user to input information to the computer.  The basic
activities the user can perform with the mouse are shown below.




```c
                 Action                Explanation
                 ------                -----------
            Moving the Mouse  Sliding the body of the mouse over a
                              surface, such as a desk top.

           Pressing a button  Pushing down a mouse button (which is
                              released at some later time).

           Clicking a button  Quickly pressing and releasing a mouse
                              button.

    Double clicking a button  Clicking a button twice in a short
                              period of time.

                    Dragging  Pressing a button and moving the mouse
                              while the button is held down.  The
                              drag operation is completed by
                              releasing the button.


                  Table 10-1: Mouse Activities
```
The action associated with mouse button presses can occur when the button
is first pressed, or while the button is held down, or when the button is
released.  As an example of this, consider the drag gadget of a window.
When the select button of the mouse is first pressed an outline
representing the window frame is drawn.  While the button is held down the
outline remains, and it moves with the pointer as the mouse is moved.
When the button is released, the outline is erased and the window takes
its new position.

 [Intuition's Use of Mouse Events](libraries/10-the-mouse-intuition-s-use-of-mouse-events.md)    [Mouse Usage Example](libraries/10-the-mouse-mouse-usage-example.md) 
 [Mouse Messages](libraries/10-the-mouse-mouse-messages.md) 

