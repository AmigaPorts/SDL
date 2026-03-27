# gadtools.library/LayoutMenuItemsA



   NAME
	LayoutMenuItemsA -- position all the menu items. (V36)
	LayoutMenuItems -- varargs stub for LayoutMenuItemsA(). (V36)

   SYNOPSIS
	success = LayoutMenuItemsA(menuitem, vi, tagList)
	D0                         A0        A1  A2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LayoutMenuItemsA(struct [MenuItem](../Includes_and_Autodocs_3._guide/node05E0.html#line87) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	success = LayoutMenuItems(menuitem, vi, firsttag, ...)

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LayoutMenuItemsA(struct [MenuItem](../Includes_and_Autodocs_3._guide/node05E0.html#line87) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

   FUNCTION
	Lays out all the menu items and sub-items according to
	the supplied visual information and tag parameters.  You would use this
	if you used [CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html) to make a single menu-pane (with sub-items,
	if any), instead of a whole menu strip.
	This routine attempts to columnize and/or shift the MenuItems in
	the event that a menu would be too tall or too wide.

   INPUTS
	menuitem - pointer to first [MenuItem](../Includes_and_Autodocs_3._guide/node05E0.html#line87) in a linked list of
	           items.
	vi - pointer returned by [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html).
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	GTMN_Menu (struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *) - Pointer to the [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) structure whose
	    FirstItem is the [MenuItem](../Includes_and_Autodocs_3._guide/node05E0.html#line87) supplied above.  If the menu items are
	    such that they need to be columnized or shifted, the [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59)
	    structure is needed to perform the complete calculation.
	    It is suggested you always provide this information. (V36)

	For the following tags, please see the description under
	[LayoutMenusA()](../Includes_and_Autodocs_3._guide/node0286.html).  Their behavior is identical when used in
	LayoutMenuItemsA().

	    GTMN_TextAttr
	    GTMN_NewLookMenus
	    GTMN_Checkmark
	    GTMN_AmigaKey
	    GTMN_FrontPen

   RESULT
	success - TRUE if successful, FALSE otherwise (signifies that
	          the [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) wasn't openable).

   BUGS
	If a menu ends up being wider than the whole screen, it will
	run off the right-hand side.

   SEE ALSO
	[CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html), [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html)

