---
title: 4 / About Windows / Window System Gadgets
manual: libraries
chapter: libraries
section: 4-about-windows-window-system-gadgets
functions: []
libraries: []
---

# 4 / About Windows / Window System Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each window may have a number of system gadgets which allow the user to
control window size, shape and arrangement.  These gadgets are: the drag
bar, the depth gadget, the sizing gadget, the zoom gadget and the close
gadget.

The drag bar allows the user to change the position of the window with
respect to the screen.  The drag bar is in the top border of a window and
occupies any space in the top border that is not used by other gadgets.
The window may be dragged left, right, up and down on the screen, with the
limitation that the entire window must remain within the screen's
boundaries.  This is done by positioning the pointer over the title bar,
selecting the window and dragging to the new position.  Window drag may be
cancelled by pressing the right mouse button before the drag is completed.


```c
     [Figure 4-1: A Window with System Gadgets](libraries/lib-pics-4-1-pic.md) 
```
The depth gadget allows the user to depth arrange a window with respect to
other windows on the screen.  The depth gadget is always positioned in the
upper right corner of the window.  Clicking the depth gadget will move the
frontmost window behind all other windows.  If the window is not the
frontmost, it will be moved to the front.  Selecting the depth gadget with
the Shift qualifier always moves the window to the back (behind other
windows).

The sizing gadget allows the user to change the size of the window.
Sizing is subject to minimum and maximum values set by the application.
Width and height are independent in a sizing operation.  The sizing gadget
is always positioned in the lower right corner of the window.  It allows
the user to drag this corner of the window to a new position relative to
the upper left corner of the window, thus changing the width and height of
the window. Window sizing using the sizing gadget may be cancelled by
pressing the right mouse button before the size is completed.

The zoom gadget allows the user to quickly alternate between two preset
window size and position values.  The zoom gadget is always placed
immediately to the left of the depth gadget.  If there is no depth gadget
on the window, the zoom gadget will still appear next to where the depth
gadget would have been.

The close gadget performs no direct action on the window, rather it causes
Intuition to send a message to the application to close the window. This
allows the application to perform any required processing or to warn the
user before it closes the window.  The close gadget is always positioned
in the upper left corner of the window.

