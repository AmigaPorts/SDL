# gadtools.library/LayoutMenusA



   NAME
	LayoutMenusA -- position all the menus and menu items. (V36)
	LayoutMenus -- varargs stub for LayoutMenusA(). (V36)

   SYNOPSIS
	success = LayoutMenusA(menu, vi, tagList)
	D0                     A0    A1  A2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LayoutMenusA(struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	success = LayoutMenus(menu, vi, firsttag, ...)

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LayoutMenus(struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

   FUNCTION
	Lays out all the menus, menu items and sub-items in the supplied
	menu according to the supplied visual information and tag parameters.
	This routine attempts to columnize and/or shift the MenuItems in
	the event that a menu would be too tall or too wide.

   INPUTS
	menu - pointer to menu obtained from [CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html).
	vi - pointer returned by [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html).
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	GTMN_TextAttr (struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *) - [Text](../Includes_and_Autodocs_3._guide/node0332.html) Attribute to use for
	    menu-items and sub-items.  If not supplied, the screen's
	    font will be used.  This font must be openable via [OpenFont()](../Includes_and_Autodocs_3._guide/node0308.html)
	    when this function is called. (V36)
	GTMN_NewLookMenus (BOOL) - If you ask for WA_NewLookMenus for your
	    window, you should ask for this tag as well.  This informs GadTools
	    to use the appropriate checkmark, Amiga-key, and colors. (V39)
	GTMN_Checkmark (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *) - If you are using a custom image for a
	    checkmark (WA_Checkmark), also pass it to GadTools, so it can lay
	    the menus out accordingly. (V39)
	GTMN_AmigaKey (struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *) - If you are using a custom image for
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
	          the [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) wasn't openable).

   NOTES
	When using this function, there is no need to also call
	[LayoutMenuItemsA()](../Includes_and_Autodocs_3._guide/node0285.html).

   BUGS
	If a menu ends up being wider than the whole screen, it will
	run off the right-hand side.

   SEE ALSO
	[CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html), [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html)

