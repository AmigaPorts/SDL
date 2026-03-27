# datatypes.library/SetDTAttrsA



    NAME
	SetDTAttrsA - Set attributes for an object.             (V39)

    SYNOPSIS
	retval = SetDTAttrsA (o, win, req, attrs);
	d0		      a0  a1   a2   a3

	ULONG SetDTAttrsA (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *,
			   struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	retval = SetDTAttrs (o, win, req, tag1, ...);

	ULONG SetDTAttrs (Object *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *,
			  [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1, ...);

    FUNCTION
	This function is used to set the attributes of a data type
	object.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

	win - [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) that the object has been added to.

	attrs - Attributes to set, terminated with TAG_DONE.

    TAGS
	see [<datatypes/datatypesclass.h>](../Includes_and_Autodocs_3._guide/node0606.html) for tags.

    SEE ALSO
	[GetDTAttrsA()](../Includes_and_Autodocs_3._guide/node010D.html), [intuition.library/SetGadgetAttrsA()](../Includes_and_Autodocs_3._guide/node03F1.html)

