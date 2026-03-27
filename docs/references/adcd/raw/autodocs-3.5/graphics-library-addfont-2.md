# graphics.library/AddFont



   NAME
	AddFont -- add a font to the system list

   SYNOPSIS
	AddFont(textFont)
	        A1

	void AddFont(struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *);

   FUNCTION
	This function adds the text font to the system, making it
	available for use by any application.  The font added must be
	in public memory, and remain until successfully removed.

   INPUTS
	textFont - a [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) structure in public ram.

   RESULT

   NOTES
	This function will set the tf_Accessors to 0.

   BUGS

   SEE ALSO
	[SetFont()](../Includes_and_Autodocs_3._guide/node0323.html)  [RemFont()](../Includes_and_Autodocs_3._guide/node0316.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

