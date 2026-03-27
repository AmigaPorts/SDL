# graphics.library/OpenFont



   NAME
	OpenFont -- Get a pointer to a system font.

   SYNOPSIS
	font = OpenFont(textAttr)
	D0              A0

	struct [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) *OpenFont(struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *);

   FUNCTION
	This function searches the system font space for the graphics
	text font that best matches the attributes specified.  The
	pointer to the font returned can be used in subsequent
	[SetFont](../Includes_and_Autodocs_3._guide/node0323.html) and [CloseFont](../Includes_and_Autodocs_3._guide/node02C4.html) calls.  It is important to match this
	call with a corresponding [CloseFont](../Includes_and_Autodocs_3._guide/node02C4.html) call for effective
	management of ram fonts.

   INPUTS
	textAttr - a [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) or [TTextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line71) structure that describes the
	           text font attributes desired.

   RESULT
	font is zero if the desired font cannot be found.  If the named
	font is found, but the size and style specified are not
	available, a font with the nearest attributes is returned.

   BUGS
	Prior to V39 this function would return a [TextFont](../Includes_and_Autodocs_3._guide/node05EC.html#line88) pointer
	for any font which matched exactly in Y size, regardless of
	differences in DPI, or DotSize.

	As part of fixing this bug it is REQUIRED that you use pass the
	same [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) (or TTextAttr) to this function that was used when
	[OpenDiskFont()](../Includes_and_Autodocs_3._guide/node0137.html) was called.

	OpenFont(), and [OpenDiskFont()](../Includes_and_Autodocs_3._guide/node0137.html) use WeighTAMatch() to measure
	how well two fonts match.  WeightTAMatch() was a public function
	in graphics.library V36-V37; it is now a system PRIVATE function
	as of V39.

   SEE ALSO
	[CloseFont()](../Includes_and_Autodocs_3._guide/node02C4.html)  [SetFont()](../Includes_and_Autodocs_3._guide/node0323.html)
	[diskfont.library/OpenDiskFont](../Includes_and_Autodocs_3._guide/node0137.html)  [graphics/text.h](../Includes_and_Autodocs_3._guide/node05EC.html)
	[intuition/intuition.h](../Includes_and_Autodocs_3._guide/node05E0.html)

