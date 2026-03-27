---
title: 3 / / Screen Functions That Integrate Intuition and Graphics
manual: libraries
chapter: libraries
section: 3-screen-functions-that-integrate-intuition-and-graphics
functions: [LoadView, MakeScreen, MakeVPort, MrgCop, RemakeDisplay, RethinkDisplay]
libraries: [graphics.library, intuition.library]
---

# 3 / / Screen Functions That Integrate Intuition and Graphics

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These functions, normally used only by the system, integrate high-level
Intuition structures with the lower-level constructs used by the graphics
library to create the display.


    Table 3-9: Screen Functions That Integrate Intuition and Graphics
  _______________________________________________________________________
 |                                                                       |
 |      [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md)  Update a single screen's copper list               |
 |                                                                       |
 |  [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md)  Merge copper lists from all screens to form a [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) |
 |                                                                       |
 |   [RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md)  Update all screen copper lists then merge them to  |
 |                    form a View                                        |
 |_______________________________________________________________________|


Advanced Intuition programmers may use these functions to achieve special
screen effects such as [double-buffering](libraries/3-advanced-screen-programming-double-buffering.md) or [dual-playfield](libraries/3-advanced-screen-programming-dual-playfield-screen-example.md) Intuition
screens.  For examples of these see the next section.

[MakeScreen()](autodocs-2.0/intuition-library-makescreen.md) updates, but does not install, a screen's Copper list.  This
function is the Intuition equivalent of the low-level [MakeVPort()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) graphics
library function.  MakeScreen() performs the MakeVPort() call,
synchronized with Intuition's own use of the screen's [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  Call
RethinkDisplay() after MakeScreen() to allow the new Copper list for the
screen to take effect.  The MakeScreen() function takes one argument, a
pointer to the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) that contains the Copper list to be updated.

[RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md) combines all the screen's copper lists into a single
view.  This procedure performs the Intuition global display
reconstruction, which includes massaging some of Intuition's internal
state data, rethinking all of the Intuition screen [ViewPorts](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) and their
relationship to one another, and, finally, reconstructing the entire
display by merging the new screens into the graphics [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure.
[Custom screens](libraries/3-intuition-screens-custom-screen-functions.md) that handle their own Copper instructions, use this call to
install the Copper list previously updated with MakeScreen().
RethinkDisplay() calls lower-level graphics primitives [MrgCop()](libraries/27-forming-a-basic-display-creating-the-display-instructions.md) and
[LoadView()](libraries/27-display-routines-and-structures-loading-and-displaying.md) to install the Copper list.  This function takes no arguments.

[RemakeDisplay()](autodocs-2.0/intuition-library-remakedisplay.md) remakes the entire Intuition display.  It is equivalent to
calling MakeScreen() for each screen in the system, then calling
RethinkDisplay().  This routine performs a MakeVPort() (graphics
primitive) on every Intuition screen and then calls RethinkDisplay() to
recreate the [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  It takes no arguments.

Both RemakeDisplay() and RethinkDisplay() take several milliseconds to run
and lock out all other tasks while they run.  This can seriously degrade
system performance, so do not use these routines lightly.

---

## See Also

- [LoadView — graphics.library](../autodocs/graphics.library.md#loadview)
- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
- [RemakeDisplay — intuition.library](../autodocs/intuition.library.md#remakedisplay)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
