---
title: BeginRefresh() and EndRefresh()
manual: amiga-mail
chapter: amiga-mail
section: beginrefresh-and-endrefresh
functions: [BeginRefresh, EndRefresh]
libraries: [intuition.library]
---

# BeginRefresh() and EndRefresh()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To improve the performance of repairing damage to simple and smart
refresh windows, Intuition can put a window into a special refresh
state using Intuition's BeginRefresh() function:


```c
    VOID BeginRefresh(struct Window *window)
```
While a window is in this state, the system restricts attempts to
render into the window to the window's damaged regions.  Because the
system ignores rendering operations outside the window's damage
regions, an application only refreshes the parts of a window that
need refreshing.  This can significant decrease the amount of time
necessary to refresh the window.  This also reduces the possibility
of visual flicker that can happen if an application has to redraw the
entire contents of a window.

To end a window's special refresh state, use EndRefresh():


```c
    VOID EndRefresh(struct Window *window, BOOL Complete)
```
Compared to BeginRefresh(), EndRefresh() has an extra parameter, a
boolean value.  If this value is TRUE, Intuition assumes that all of
the refreshing for this window is finished and removes all of the
window layer's damaged regions.  In most cases, this value should be
TRUE.  See the Autodoc for BeginRefresh() and EndRefresh() for more
information.

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
