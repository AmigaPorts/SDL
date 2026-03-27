# diskfont.library/NewScaledDiskFont



   NAME
	NewScaledDiskFont -- Create a DiskFont scaled from another. (V36)

   SYNOPSIS
	header = NewScaledDiskFont(srcFont, destTextAttr)
	D0                         A0       A1

	struct [DiskFontHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line62) *NewScaledDiskFont( struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *,
		struct [TTextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line71) * );

   INPUTS
	srcFont - the font from which the scaled font is to be
	    constructed.
	destTextAttr - the desired attributes for the new scaled
	    font.  This may be a structure of type [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) or
	    [TTextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line71).

   RESULT
	header - a pointer to a [DiskFontHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line62) structure.  This is not
		being managed by the diskfont.library, however.

   NOTES
	o   This function may use the blitter.
	o   Fonts containing characters that render wholly outside
	    the character advance cell are currently not scalable.
	o   The font, and memory allocated for the scaled font can
	    can be freed by calling [StripFont()](../Includes_and_Autodocs_3._guide/node0330.html) on the font,
	    and then calling [UnLoadSeg()](../Includes_and_Autodocs_3._guide/node01C7.html) on the segment created
	    by this function.

	    Both the [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) structure, and segment pointer are contained
	    within the [DiskFontHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line62) struct.  The [DiskFontHeader](../Includes_and_Autodocs_3._guide/node05DA.html#line62) structure
	    will also be freed as part of the [UnLoadSeg()](../Includes_and_Autodocs_3._guide/node01C7.html) call.
	    [StripFont()](../Includes_and_Autodocs_3._guide/node0330.html) is a new graphics.library call as of V36.

