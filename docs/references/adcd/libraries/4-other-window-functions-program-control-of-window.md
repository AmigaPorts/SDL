---
title: 4 / Other Window Functions / Program Control of Window Arrangement
manual: libraries
chapter: libraries
section: 4-other-window-functions-program-control-of-window
functions: [ChangeWindowBox, MoveWindow, MoveWindowInFrontOf, SizeWindow, WindowToBack, WindowToFront, ZipWindow]
libraries: [intuition.library]
---

# 4 / Other Window Functions / Program Control of Window Arrangement

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md) and [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md) allow the
program to modify the size and placement of its windows.  These calls are
available in all versions of the operating system.

[MoveWindowInFrontOf()](autodocs-2.0/intuition-library-movewindowinfrontof.md), [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md) and [ZipWindow()](autodocs-2.0/intuition-library-zipwindow.md) have been added
in Release 2 to provide more flexible control over the size and placement
of windows.

All of these functions are asynchronous.  The window will not be affected
by them immediately, rather, Intuition will act on the request the next
time it receives an input event.  Currently this happens at a minimum rate
of ten times per second, and a maximum of sixty times per second.  There
is no guarantee that the operation has taken place when the function
returns.  In some cases, there are IDCMP messages which will inform the
application when the change has completed (for example, an [IDCMP_NEWSIZE](libraries/9-event-message-classes-and-flags-window-flags.md)
event indicates that a resize operation has completed).

Use the [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md) function to move a window to a new position in the
screen.  Use [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md) to change the size of the window:


```c
    void MoveWindow( struct Window *window, long dx, long dy );
    void SizeWindow( struct Window *window, long dx, long dy );
```
Note that both [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md) and [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md) take the amount of change in
each axis (delta values instead of absolute coordinates).  To specify the
coordinates as absolute numbers, use [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md).  The SizeWindow()
function will respect the window's maximum and minimum dimensions only if
the window has a sizing gadget.

A new function in Release 2, [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md), allows an application to
change the window size and position in a single call:


```c
    void ChangeWindowBox( struct Window *window, long left, long top,
                          long width, long height );
```
Note that the position and size values are absolutes and not deltas.  The
window's maximum and minimum dimensions are always respected.

To depth arrange windows under program control, use [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md) and
[WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md):


```c
    void WindowToFront( struct Window *window );
    void WindowToBack( struct Window *window );
```
[WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md) depth arranges a given window in front of all other
windows on its screen.  [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md) depth arranges a given window
behind all other windows on its screen.

To move a window in front of a specific, given window (as opposed to all
windows), use [MoveWindowInFrontOf()](autodocs-2.0/intuition-library-movewindowinfrontof.md):


```c
    void MoveWindowInFrontOf( struct Window *window,
                              struct Window *behindWindow );
```
[MoveWindowInFrontOf()](autodocs-2.0/intuition-library-movewindowinfrontof.md) is a new call provided in Release 2 and is not
available in older versions of the OS.

To toggle the window size between its two zoom settings use [ZipWindow()](autodocs-2.0/intuition-library-zipwindow.md).
This performs the same action that occurs when the user selects the zoom
gadget:


```c
    void ZipWindow( struct Window *window );
```
The two zoom settings are the initial size and position of the window when
it was first opened and the alternate position specified with the [WA_Zoom](libraries/4-window-attributes-window-attribute-tags.md)
tag.  If no WA_Zoom tag is provided, the alternate position is taken from
the window's minimum dimensions, unless the window was opened at its
minimum dimension.  In that case, the alternate position is taken from the
window's maximum dimension.  [ZipWindow()](autodocs-2.0/intuition-library-zipwindow.md) is a new call provided in Release
2 and is not available in older versions of the OS.

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [MoveWindowInFrontOf — intuition.library](../autodocs/intuition.library.md#movewindowinfrontof)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
