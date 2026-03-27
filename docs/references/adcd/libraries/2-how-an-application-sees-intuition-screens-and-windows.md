---
title: 2 / How an Application Sees Intuition / Screens and Windows
manual: libraries
chapter: libraries
section: 2-how-an-application-sees-intuition-screens-and-windows
functions: []
libraries: []
---

# 2 / How an Application Sees Intuition / Screens and Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As mentioned earlier, Intuition allows multiple programs to share the
display by managing a system of [multiple screens](libraries/3-types-of-screens-multiple-screens.md) and overlapping [windows](libraries/4-intuition-windows-about-windows.md).
A screen sets up the display environment and forms the background that
application windows operate in.  A window is simply a graphic rectangle
that represents a work context.  Each screen can have many windows on it.

[Multiple screens](libraries/3-types-of-screens-multiple-screens.md) and [windows](libraries/4-intuition-windows-about-windows.md) give each application its own separate visual
context so that many programs can output graphics and text to the display
at the same time without interfering with one another.  Intuition (using
the [layers library](libraries/30-layers-library-layers.md)) handles all the details of clipping graphics so they
stay inside window bounds and remembering graphics that go temporarily out
of sight when the user [rearranges windows](libraries/4-intuition-windows-preserving-the-window-display.md).

The keyboard and mouse are shared among applications through a simpler
technique:  only one application window at a time can have the
[input focus](libraries/9-intuition-input-idcmp-events-and-the-input-focus.md).  Hence, Intuition ensures that only one window, called the
[active window](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md) gets to know about keyboard, mouse and other types of input
activity.

Each application window is like a virtual terminal or console.  Your
program will seem to have the entire machine and display to itself.  It
can send text and graphics to its terminal window, and ask for input from
any number of sources, ignoring the fact that other programs may be
performing these same operations.  Intuition handles all the housekeeping.
In fact, your program can open several of these virtual terminals and
treat each one as if it were the only program running on the machine.
Intuition will keep track of all the activity and make sure commands and
data are dispatched to the right place.

