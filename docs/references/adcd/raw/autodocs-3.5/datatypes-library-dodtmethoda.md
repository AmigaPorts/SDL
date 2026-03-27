# datatypes.library/DoDTMethodA



    NAME
	DoDTMethodA - Do a datatypes method.                    (V39)

    SYNOPSIS
	retval = DoDTMethodA (o, win, req, msg);
	d0		      a0 a1   a2   a3

	ULONG DoDTMethodA (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
			   struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, Msg);

	retval = DoDTMethod (o, win, req, data, ...);

	ULONG DoDTMethod (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
			  struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, ULONG, ...);

    FUNCTION
	This function is used to perform a datatypes method.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

	win - [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) that the object is attached to.

	req - [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) that the object is attached to.

	msg - The message to send to the object.

    RETURNS
	Returns the value returned by the method.

    SEE ALSO
	intuition.library/DoGadgetMethod()

