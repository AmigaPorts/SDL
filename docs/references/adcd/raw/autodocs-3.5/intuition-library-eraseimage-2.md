# intuition.library/EraseImage



   NAME	
	EraseImage -- Erases an [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704). (V36)

   SYNOPSIS
	EraseImage( RPort, [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704), LeftOffset, TopOffset )
	            A0     A1     D0          D1

	VOID EraseImage( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) *, WORD, WORD );

   FUNCTION
	Erases an [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704).  For a normal [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) structure, this will
	call the graphics function [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html) (clear using layer
	backfill, if any) for the [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) box (LeftEdge/TopEdge/Width/Height).

	For custom image, the exact behavior is determined by the
	custom image class.

   INPUTS
 	RPort	- [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to erase a part of
	[Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704)	- custom or standard image
	LeftOffset,RightOffset - pixel offsets of [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) position

   RESULT
 	None.

   EXAMPLE


   NOTES


   BUGS


   SEE ALSO
	[graphics.library/EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html).

