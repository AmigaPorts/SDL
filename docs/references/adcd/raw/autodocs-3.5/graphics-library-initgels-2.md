# graphics.library/InitGels



   NAME
	InitGels -- initialize a gel list; must be called before using gels.

   SYNOPSIS
	InitGels(head, tail, GInfo)
	         A0    A1    A2

	void InitGels(struct [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) *, struct [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) *, struct [GelsInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line38) *);

   FUNCTION
	Assigns the VSprites as the head and tail of the gel list in [GfxBase](../Includes_and_Autodocs_3._guide/node0612.html#line25).
	Links these two gels together as the keystones of the list.
	If the collHandler vector points to some memory array, sets
	the BORDERHIT vector to NULL.

   INPUTS
	head  = pointer to the [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) structure to be used as the gel list head
	tail  = pointer to the [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) structure to be used as the gel list tail
	GInfo = pointer to the [GelsInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line38) structure to be initialized

   RESULT

   BUGS

   SEE ALSO
	[graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

