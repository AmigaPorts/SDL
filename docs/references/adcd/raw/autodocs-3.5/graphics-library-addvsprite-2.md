# graphics.library/AddVSprite



   NAME
	AddVSprite -- Add a [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) to the current gel list.

   SYNOPSIS
	AddVSprite(vs, rp)
	           A0  A1

	void AddVSprite(struct [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *);

   FUNCTION
	Sets up the system [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) flags
	Links this [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) into the current gel list using its Y,X

   INPUTS
	vs = pointer to the [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) structure to be added to the gel list
	rp = pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)

