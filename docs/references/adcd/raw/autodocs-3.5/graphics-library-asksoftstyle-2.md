# graphics.library/AskSoftStyle



   NAME
	AskSoftStyle -- Get the soft style bits of the current font.

   SYNOPSIS
	enable = AskSoftStyle(rp)
	D0                    A1

	ULONG AskSoftStyle(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	This function returns those style bits of the current font
	that are not intrinsic in the font itself, but
	algorithmically generated.  These are the bits that are
	valid to set in the enable mask for [SetSoftStyle()](../Includes_and_Autodocs_3._guide/node032D.html).

   INPUTS
	rp - the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) from which the font and style	are extracted.

   RESULTS
	enable - those bits in the style algorithmically generated.
	         Style bits that are not defined are also set.

   BUGS

   SEE ALSO
	[SetSoftStyle()](../Includes_and_Autodocs_3._guide/node032D.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)

