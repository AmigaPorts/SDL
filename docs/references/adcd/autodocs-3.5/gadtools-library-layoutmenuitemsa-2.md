---
title: gadtools.library/LayoutMenuItemsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-layoutmenuitemsa-2
functions: [CreateMenusA, GetVisualInfoA, LayoutMenuItemsA, LayoutMenusA]
libraries: [gadtools.library]
---

# gadtools.library/LayoutMenuItemsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LayoutMenuItemsA -- position all the menu items. (V36)
	LayoutMenuItems -- varargs stub for LayoutMenuItemsA(). (V36)

   SYNOPSIS
	success = LayoutMenuItemsA(menuitem, vi, tagList)
	D0                         A0        A1  A2

	[BOOL](autodocs-3.5/include-exec-types-h.md) LayoutMenuItemsA(struct [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	success = LayoutMenuItems(menuitem, vi, firsttag, ...)

	[BOOL](autodocs-3.5/include-exec-types-h.md) LayoutMenuItemsA(struct [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	Lays out all the menu items and sub-items according to
	the supplied visual information and tag parameters.  You would use this
	if you used [CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md) to make a single menu-pane (with sub-items,
	if any), instead of a whole menu strip.
	This routine attempts to columnize and/or shift the MenuItems in
	the event that a menu would be too tall or too wide.

   INPUTS
	menuitem - pointer to first [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) in a linked list of
	           items.
	vi - pointer returned by [GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md).
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	GTMN_Menu (struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *) - Pointer to the [Menu](autodocs-3.5/include-intuition-intuition-h.md) structure whose
	    FirstItem is the [MenuItem](autodocs-3.5/include-intuition-intuition-h.md) supplied above.  If the menu items are
	    such that they need to be columnized or shifted, the [Menu](autodocs-3.5/include-intuition-intuition-h.md)
	    structure is needed to perform the complete calculation.
	    It is suggested you always provide this information. (V36)

	For the following tags, please see the description under
	[LayoutMenusA()](autodocs-3.5/gadtools-library-layoutmenusa-2.md).  Their behavior is identical when used in
	LayoutMenuItemsA().

	    GTMN_TextAttr
	    GTMN_NewLookMenus
	    GTMN_Checkmark
	    GTMN_AmigaKey
	    GTMN_FrontPen

   RESULT
	success - TRUE if successful, FALSE otherwise (signifies that
	          the [TextAttr](autodocs-3.5/include-graphics-text-h.md) wasn't openable).

   BUGS
	If a menu ends up being wider than the whole screen, it will
	run off the right-hand side.

   SEE ALSO
	[CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md), [GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md)

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
- [LayoutMenuItemsA — gadtools.library](../autodocs/gadtools.library.md#layoutmenuitemsa)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
