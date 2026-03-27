# graphics.library/CloseFont



   NAME
	CloseFont -- Release a pointer to a system font.

   SYNOPSIS
	CloseFont(font)
	          A1

	void CloseFont(struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *);

   FUNCTION
	This function indicates that the font specified is no longer
	in use.  It is used to close a font opened by [OpenFont](../Includes_and_Autodocs_3._guide/node0308.html), so
	that fonts that are no longer in use do not consume system
	resources.

   INPUTS
	font -	a font pointer as returned by [OpenFont()](../Includes_and_Autodocs_3._guide/node0308.html) or [OpenDiskFont()](../Includes_and_Autodocs_3._guide/node0137.html)

   RESULT

   BUGS

   SEE ALSO
	[OpenFont()](../Includes_and_Autodocs_3._guide/node0308.html)  [diskfont.library/OpenDiskFont](../Includes_and_Autodocs_3._guide/node0137.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

