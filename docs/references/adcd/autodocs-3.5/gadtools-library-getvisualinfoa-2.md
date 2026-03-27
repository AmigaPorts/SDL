---
title: gadtools.library/GetVisualInfoA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-getvisualinfoa-2
functions: [FreeVisualInfo, GetVisualInfoA, LockPubScreen, UnlockPubScreen]
libraries: [gadtools.library, intuition.library]
---

# gadtools.library/GetVisualInfoA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetVisualInfoA -- get information GadTools needs for visuals. (V36)
	GetVisualInfo -- varargs stub for GetVisualInfoA(). (V36)

   SYNOPSIS
	vi = GetVisualInfoA(screen, tagList)
	D0                  A0      A1

	[APTR](autodocs-3.5/include-exec-types-h.md) vi = GetVisualInfoA(struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	vi = GetVisualInfo(screen, firsttag, ...)

	[APTR](autodocs-3.5/include-exec-types-h.md) vi = GetVisualInfo(struct [Screen](autodocs-3.5/include-intuition-screens-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	Get a pointer to a (private) block of data containing various bits
	of information that GadTools needs to ensure the best quality
	visuals.  Use the result in the [NewGadget](autodocs-3.5/include-libraries-gadtools-h.md) structure of any gadget
	you create, or as a parameter to the various menu calls.  Once the
	gadgets/menus are no longer needed (after the last CloseWindow),
	call [FreeVisualInfo()](autodocs-3.5/gadtools-library-freevisualinfo-2.md).

   INPUTS
	screen - pointer to the screen you will be opening on. This parameter
		 may be NULL, in which case this function fails.
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	There are currently no tags defined for this function.

   RESULT
	vi - pointer to private data, or NULL for failure

   SEE ALSO
	[FreeVisualInfo()](autodocs-3.5/gadtools-library-freevisualinfo-2.md), [intuition/LockPubScreen()](autodocs-3.5/intuition-library-lockpubscreen-2.md),
	[intuition/UnlockPubScreen()](autodocs-3.5/intuition-library-unlockpubscreen-2.md)

---

## See Also

- [FreeVisualInfo — gadtools.library](../autodocs/gadtools.library.md#freevisualinfo)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [UnlockPubScreen — intuition.library](../autodocs/intuition.library.md#unlockpubscreen)
