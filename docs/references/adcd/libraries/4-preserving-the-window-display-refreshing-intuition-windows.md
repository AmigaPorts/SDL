---
title: 4 / Preserving the Window Display / Refreshing Intuition Windows
manual: libraries
chapter: libraries
section: 4-preserving-the-window-display-refreshing-intuition-windows
functions: [AutoRequest, BeginRefresh, EndRefresh, OpenWindowTagList, RefreshGList, RefreshGadgets]
libraries: [intuition.library]
---

# 4 / Preserving the Window Display / Refreshing Intuition Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the user or an application performs an Intuition operation which
causes damage to a window, Intuition notifies that window's application.
It does this by sending a message of the class [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) to that
window's IDCMP.

In response to this message, your application should update the damaged
areas.  Rendering proceeds faster and looks cleaner if it is restricted to
the damaged areas only.  The [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) pair achieve
that.  The application should call BeginRefresh() for the window, and then
do its rendering.  Any rendering that would have gone into undamaged areas
of the window is automatically discarded; only the area in need of repair
is affected.  Finally, the application should call EndRefresh(), which
removes the restriction on rendering, and informs the system that the
damage region has been dealt with. Even if your application intends to do
no rendering, it must at least call BeginRefresh()/EndRefresh(), to inform
the system that the damage region is no longer needed.  If your
application never needs to render in response to a refresh event, it can
avoid having to call BeginRefresh()/EndRefresh() by setting the
WFLG_NOCAREREFRESH flag or the [WA_NoCareRefresh](libraries/4-window-attributes-boolean-window-attribute-tags.md) tag in the
[OpenWindowTagList()](libraries/4-basic-window-structures-and-functions-opening-a-window.md) call.

Note that by the time that your application receives notification that
refresh is needed, Intuition will have already refreshed your window's
border and all gadgets in the window, as needed.  Thus, it is unnecessary
to use any of the gadget-refreshing functions in response to an
[IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) event.

Operations performed between the [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) pair should
be restricted to simple rendering.  All of the rendering functions in
Intuition library and Graphics library are safe.  Avoid [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) or
[RefreshGadgets()](libraries/5-intuition-gadgets-function-reference.md), or you risk deadlocking the computer.  Avoid calls that
may lock the [LayerInfo](autodocs-2.0/includes-graphics-layers-h.md) or get complicated in Intuition, since
BeginRefresh() leaves the window's layer or layers locked.  Avoid
[AutoRequest()](libraries/7-intuition-requesters-and-alerts-function-reference.md) and [EasyRequest()](libraries/7-intuition-requesters-and-alerts-easy-requesters.md), and therefore all direct or indirect disk
related DOS calls.  See the "[Intuition Gadgets](libraries/5-gadget-refreshing-gadget-refreshing-by-intuition.md)" chapter for more
information on gadget restrictions with BeginRefresh()/EndRefresh().

 [Simple Refresh](libraries/4-refreshing-intuition-windows-simple-refresh.md)    [Smart Refresh](libraries/4-refreshing-intuition-windows-smart-refresh.md)    [SuperBitMap Refresh](libraries/4-refreshing-intuition-windows-superbitmap-refresh.md) 

---

## See Also

- [AutoRequest — intuition.library](../autodocs/intuition.library.md#autorequest)
- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [OpenWindowTagList — intuition.library](../autodocs/intuition.library.md#openwindowtaglist)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
