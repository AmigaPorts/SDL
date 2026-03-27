---
title: gadtools.library/FreeVisualInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-freevisualinfo-2
functions: [CloseScreen, CloseWindow, FreeVisualInfo, GetVisualInfoA, UnlockPubScreen]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/FreeVisualInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeVisualInfo -- return any resources taken by GetVisualInfo. (V36)

   SYNOPSIS
	FreeVisualInfo(vi)
	               A0

	VOID FreeVisualInfo(APTR);

   FUNCTION
	FreeVisualInfo() returns any memory or other resources that
	were allocated by [GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md).  You should only call this function
	once you are done with using the gadgets (i.e. after [CloseWindow()](autodocs-3.5/intuition-library-closewindow-2.md)),
	but while the screen is still valid (i.e. before [CloseScreen()](autodocs-3.5/intuition-library-closescreen-2.md) or
	[UnlockPubScreen()](autodocs-3.5/intuition-library-unlockpubscreen-2.md)).

   INPUTS
	vi - pointer that was obtained by calling [GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md). This
	     value may be NULL.

   SEE ALSO
	[GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md)

---

## See Also

- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [FreeVisualInfo — gadtools.library](../autodocs/gadtools.library.md#freevisualinfo)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
