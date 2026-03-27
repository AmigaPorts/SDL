---
title: 4 / Basic Window Structures and Functions / Closing Windows
manual: libraries
chapter: libraries
section: 4-basic-window-structures-and-functions-closing-windows
functions: [ActivateWindow, CloseWindow, OpenWindow]
libraries: [intuition.library]
---

# 4 / Basic Window Structures and Functions / Closing Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Call the [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md) function to close a window, remove its imagery from
the display, and clean up any system resources used by the window.
Typically, you call CloseWindow() when Intuition informs you that the user
has selected the window's close gadget but this is not a requirement nor
does the window have to be active to be closed.


```c
    void CloseWindow( struct Window *window );
```
Pass this function a pointer to the [Window](libraries/4-intuition-windows-basic-window-structures-and-functions.md) structure returned by one of
the [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) calls.

If you call [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md) on the active window, the previously active
window (if available) will become the active window.  If the previously
active window has already closed, then the window active prior to that
window will become the active window.  (Applications should not rely on
this behavior.  To make a specific window become active, call the
[ActivateWindow()](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md) function.)

Intuition does not automatically close a window when the user selects the
close window gadget.  Instead, Intuition sends your program a message
about the user's action.  The program can then perform whatever cleanup is
necessary before closing the window with the [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md) function.

---

## See Also

- [ActivateWindow — intuition.library](../autodocs/intuition.library.md#activatewindow)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
