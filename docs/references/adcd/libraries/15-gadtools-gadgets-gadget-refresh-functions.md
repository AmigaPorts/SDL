---
title: 15 / GadTools Gadgets / Gadget Refresh Functions
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-gadget-refresh-functions
functions: [AddGList, BeginRefresh, EndRefresh, GT_BeginRefresh, GT_EndRefresh, GT_RefreshWindow, RefreshGList]
libraries: [gadtools.library, intuition.library]
---

# 15 / GadTools Gadgets / Gadget Refresh Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Normally, GadTools gadgets are created and then attached to a window when
the window is opened, either through the [WA_Gadget](libraries/4-window-attributes-window-attribute-tags.md) tag or the
[NewWindow.FirstGadget](libraries/4-window-attributes-window-attribute-tags.md) field.  Alternately, they may be added to a window
after it is open by using the functions [AddGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) and [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md).

Regardless of which way gadgets are attached to a window, the program must
then call the [GT_RefreshWindow()](autodocs-2.0/gadtools-library-gt-refreshwindow.md) function to complete the rendering of
GadTools gadgets.  This function takes two arguments.


```c
    void GT_RefreshWindow( struct Window *win, struct Requester *req );
```
This win argument is a pointer to the window that contains the GadTools
gadgets.  The req argument is currently unused and should be set to NULL.
This function should only be called immediately after adding GadTools
gadgets to a window.  Subsequent changes to GadTools gadget imagery made
through calls to [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) will be automatically performed by
GadTools when the changes are made.  (There is no need to call
[GT_RefreshWindow()](autodocs-2.0/gadtools-library-gt-refreshwindow.md) in that case.)

As mentioned earlier, applications must always ask for notification of
window refresh events for any window that uses GadTools gadgets.  When the
application receives an [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) message for a window,
Intuition has already refreshed its gadgets.  Normally, a program would
then call Intuition's [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md), perform its own custom rendering
operations, and finally call [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md).  But for a window that uses
GadTools gadgets, the application must call [GT_BeginRefresh()](autodocs-2.0/gadtools-library-gt-beginrefresh.md) and
[GT_EndRefresh()](autodocs-2.0/gadtools-library-gt-endrefresh.md) in place of BeginRefresh() and EndRefresh().  This allows
the the GadTools gadgets to be fully refreshed.


```c
    void GT_BeginRefresh( struct Window *win );
    void GT_EndRefresh ( struct Window *win, long complete );
```
For both functions, the win argument is a pointer to the window to be
refreshed.  For [GT_EndRefresh()](autodocs-2.0/gadtools-library-gt-endrefresh.md), set the complete argument to TRUE if
refreshing is complete, set it to FALSE otherwise.  See the discussion of
[BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) and [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) in the "Intuition Windows" chapter for
more about window refreshing.

When using GadTools gadgets, the program may not set the window's
[WFLG_NOCAREREFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag.  Even if there is no custom rendering to be
performed, GadTools gadgets requires this minimum code to handle
[IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) messages:


```c
    case IDCMP_REFRESHWINDOW:
        GT_BeginRefresh(win);
        /* custom rendering, if any, goes here */
        GT_EndRefresh(win, TRUE);
        break;
```

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
- [GT_RefreshWindow — gadtools.library](../autodocs/gadtools.library.md#gt_refreshwindow)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
