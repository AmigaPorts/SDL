# gadtools.library/FreeMenus



   NAME
	FreeMenus -- frees memory allocated by [CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html). (V36)

   SYNOPSIS
	FreeMenus(menu)
	          A0

	VOID FreeMenus(struct [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) *);

   FUNCTION
	Frees the menus allocated by [CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html).  It is safe to
	call this function with a NULL parameter.

   INPUTS
	menu - pointer to menu structure (or first MenuItem) obtained
	       from [CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html).

   SEE ALSO
	[CreateMenusA()](../Includes_and_Autodocs_3._guide/node0276.html)

