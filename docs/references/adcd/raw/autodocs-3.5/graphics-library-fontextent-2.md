# graphics.library/FontExtent



   NAME
	FontExtent -- get the font attributes of the current font (V36)

   SYNOPSIS
	FontExtent(font, fontExtent)
	           A0    A1

	void FontExtent(struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *, struct [TextExtent](../Includes_and_Autodocs_3._guide/node05EC.html#line163) *);

   FUNCTION
	This function fills the text extent structure with a bounding
	(i.e. maximum) extent for the characters in the specified font.

   INPUTS
	font       - the [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) from which the font metrics are extracted.
	fontExtent - the [TextExtent](../Includes_and_Autodocs_3._guide/node05EC.html#line163) structure to be filled.

   RESULT
	fontExtent is filled.

   NOTES
	The [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88), not the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), is specified -- unlike
	[TextExtent()](../Includes_and_Autodocs_3._guide/node0333.html), effect of algorithmic enhancements is not
	included, nor does te_Width include any effect of
	rp_TxSpacing.  The returned te_Width will be negative only
	when FPF_REVPATH is set in the tf_Flags of the font -- the
	effect of left-moving characters is ignored for the width of
	a normal font, and the effect of right-moving characters is
	ignored if a REVPATH font.  These characters will, however,
	be reflected in the bounding extent.

   SEE ALSO
	[TextExtent()](../Includes_and_Autodocs_3._guide/node0333.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

