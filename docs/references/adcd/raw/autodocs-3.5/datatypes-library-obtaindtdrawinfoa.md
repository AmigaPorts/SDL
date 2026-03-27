# datatypes.library/ObtainDTDrawInfoA



    NAME
	ObtainDTDrawInfoA - Obtain a DataTypes object for drawing. (V44)

    SYNOPSIS
	handle = ObtainDTDrawInfoA (o, attrs);
	d0			    a0 a1

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) ObtainDTDrawInfoA (Object *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	handle = ObtainDTDrawInfo (o, tag1, ...);

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) ObtainDTDrawInfo (Object *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
	This function is used to prepare a DataTypes object for
	drawing into a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

	This function will send the DTM_OBTAINDRAWINFO method
	to the object using the [opSet](../Includes_and_Autodocs_3._guide/node0636.html#line76) message structure.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).
	attrs - Additional attributes.

    RETURNS
	Returns a opaque handle that must be passed to [ReleaseDTDrawInfo()](../Includes_and_Autodocs_3._guide/node0117.html)
	when the application is done drawing the object.

    NOTE
	This function implies a layout operation. Thus, you must not
	add the object in question to a window or requester and use
	ObtainDTDrawInfo() on it.

    TAGS
	none defined at this time.

    SEE ALSO
	[DrawDTObjectA()](../Includes_and_Autodocs_3._guide/node010C.html), [ReleaseDTDrawInfo()](../Includes_and_Autodocs_3._guide/node0117.html)

