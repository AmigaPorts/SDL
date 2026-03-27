---
title: 4 / Basic Window Structures and Functions / Windows and Screens
manual: libraries
chapter: libraries
section: 4-basic-window-structures-and-functions-windows-and-screens
functions: [LockPubScreen, OpenWindow, OpenWindowTagList, SetPubScreenModes]
libraries: [intuition.library]
---

# 4 / Basic Window Structures and Functions / Windows and Screens

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Windows may be opened on one of three screen types:  a custom screen, a
public screen or the Workbench screen.  A custom screen is one created and
controlled by your application.  Once you have set up a custom screen, you
may open a window on it directly by calling one of the three open window
functions.

To open a window on a custom screen, call [OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) (or
[OpenWindowTags()](libraries/4-basic-window-structures-and-functions-opening-a-window.md)) with the [WA_CustomScreen](libraries/4-window-attributes-window-attribute-tags.md) tag along with a pointer to the
custom screen.  This must be a pointer to a screen created by your
application.  For systems prior to Release 2, use the [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call
with [NewWindow](libraries/4-intuition-windows-basic-window-structures-and-functions.md).Type set to CUSTOMSCREEN and NewWindow.Screen set to a
pointer to your custom screen.

You may choose to open a window on an existing public (shareable) screen
instead of setting up your own custom screen.  Such windows are often
referred to as visitor windows because they "visit" a screen managed by
the system or another application.

For Workbench or other public screens that are not created and managed
directly by your application, you must lock the screen before opening the
window.  This ensures that the screen remains open while your call to open
the window is processed.  One way to obtain a lock on a public screen is
by calling the [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) function (see the "[Intuition Screens](libraries/3-public-screen-functions-accessing-a-public-screen-by-name.md)"
chapter).

Use [WA_PubScreenName](libraries/4-window-attributes-window-attribute-tags.md) with NULL to open a visitor window on the default
public screen (normally the Workbench screen).  If a name is provided and
the named screen exists, the visitor window will open on that named
screen.  In this case the system locks the named screen for you so there
is no need to call [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md) directly.  The open window call will
fail if it cannot obtain a lock on the screen.  If the
[WA_PubScreenFallBack](libraries/4-window-attributes-window-attribute-tags.md) tag is TRUE, the window will open on the default
public screen when WA_PubScreenName can't be found.

Another method to open a visitor window on a public screen is to use the
[WA_PubScreen](libraries/4-window-attributes-window-attribute-tags.md) tag along with a pointer to the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure of the
public screen obtained via [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md).

The application may also request the name of the "next" public screen,
which allows windows to "jump" between public screens.  This is done by
closing the application window on the first screen and opening a new
window on the next screen.  (See the "[Intuition Screens](libraries/3-types-of-screens-public-screens-and-custom-screens.md)" chapter for more
information on public and custom screens.)

If no action is taken by the programmer to open the window on a specific
screen, the window will open on the default public screen (normally the
Workbench).  This behavior is shown in the above [example](libraries/lib-examples-openwindowtags-c.md) using
[OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md).

There are two global modes which come into play when a visitor window is
opened on a public screen.  If the global mode SHANGHAI is set, Workbench
application windows will be opened on the default public screen.  A second
global mode, POPPUBSCREEN, forces a public screen to be moved to the front
when a visitor window opens on it.  These modes can be changed using
[SetPubScreenModes()](libraries/3-intuition-screens-public-screen-functions.md), however, these should only be set according to the
preferences of the user.

 [Simple Window on a Public Screen Example](libraries/lib-examples-winpubscreen-c.md) 

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [SetPubScreenModes — intuition.library](../autodocs/intuition.library.md#setpubscreenmodes)
