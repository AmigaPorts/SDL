---
title: gadtools.library/CreateMenusA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-createmenusa-2
functions: [CreateMenusA, FreeMenus, LayoutMenuItemsA, LayoutMenusA]
libraries: [gadtools.library]
---

# gadtools.library/CreateMenusA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateMenusA -- allocate and fill out a menu structure. (V36)
	CreateMenus -- varargs stub for CreateMenus(). (V36)

   SYNOPSIS
	menu = CreateMenusA(newmenu, tagList)
	D0                  A0       A1

	struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *CreateMenusA(struct [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	menu = CreateMenus(newmenu, firsttag, ...)

	struct [Menu](autodocs-3.5/include-intuition-intuition-h.md) *CreateMenus(struct [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	CreateMenusA() allocates and initializes a complete menu
	structure based on the supplied array of [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) structures.
	Optionally, CreateMenusA() can allocate and initialize a complete
	set of menu items and sub-items for a single menu title.  This
	is dictated by the contents of the array of NewMenus.

   INPUTS
	newmenu - pointer to an array of initialized struct NewMenus.
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	GTMN_FrontPen (UBYTE) - Pen number to be used for menu text.
	    (Under V39 and higher, this tag also exists for [LayoutMenusA()](autodocs-3.5/gadtools-library-layoutmenusa-2.md)
	    and LayoutMenuItemsA()).  (defaults to zero).
	GTMN_FullMenu (BOOL) - Requires that the [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) specification
	    describes a complete menu strip, not a fragment.  If a fragment
	    is found, CreateMenusA() will fail with a secondary error of
	    GTMENU_INVALID.  (defaults to FALSE). (V37)
	GTMN_SecondaryError (ULONG *) - Supply a pointer to a NULL-initialized
	    ULONG to receive a descriptive error code.  Possible values:
	    GTMENU_INVALID - [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) structure describes an illegal
	        menu.  (CreateMenusA() will fail with a NULL result).
	    GTMENU_TRIMMED - [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) structure has too many menus, items,
	        or subitems (CreateMenusA() will succeed, returning a
	        trimmed-down menu structure).
	    GTMENU_NOMEM - CreateMenusA() ran out of memory.
	    (V37)

   RESULT
	menu - pointer to the resulting initialized menu structure (or

```c
              the resulting FirstItem), with all the links for menu items
              and subitems in place.
              The result will be NULL if CreateMenusA() could not allocate
              memory for the menus, or if the [NewMenu](autodocs-3.5/include-libraries-gadtools-h.md) array had an
              illegal arrangement (eg. NM_SUB following NM_TITLE).
              (see also the GTMN_SecondaryError tag above).
```
   NOTES
	The strings you supply for menu text are not copied, and must
	be preserved for the life of the menu.
	The resulting menus have no positional information.  You will
	want to call [LayoutMenusA()](autodocs-3.5/gadtools-library-layoutmenusa-2.md) (or [LayoutMenuItemsA()](autodocs-3.5/gadtools-library-layoutmenuitemsa-2.md)) to supply that.
	CreateMenusA() automatically provides you with a UserData field
	for each menu, menu-item or sub-item.  Use the GTMENU_USERDATA(menu)
	or GTMENUITEM_USERDATA(menuitem) macro to access it.

   BUGS
	Prior to V39, if you put images into menus using IM_ITEM
	or IM_SUB for a NewMenu->nm_Type, the image supplied had to
	be an ordinary struct [Image](autodocs-3.5/include-intuition-intuition-h.md).  Starting with V39, you can use
	boopsi images.

   SEE ALSO
	[LayoutMenusA()](autodocs-3.5/gadtools-library-layoutmenusa-2.md), [FreeMenus()](autodocs-3.5/gadtools-library-freemenus-2.md), gadtools.h/GTMENU_USERDATA(),
	gadtools.h/GTMENUITEM_USERDATA()

---

## See Also

- [CreateMenusA — gadtools.library](../autodocs/gadtools.library.md#createmenusa)
- [FreeMenus — gadtools.library](../autodocs/gadtools.library.md#freemenus)
- [LayoutMenuItemsA — gadtools.library](../autodocs/gadtools.library.md#layoutmenuitemsa)
- [LayoutMenusA — gadtools.library](../autodocs/gadtools.library.md#layoutmenusa)
