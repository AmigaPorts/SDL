# datatypes.library/AddDTObject



    NAME
	AddDTObject - Add an object to a window or requester.   (V39)

    SYNOPSIS
	realposition = AddDTObject (window, requester, object, position);
	d0			    a0      a1	       a2      d0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AddDTObject (struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *,
			  [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, LONG);

    FUNCTION
	This function adds a single object to the gadget list of the given
	window or requester at the position in the list specified by the
	position argument.

	When the object is added to the gadget list, the object will
	receive a GM_LAYOUT message with the gpl_Initial field set to
	one.

    INPUTS
	window - Pointer to the window.

	requester - Must be NULL.

	object - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

	position - Integer position in the list for the new gadget.
	    -1 to add to the end of the list.

    RETURNS
	Returns the position of where the object was actually added.

    SEE ALSO
	[RemoveDTObject()](../Includes_and_Autodocs_3._guide/node0118.html), [intuition.library/AddGList()](../Includes_and_Autodocs_3._guide/node0393.html)

