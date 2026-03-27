---
title: gadtools.library/GT_EndRefresh
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-endrefresh-2
functions: [EndRefresh, GT_BeginRefresh]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GT_EndRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_EndRefresh -- end refreshing friendly to GadTools. (V36)

   SYNOPSIS
	GT_EndRefresh(win, complete)
	              A0   D0

	VOID GT_EndRefresh(struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, [BOOL](autodocs-3.5/include-exec-types-h.md) complete);

   FUNCTION
	Invokes the [intuition.library/EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md) function in a manner
	friendly to the [Gadget](autodocs-3.5/include-intuition-intuition-h.md) Toolkit.  This function call permits
	GadTools gadgets to refresh themselves at the correct time.
	Call this function to [EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md) when you have used
	[GT_BeginRefresh()](autodocs-3.5/gadtools-library-gt-beginrefresh-2.md).

   INPUTS
	win - pointer to [Window](autodocs-3.5/include-intuition-intuition-h.md) structure for which a IDCMP_REFRESHWINDOW
	      IDCMP event was received.
	complete - TRUE when done with refreshing.

   SEE ALSO
	[intuition.library/EndRefresh()](autodocs-3.5/intuition-library-endrefresh-2.md)

---

## See Also

- [EndRefresh — intuition.library](../autodocs/intuition.library.md#endrefresh)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
