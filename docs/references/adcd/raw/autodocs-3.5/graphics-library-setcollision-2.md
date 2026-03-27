# graphics.library/SetCollision



   NAME
	SetCollision -- Set a pointer to a user collision routine.

   SYNOPSIS
	SetCollision(num, routine, GInfo)
	             D0   A0       A1

	void SetCollision(ULONG, VOID (*)(), struct [GelsInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line38) *);

   FUNCTION
	Sets a specified entry (num) in the user's collision vectors table
	equal to the address of the specified collision routine.

   INPUTS
	num     = collision vector number
	routine = pointer to the user's collision routine
	GInfo   = pointer to a [GelsInfo](../Includes_and_Autodocs_3._guide/node05D7.html#line38) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)  [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)

