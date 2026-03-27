# 4 / Window Types / Backdrop Window Type


Backdrop windows open behind all other non-backdrop windows, but in front
of other backdrop windows that might already be open.  Depth arrangement
of a backdrop window affects the order of the window relative to other
backdrop windows, but backdrop windows always stay behind all non-backdrop
windows.  No amount of depth arrangement will ever move a non-backdrop
window behind a backdrop window.

The only system gadget that can be attached to a backdrop window is the
closewindow gadget. Application gadgets are not restricted in backdrop
windows.

Backdrop windows may often be used in place of drawing directly into the
display memory of a custom screen.  Such a technique is preferred, as
backdrop windows are compatible with the Intuition windowing system.
Using a backdrop window eliminates the danger of writing to the screen
memory at a "bad" time or at the wrong position and overwriting data in a
window.

To provide a full screen display area that is compatible with the
windowing system, create a full sized, borderless, backdrop window with no
system gadgets.  Use the [ShowTitle()](../Libraries_Manual_guide/node00FC.html#line10) call to hide or reveal the screen's
title bar, as appropriate.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for a complete list of arguments for [ShowTitle()](../Includes_and_Autodocs_2._guide/node0259.html).

Backdrop windows are created by specifying the WFLG_BACKDROP flag or the
[WA_Backdrop](../Libraries_Manual_guide/node0125.html#line77) tag in the [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.

