---
title: D / Errors / Windows--Borders Flicker after Resize
manual: libraries
chapter: libraries
section: d-errors-windows-borders-flicker-after-resize
functions: [EndRefresh]
libraries: [intuition.library]
---

# D / Errors / Windows--Borders Flicker after Resize

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Set the [NOCAREREFESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) flag.  Even [SMART_REFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) windows may generate
refresh events if there is a sizing gadget.  If you don't have specific
code to handle this, you must set the NOCAREREFRESH flag.  If you do have
refresh code, be sure to use the [Begin](libraries/4-preserving-the-window-display-optimized-window-refreshing.md)/[EndRefresh()](libraries/4-preserving-the-window-display-optimized-window-refreshing.md) calls.  Failure to
do one or the other will leave Intuition in an intermediate state, and
slow down operation for all windows on the screen.

---

## See Also

- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
