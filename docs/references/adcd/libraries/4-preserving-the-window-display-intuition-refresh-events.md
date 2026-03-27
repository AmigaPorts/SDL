---
title: 4 / Preserving the Window Display / Intuition Refresh Events
manual: libraries
chapter: libraries
section: 4-preserving-the-window-display-intuition-refresh-events
functions: [BeginRefresh, EndRefresh]
libraries: [intuition.library]
---

# 4 / Preserving the Window Display / Intuition Refresh Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When using a Simple Refresh or a Smart Refresh windows, the program may
receive refresh events, informing it to update the display.  See the above
discussion for information on when refresh events are sent.

A message of the class [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md) arrives at the IDCMP, informing
the program of the need to update the display.  The program must take some
action when it receives a refresh event, even if it is just the acceptable
minimum action described below.

On receiving a refresh event, [BeginRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) must be called, then the
program should redraw its display, and, finally, call [EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md).  The
minimum required action is to call the BeginRefresh()/EndRefresh() pair.
This allows Intuition and the [Layers library](libraries/30-layers-library-layers.md) keep things sorted and
organized.

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
