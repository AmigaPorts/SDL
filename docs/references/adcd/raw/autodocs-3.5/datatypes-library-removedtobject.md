# datatypes.library/RemoveDTObject



    NAME
	RemoveDTObject - [Remove](../Includes_and_Autodocs_3._guide/node022F.html) an object from a window.        (V39)

    SYNOPSIS
	position = RemoveDTObject (window, object);
	d0			    a0	    a1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) RemoveDTObject (struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *);

    FUNCTION
	Removes the object from the window's object list.  This will wait
	until the AsyncLayout process is complete.  The object will
	receive a DTM_REMOVEDTOBJECT message to inform the object it has
	been removed.

    INPUTS
	window - Pointer to the window.

	object - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

    RETURNS
	Returns the ordinal position of the removed object.  If the
	object wasn't found in the appropriate list then a -1 is
	returned.

    SEE ALSO
	[AddDTObject()](../Includes_and_Autodocs_3._guide/node0108.html), [intuition.library/RemoveGList()](../Includes_and_Autodocs_3._guide/node03E3.html)

