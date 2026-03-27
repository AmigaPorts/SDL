# graphics.library/RemIBob



   NAME
	RemIBob -- Immediately remove a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) from the gel list and the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   SYNOPSIS
	RemIBob(bob, rp, vp)
	        A0   A1  A2

	void RemIBob(struct [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) *, struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

   FUNCTION
	Removes a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) immediately by uncoupling it from the gel list and
	erases it from the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   INPUTS
	bob = pointer to the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) to be removed
	rp  = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) if the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) is to be erased
	vp  = pointer to the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) for beam-synchronizing

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [RemVSprite()](../Includes_and_Autodocs_3._guide/node0318.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)

