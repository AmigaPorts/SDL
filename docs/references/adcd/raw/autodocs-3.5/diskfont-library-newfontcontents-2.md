# diskfont.library/NewFontContents



   NAME
	NewFontContents -- Create a [FontContents](../Includes_and_Autodocs_3._guide/node05DA.html#line26) image for a font. (V34)

   SYNOPSIS
	fontContentsHeader = NewFontContents(fontsLock,fontName)

       D0                                   A0        A1
	struct [FontContentsHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line52) *NewFontContents( [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129), char * );

   FUNCTION
	This function creates a new array of [FontContents](../Includes_and_Autodocs_3._guide/node05DA.html#line26) entries
	that describe all the fonts associated with the fontName,
	specifically, all those in the font directory whose name
	is that of the font sans the ".font" suffix.

   INPUTS
	fontsLock - a DOS lock on the FONTS: directory (or other
	    directory where the font contents file and associated
	    font directory resides).
	fontName - the font name, with the ".font" suffix, which
	    is also the name of the font contents file.

   RESULT
	fontContentsHeader - a struct [FontContentsHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line52) pointer.

   EXCEPTIONS
	This command was first made available as of version 34.

	D0 is zero if the fontName is does not have a ".font" suffix,
	if the fontName is too long, if a DOS error occurred, or if
	memory could not be allocated for the fontContentsHeader.

   SEE ALSO
	[DisposeFontContents()](../Includes_and_Autodocs_3._guide/node0134.html) to free the structure acquired here.

