# graphics.library/RemBob



   NAME
	RemBob -- Macro to remove a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) from the gel list.

   SYNOPSIS
	RemBob(bob)

	RemBob(struct [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) *);

   FUNCTION
	Marks a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) as no-longer-required.  The gels internal code then
	removes the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) from the list of active gels the next time
	[DrawGList](../Includes_and_Autodocs_3._guide/node02CF.html) is executed. This is implemented as a macro.
	If the user is double-buffering the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138), it could take two
	calls to [DrawGList](../Includes_and_Autodocs_3._guide/node02CF.html) before the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) actually disappears from
	the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   INPUTS
	[Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) = pointer to the [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) to be removed

   RESULT

   BUGS

   SEE ALSO
	[RemIBob()](../Includes_and_Autodocs_3._guide/node0317.html)  [DrawGList()](../Includes_and_Autodocs_3._guide/node02CF.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)  [graphics/gfxmacros.h](../Includes_and_Autodocs_3._guide/node0660.html)

