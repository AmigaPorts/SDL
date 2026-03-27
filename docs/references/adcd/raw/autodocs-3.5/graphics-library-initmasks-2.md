# graphics.library/InitMasks



   NAME
	InitMasks -- Initialize the BorderLine and CollMask masks of a [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71).

   SYNOPSIS
	InitMasks(vs)
	          A0

	void InitMasks(struct [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) *);

   FUNCTION
	Creates the appropriate BorderLine and CollMask masks of the [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71).
	Correctly detects if the [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) is actually a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138) definition, handles
	the image data accordingly.

   INPUTS
	vs = pointer to the [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71) structure

   RESULT

   BUGS

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html)

