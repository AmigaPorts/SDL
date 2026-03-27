# intuition.library/DrawImageState



   NAME	
	DrawImageState -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) an (extended) Intuition [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) with
		special visual state. (V36)

   SYNOPSIS
	DrawImageState( RPort, [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704), LeftOffset, TopOffset, State, [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) )
			A0     A1     D0          D1         D2     A2

	VOID DrawImageState( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *,
		WORD, WORD, ULONG, struct [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) * );

   FUNCTION
	This function draws an Intuition [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) structure in a variety of
	"visual states," which are defined by constants in
	[intuition/imageclass.h](../Includes_and_Autodocs_3._guide/node061B.html).  These include:
	IDS_NORMAL		- like [DrawImage()](../Includes_and_Autodocs_3._guide/node03A9.html)
	IDS_SELECTED		- represents the "selected state" of a [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213)
	IDS_DISABLED		- the "ghosted state" of a gadget
	IDS_BUSY		- for future functionality
	IDS_INDETERMINATE	- for future functionality
	IDS_INACTIVENORMAL	- for gadgets in window border
	IDS_INACTIVESELECTED	- for gadgets in window border
	IDS_INACTIVEDISABLED	- for gadgets in window border

	Only IDS_NORMAL will make sense for traditional [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) structures,
	this function is more useful when applied to new custom images
	or "object-oriented image classes."

	Each class of custom images is responsible for documenting which
	visual states it supports, and you typically want to use images
	which support the appropriate states with your custom gadgets.

	The [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) parameter provides information invaluable to
	"rendered" images, such as pen color and resolution.  Each
	image class must document whether this parameter is required.

   INPUTS
 	RPort	- [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) for rendering
	[Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704)	- pointer to a (preferably custom) image
	LeftOffset,RightOffset - positional offsets in pixels
	State	- visual state selected from above
	[DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) - pointer to packed of pen selections and resolution.

   RESULT
 	None.

   EXAMPLE
	Provided separately in the DevCon '90 disk set.

   NOTES


   BUGS


   SEE ALSO
	[DrawImage()](../Includes_and_Autodocs_3._guide/node03A9.html), [GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html), [intuition/imageclass.h](../Includes_and_Autodocs_3._guide/node061B.html)

