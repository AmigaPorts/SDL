# graphics.library/RemFont



   NAME
	RemFont -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) a font from the system list.

   SYNOPSIS
	RemFont(textFont)
	        A1

	void RemFont(struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *);

   FUNCTION
	This function removes a font from the system, ensuring that
	access to it is restricted to those applications that
	currently have an active pointer to it: i.e. no new [SetFont](../Includes_and_Autodocs_3._guide/node0323.html)
	requests to this font are satisfied.

   INPUTS
	textFont - the [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) structure to remove.

   RESULT

   BUGS

   SEE ALSO
	[SetFont()](../Includes_and_Autodocs_3._guide/node0323.html)  [AddFont()](../Includes_and_Autodocs_3._guide/node029E.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

