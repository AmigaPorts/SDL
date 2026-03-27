# graphics.library/AskFont



   NAME
	AskFont -- get the text attributes of the current font

   SYNOPSIS
	AskFont(rp, textAttr)
	        A1  A0

	void AskFont(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *);

   FUNCTION
	This function fills the text attributes structure with the
	attributes of the current font in the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   INPUTS
	rp       - the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) from which the text attributes are
	           extracted
	textAttr - the [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) structure to be filled.  Note that
	           there is no support for a [TTextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line71).

   RESULT
	The textAttr structure is filled with the RastPort's text
	attributes.

   BUGS

   SEE ALSO
	[graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

