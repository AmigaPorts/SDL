# graphics.library/DoCollision



   NAME
	DoCollision -- Test every gel in gel list for collisions.

   SYNOPSIS
	DoCollision(rp)
	            A1

	void DoCollision(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Tests each gel in gel list for boundary and gel-to-gel collisions.
	On detecting one of these collisions, the appropriate collision-
	handling routine is called. See the documentation for a thorough
	description of which collision routine is called. This routine
	expects to find the gel list correctly sorted in Y,X order.
	The system routine [SortGList](../Includes_and_Autodocs_3._guide/node032F.html) performs this function for the user.

   INPUTS
	rp = pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53)

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [SortGList()](../Includes_and_Autodocs_3._guide/node032F.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)

