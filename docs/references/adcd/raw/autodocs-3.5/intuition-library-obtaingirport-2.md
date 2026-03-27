# intuition.library/ObtainGIRPort



    NAME
	ObtainGIRPort -- Set up a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) for a custom gadget. (V36)

    SYNOPSIS
	RPort = ObtainGIRPort( GInfo )
	D0		       A0

	struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *ObtainGIRPort( struct [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) * );

    FUNCTION
	Sets up a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) for use (only) by custom gadget hook routines.
	This function must be called EACH time a hook routine needing
	to perform gadget rendering is called, and must be accompanied
	by a corresponding call to [ReleaseGIRPort()](../Includes_and_Autodocs_3._guide/node03DF.html).

	Note that if a hook function passes you a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) pointer,
	e.g., GM_RENDER, you needn't call ObtainGIRPort() in that case.

    INPUTS
	A pointer to a [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) structure, as passed to each custom
	gadget hook function.

    RESULT
	A pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) that may be used for gadget rendering.
	This pointer may be NULL, in which case you should do no rendering.
	You may (optionally) pass a null return value to [ReleaseGIRPort()](../Includes_and_Autodocs_3._guide/node03DF.html).

    BUGS

    SEE ALSO
	[ReleaseGIRPort()](../Includes_and_Autodocs_3._guide/node03DF.html), [Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) documentation

