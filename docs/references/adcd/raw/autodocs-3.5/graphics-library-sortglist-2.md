# graphics.library/SortGList



   NAME
	SortGList -- Sort the current gel list, ordering its y,x coordinates.

   SYNOPSIS
	SortGList(rp)
	          A1

	void SortGList(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Sorts the current gel list according to the gels' y,x coordinates.
	This sorting is essential before calls to [DrawGList](../Includes_and_Autodocs_3._guide/node02CF.html) or [DoCollision](../Includes_and_Autodocs_3._guide/node02CC.html).

   INPUTS
	rp = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure containing the [GelsInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line38)

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [DoCollision()](../Includes_and_Autodocs_3._guide/node02CC.html)  [DrawGList()](../Includes_and_Autodocs_3._guide/node02CF.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

