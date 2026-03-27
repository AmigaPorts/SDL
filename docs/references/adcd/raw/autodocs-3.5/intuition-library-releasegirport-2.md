# intuition.library/ReleaseGIRPort



    NAME
	ReleaseGIRPort -- Release a custom gadget [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53). (V36)

    SYNOPSIS
	ReleaseGIRPort( RPort )
			A0

	VOID ReleaseGIRPort( struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) * );

    FUNCTION
	The corresponding function to [ObtainGIRPort()](../Includes_and_Autodocs_3._guide/node03CE.html), it releases
	arbitration used by Intuition for gadget RastPorts.

    INPUTS
	Pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) returned by [ObtainGIRPort()](../Includes_and_Autodocs_3._guide/node03CE.html).
	This pointer can be NULL, in which case nothing happens.

    RESULT
	None

    BUGS

    SEE ALSO
	[ObtainGIRPort()](../Includes_and_Autodocs_3._guide/node03CE.html), [Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) documentation

