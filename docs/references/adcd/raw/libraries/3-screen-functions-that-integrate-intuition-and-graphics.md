# 3 / / Screen Functions That Integrate Intuition and Graphics


These functions, normally used only by the system, integrate high-level
Intuition structures with the lower-level constructs used by the graphics
library to create the display.


    Table 3-9: Screen Functions That Integrate Intuition and Graphics
  _______________________________________________________________________
 |                                                                       |
 |      [MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html)  Update a single screen's copper list               |
 |                                                                       |
 |  [RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html)  Merge copper lists from all screens to form a [View](../Libraries_Manual_guide/node00F1.html#line4) |
 |                                                                       |
 |   [RemakeDisplay()](../Includes_and_Autodocs_2._guide/node0244.html)  Update all screen copper lists then merge them to  |
 |                    form a View                                        |
 |_______________________________________________________________________|


Advanced Intuition programmers may use these functions to achieve special
screen effects such as [double-buffering](../Libraries_Manual_guide/node00F7.html) or [dual-playfield](../Libraries_Manual_guide/node00F8.html) Intuition
screens.  For examples of these see the next section.

[MakeScreen()](../Includes_and_Autodocs_2._guide/node0228.html) updates, but does not install, a screen's Copper list.  This
function is the Intuition equivalent of the low-level [MakeVPort()](../Libraries_Manual_guide/node0332.html#line9) graphics
library function.  MakeScreen() performs the MakeVPort() call,
synchronized with Intuition's own use of the screen's [ViewPort](../Libraries_Manual_guide/node00F1.html#line4).  Call
RethinkDisplay() after MakeScreen() to allow the new Copper list for the
screen to take effect.  The MakeScreen() function takes one argument, a
pointer to the [Screen](../Libraries_Manual_guide/node00DE.html#line6) that contains the Copper list to be updated.

[RethinkDisplay()](../Includes_and_Autodocs_2._guide/node024B.html) combines all the screen's copper lists into a single
view.  This procedure performs the Intuition global display
reconstruction, which includes massaging some of Intuition's internal
state data, rethinking all of the Intuition screen [ViewPorts](../Libraries_Manual_guide/node00F1.html#line4) and their
relationship to one another, and, finally, reconstructing the entire
display by merging the new screens into the graphics [View](../Libraries_Manual_guide/node00F1.html#line4) structure.
[Custom screens](../Libraries_Manual_guide/node00DF.html) that handle their own Copper instructions, use this call to
install the Copper list previously updated with MakeScreen().
RethinkDisplay() calls lower-level graphics primitives [MrgCop()](../Libraries_Manual_guide/node0332.html#line27) and
[LoadView()](../Libraries_Manual_guide/node0333.html) to install the Copper list.  This function takes no arguments.

[RemakeDisplay()](../Includes_and_Autodocs_2._guide/node0244.html) remakes the entire Intuition display.  It is equivalent to
calling MakeScreen() for each screen in the system, then calling
RethinkDisplay().  This routine performs a MakeVPort() (graphics
primitive) on every Intuition screen and then calls RethinkDisplay() to
recreate the [View](../Libraries_Manual_guide/node00F1.html#line4).  It takes no arguments.

Both RemakeDisplay() and RethinkDisplay() take several milliseconds to run
and lock out all other tasks while they run.  This can seriously degrade
system performance, so do not use these routines lightly.

