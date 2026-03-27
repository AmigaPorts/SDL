# graphics.library/AddBob



   NAME
	AddBob -- Adds a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) to current gel list.

   SYNOPSIS
	AddBob(Bob, rp)
	       A0   A1

	void AddBob(struct [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Sets up the system [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) flags, then links this gel into the list
	via [AddVSprite](../Includes_and_Autodocs_3._guide/node029F.html).

   INPUTS
	[Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) = pointer to the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) structure to be added to the gel list
	rp  = pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [AddVSprite()](../Includes_and_Autodocs_3._guide/node029F.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

