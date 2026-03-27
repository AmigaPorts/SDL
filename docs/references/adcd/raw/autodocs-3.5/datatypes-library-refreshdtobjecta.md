# datatypes.library/RefreshDTObjectA



    NAME
	RefreshDTObjectA - Refresh a datatypes object.          (V39)

    SYNOPSIS
	RefreshDTObjectA (object, window, req, attrs)
			   a0	   a1	   a2	a3

	VOID RefreshDTObjectA (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
			        struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	RefreshDTObject (object, window, req, tag1, ...);

	VOID RefreshDTObject (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
			       struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1, ...);

    FUNCTION
	Refreshes the specified object, by sending the GM_RENDER method to
	the object.

    INPUTS
	object - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

	window - Pointer to the window.

	req - Must be NULL.

	attrs - Additional attributes (currently none are defined).

    SEE ALSO
	[AddDTObject()](../Includes_and_Autodocs_3._guide/node0108.html), [RemoveDTObject()](../Includes_and_Autodocs_3._guide/node0118.html), [intuition.library/RefreshGList()](../Includes_and_Autodocs_3._guide/node03DD.html)

