# gadtools.library/CreateMenusA



   NAME
	CreateMenusA -- allocate and fill out a menu structure. (V36)
	CreateMenus -- varargs stub for CreateMenus(). (V36)

   SYNOPSIS
	menu = CreateMenusA(newmenu, tagList)
	D0                  A0       A1

	struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *CreateMenusA(struct [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	menu = CreateMenus(newmenu, firsttag, ...)

	struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *CreateMenus(struct [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

   FUNCTION
	CreateMenusA() allocates and initializes a complete menu
	structure based on the supplied array of [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) structures.
	Optionally, CreateMenusA() can allocate and initialize a complete
	set of menu items and sub-items for a single menu title.  This
	is dictated by the contents of the array of NewMenus.

   INPUTS
	newmenu - pointer to an array of initialized struct NewMenus.
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	GTMN_FrontPen (UBYTE) - Pen number to be used for menu text.
	    (Under V39 and higher, this tag also exists for [LayoutMenusA()](../Includes_and_Autodocs_3._guide/node0286.html)
	    and LayoutMenuItemsA()).  (defaults to zero).
	GTMN_FullMenu (BOOL) - Requires that the [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) specification
	    describes a complete menu strip, not a fragment.  If a fragment
	    is found, CreateMenusA() will fail with a secondary error of
	    GTMENU_INVALID.  (defaults to FALSE). (V37)
	GTMN_SecondaryError (ULONG *) - Supply a pointer to a NULL-initialized
	    ULONG to receive a descriptive error code.  Possible values:
	    GTMENU_INVALID - [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) structure describes an illegal
	        menu.  (CreateMenusA() will fail with a NULL result).
	    GTMENU_TRIMMED - [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) structure has too many menus, items,
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
              memory for the menus, or if the [NewMenu](../Includes_and_Autodocs_3._guide/node062A.html#line113) array had an
              illegal arrangement (eg. NM_SUB following NM_TITLE).
              (see also the GTMN_SecondaryError tag above).
```
   NOTES
	The strings you supply for menu text are not copied, and must
	be preserved for the life of the menu.
	The resulting menus have no positional information.  You will
	want to call [LayoutMenusA()](../Includes_and_Autodocs_3._guide/node0286.html) (or [LayoutMenuItemsA()](../Includes_and_Autodocs_3._guide/node0285.html)) to supply that.
	CreateMenusA() automatically provides you with a UserData field
	for each menu, menu-item or sub-item.  Use the GTMENU_USERDATA(menu)
	or GTMENUITEM_USERDATA(menuitem) macro to access it.

   BUGS
	Prior to V39, if you put images into menus using IM_ITEM
	or IM_SUB for a NewMenu->nm_Type, the image supplied had to
	be an ordinary struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704).  Starting with V39, you can use
	boopsi images.

   SEE ALSO
	[LayoutMenusA()](../Includes_and_Autodocs_3._guide/node0286.html), [FreeMenus()](../Includes_and_Autodocs_3._guide/node0279.html), gadtools.h/GTMENU_USERDATA(),
	gadtools.h/GTMENUITEM_USERDATA()

