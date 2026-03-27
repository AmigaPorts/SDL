---
title: gadtools.library/GT_RefreshWindow
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-refreshwindow-2
functions: [AddGList, GT_BeginRefresh, RefreshGList]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GT_RefreshWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_RefreshWindow -- refresh all GadTools gadgets in a window. (V36)

   SYNOPSIS
	GT_RefreshWindow(win, req)
	                 A0   A1

	VOID GT_RefreshWindow(struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *);

   FUNCTION
	Perform the initial refresh of all the GadTools gadgets you have
	created.  After you have opened your window, you must call this
	function.  Or, if you have opened your window without gadgets,
	you add the gadgets with [intuition.library/AddGList()](autodocs-3.5/intuition-library-addglist-2.md),
	refresh them using [intuition.library/RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md), then call
	this function.
	You should not need this function at other times.

   INPUTS
	win - pointer to the [Window](autodocs-3.5/include-intuition-intuition-h.md) containing GadTools gadgets.
	req - reserved for future use, should always be NULL

   SEE ALSO
	[GT_BeginRefresh()](autodocs-3.5/gadtools-library-gt-beginrefresh-2.md)

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
