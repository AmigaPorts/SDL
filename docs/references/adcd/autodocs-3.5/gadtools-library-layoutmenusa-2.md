---
title: gadtools.library/LayoutMenusA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-layoutmenusa-2
functions: [CreateMenusA, GetVisualInfoA, LayoutMenuItemsA, LayoutMenusA, OpenFont]
libraries: [gadtools.library, graphics.library]
---

# gadtools.library/LayoutMenusA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	LayoutMenusA -- position all the menus and menu items. (V36)
	LayoutMenus -- varargs stub for LayoutMenusA(). (V36)

   SYNOPSIS
	success = LayoutMenusA(menu, vi, tagList)
	D0                     A0    A1  A2

	[BOOL](autodocs-3.5/include-exec-types-h.md) LayoutMenusA(struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	success = LayoutMenus(menu, vi, firsttag, ...)

	[BOOL](autodocs-3.5/include-exec-types-h.md) LayoutMenus(struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md), [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	Lays out all the menus, menu items and sub-items in the supplied
	menu according to the supplied visual information and tag parameters.
	This routine attempts to columnize and/or shift the MenuItems in
	the event that a menu would be too tall or too wide.

   INPUTS
	menu - pointer to menu obtained from [CreateMenusA()](autodocs-3.5/gadtools-library-createmenusa-2.md).
	vi - pointer returned by [GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md).
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	GTMN_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *) - [Text](autodocs-3.5/graphics-library-text-2.md) Attribute to use for
	    menu-items and sub-items.  If not supplied, the screen's
	    font will be used.  This font must be openable via [OpenFont()](autodocs-3.5/graphics-library-openfont-2.md)
	    when this function is called. (V36)
	GTMN_NewLookMenus (BOOL) - If you ask for WA_NewLookMenus for your
	    window, you should ask for this tag as well.  This informs GadTools
	    to use the appropriate checkmark, Amiga-key, and colors. (V39)
	GTMN_Checkmark (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *) - If you are using a custom image for a
	    checkmark (WA_Checkmark), also pass it to GadTools, so it can lay
	    the menus out accordingly. (V39)
	GTMN_AmigaKey (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *) - If you are using a custom image for
	    the Amiga-key in menus (WA_AmigaKey), also pass it to GadTools, so
	    it can lay the menus out accordingly. (V39)
	GTMN_FrontPen (ULONG) - This tag has existed for CreateMenus(), but now
	    LayoutMenusA() has it too.  If a legitimate pen number is supplied,
	    it is used for coloring the menu items (in preference to
	    anything passed to CreateMenus()).  If GTMN_NewLookMenus
	    has been specified, this tag defaults to using the
	    screen's BARDETAILPEN, else it defaults to "do nothing".
	    For visual consistency, we recommend you omit this tag in all
	    functions, and let the defaults be used. (V39)

   RESULT
	success - TRUE if successful, FALSE otherwise (signifies that
	          the [TextAttr](autodocs-3.5/include-graphics-text-h.md) wasn't openable).

   NOTES
	When using this function, there is no need to also call
	[LayoutMenuItemsA()](autodocs-3.5/gadtools-library-layoutmenuitemsa-2.md).

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
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
