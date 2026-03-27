---
title: IV-77: Optimized Window Refreshing
manual: amiga-mail
chapter: amiga-mail
section: iv-77-optimized-window-refreshing
functions: [BeginRefresh, EndRefresh]
libraries: [intuition.library]
---

# IV-77: Optimized Window Refreshing

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Martin Taillefer


Maintaining the graphical contents of an Amiga window can be
difficult.  There are many subtleties associated with the process
known as window refreshing.  At present, many applications refresh
their windows in suboptimal ways, or fail to refresh correctly under
all conditions.  This article attempts to explore and resolve the
window refreshing problems commonly encountered by applications.

 [Damaging Information](amiga-mail/damaging-information.md)          [Using Multiple RastPorts](amiga-mail/using-multiple-rastports.md) 
 [When To Refresh](amiga-mail/when-to-refresh.md)               [Refreshing a Sizable Window](amiga-mail/refreshing-a-sizable-window.md) 
 [Scrolling Your Life Away](amiga-mail/scrolling-your-life-away.md)      [BeginRefresh() and EndRefresh()](amiga-mail/beginrefresh-and-endrefresh.md) 
 [Faster Rendering](amiga-mail/faster-rendering.md)              [Backfill Hook](amiga-mail/backfill-hook.md) 

 [Optimrefresh.c](amiga-mail/iv-77-optimrefresh-c.md) 

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
