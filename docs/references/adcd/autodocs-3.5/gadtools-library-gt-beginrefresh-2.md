---
title: gadtools.library/GT_BeginRefresh
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-beginrefresh-2
functions: [BeginRefresh, GT_EndRefresh]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GT_BeginRefresh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_BeginRefresh -- begin refreshing friendly to GadTools. (V36)

   SYNOPSIS
	GT_BeginRefresh(win)
	                A0

	VOID GT_BeginRefresh(struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *);

   FUNCTION
	Invokes the [intuition.library/BeginRefresh()](autodocs-3.5/intuition-library-beginrefresh-2.md) function in a manner
	friendly to the [Gadget](autodocs-3.5/include-intuition-intuition-h.md) Toolkit.  This function call permits the
	GadTools gadgets to refresh themselves at the correct time.
	Call [GT_EndRefresh()](autodocs-3.5/gadtools-library-gt-endrefresh-2.md) function when done.

   INPUTS
	win - pointer to [Window](autodocs-3.5/include-intuition-intuition-h.md) structure for which a IDCMP_REFRESHWINDOW
	      IDCMP event was received.

   NOTES
	The nature of GadTools precludes the use of the IDCMP flag
	WFLG_NOCAREREFRESH.  You must handle IDCMP_REFRESHWINDOW events
	in at least the minimal way, namely:

		case IDCMP_REFRESHWINDOW:
		    GT_BeginRefresh(win);
		    GT_EndRefresh(win, TRUE);
		    break;

   SEE ALSO
	[intuition.library/BeginRefresh()](autodocs-3.5/intuition-library-beginrefresh-2.md)

---

## See Also

- [BeginRefresh — intuition.library](../autodocs/intuition.library.md#beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
