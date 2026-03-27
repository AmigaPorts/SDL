# intuition.library/SetAttrsA



    NAME
	SetAttrsA -- Specify attribute values for an object. (V36)
	SetAttrs -- Varargs stub for SetAttrsA(). (V36)

    SYNOPSIS
	result = SetAttrsA( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18), TagList )
	D0                  A0      A1

	ULONG SetAttrsA( [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) * );

	result = SetAttrs( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18), Tag1, ... )

	ULONG SetAttrs( [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ULONG, ... );

    FUNCTION
	Specifies a set of attribute/value pairs with meaning as
	defined by a 'boopsi' object's class.

	This function does not provide enough context information or
	arbitration for boopsi gadgets which are attached to windows
	or requesters.  For those objects, use SetGadgetAttrs().

    INPUTS
	[Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) = abstract pointer to a boopsi object.
	TagList = array of [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) structures with attribute/value pairs.

    RESULT
	The object does whatever it wants with the attributes you provide.
	The return value tends to be non-zero if the changes would require
	refreshing gadget imagery, if the object is a gadget.

    NOTES
	This function invokes the OM_SET method with a NULL [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24)
	parameter.

    BUGS

    SEE ALSO
	[NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html), [DisposeObject()](../Includes_and_Autodocs_3._guide/node03A5.html), [GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html), [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

