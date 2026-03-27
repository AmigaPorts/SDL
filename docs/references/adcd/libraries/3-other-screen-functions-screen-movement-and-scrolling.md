---
title: 3 / Other Screen Functions / Screen Movement and Scrolling
manual: libraries
chapter: libraries
section: 3-other-screen-functions-screen-movement-and-scrolling
functions: [MoveScreen]
libraries: [intuition.library]
---

# 3 / Other Screen Functions / Screen Movement and Scrolling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [MoveScreen()](autodocs-2.0/intuition-library-movescreen.md) function moves the screen origin by the number of pixels
specified in dx and dy.


```c
    VOID MoveScreen( struct Screen *myscreen, WORD dx, WORD dy )
```
Calls to [MoveScreen()](autodocs-2.0/intuition-library-movescreen.md) are asynchronous; the screen is not necessarily
moved upon return of this function.  If the calls happen too quickly,
there may be unexpected results.  One way to pace these calls is to call
the function one time for each [IDCMP_INTUITICKS](libraries/9-event-message-classes-and-flags-other-flags.md) event.

Screen movement is also available through the screen's drag gadget in the
title bar and through a keyboard/mouse shortcut.  Left-Amiga with the
select button of the mouse anywhere within the screen will drag the screen
(even if the title bar is totally concealed by a window).  Dragging a
screen down will reveal any screen(s) behind it.  Screens are never
revealed to the left, right or bottom of another screen.

Additionally, oversized screens may be moved with the new autoscroll
feature of Release 2.  With autoscroll, the screen is automatically
scrolled as the pointer reaches one of the edges of the display.
Autoscroll only works on the active screen.

Another screen movement feature added in Release 2 is screen menu snap.
When a screen much larger than the viewing area is scrolled such that the
upper left corner is not visible (scrolled down or to the right), menus
may could be out of the visible portion of the screen.  To prevent this,
menu snap moves the screen to a position where the menus will be visible
before rendering them.  The screen appears to snap to the home position as
the menus are selected, moving back when the operation is complete.  If
the Left-Amiga qualifier is held when the menus are selected then the
screen will remain in the home position when the menu button is released.

The Intuition preferences editor, IControl, allows the user to change a
number of Intuition features.  Some of these features include the ability
to globally disable menu snap, and to change the select qualifier for
dragging the screen.  See the User's Manual for more information on
Preferences editors.

---

## See Also

- [MoveScreen — intuition.library](../autodocs/intuition.library.md#movescreen)
