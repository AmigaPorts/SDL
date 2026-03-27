# 3 / Types of Screens / Screen Components


Screens have very little visual impact, they simply provide a resolution
specific area to place other objects such as windows and menus.  Screens
have no borders.  Only the title bar marks the screen limits (specifying
the left and top edges, and the width of the screen), and the title bar
may be hidden, or obscured by graphics or windows.

The title bar also serves as the [menu bar](../Libraries_Manual_guide/node017B.html) when the user presses the menu
button on the mouse.  The menu bar area is shared by all applications
operating within the screen.

Within the title bar, there are [two gadgets](../Libraries_Manual_guide/node0131.html): a screen drag gadget and a
depth-arrangement gadget.  The screen drag gadget allows the screen to be
moved up and down.  The depth-arrangement gadget allows the screen to be
placed in front or behind all other screens.


```c
     [Figure 3-1: An Intuition Screen (Workbench)](../Libraries_Manual_guide/node05CF.html) 
```
Screens are always rectangular, and the areas at the sides and bottom of
the display that are not within the screen's limits are filled with the
background color.  The area above all visible screens is filled with the
background color of the highest screen.  These areas surrounding the
screen (normally unused) are known as the overscan area.  The Amiga
display system allows the overscan area to be used for graphics under
special circumstances (see the section on "[Overscan and the Display Clip](../Libraries_Manual_guide/node00EF.html)"
later in this chapter).

