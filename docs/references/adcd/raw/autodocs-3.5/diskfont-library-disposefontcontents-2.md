# diskfont.library/DisposeFontContents



   NAME
	DisposeFontContents -- Free the result from [NewFontContents](../Includes_and_Autodocs_3._guide/node0135.html). (V34)

   SYNOPSIS
	DisposeFontContents(fontContentsHeader)
			    A1

	VOID DisposeFontContents( struct [FontContentsHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line52) * );

   FUNCTION
	This function frees the array of [FontContents](../Includes_and_Autodocs_3._guide/node05DA.html#line26) entries
	returned by [NewFontContents](../Includes_and_Autodocs_3._guide/node0135.html).

   INPUTS
	fontContentsHeader - a struct [FontContentsHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line52) pointer
	    returned by [NewFontContents](../Includes_and_Autodocs_3._guide/node0135.html).

   EXCEPTIONS
 	This command was first made available as of version 34.

	A fontContentsHeader other than one acquired by a call
	[NewFontContents](../Includes_and_Autodocs_3._guide/node0135.html) will crash.

   SEE ALSO
	[NewFontContents()](../Includes_and_Autodocs_3._guide/node0135.html) to get structure freed here.

