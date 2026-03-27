# intuition.library/GetAttr



    NAME
	GetAttr -- Inquire the value of some attribute of an object. (V36)

    SYNOPSIS
	attr = GetAttr( AttrID, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18), StoragePtr )
	D0		D0	A0	A1

	ULONG GetAttr( ULONG, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ULONG * );

    FUNCTION
	Inquires from the specified object the value of the specified attribute.

	You always pass the address of a long variable, which will
	receive the same value that would be passed to SetAttrs() in
	the ti_Data portion of a [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) element.  See the documentation
	for the class for exceptions to this general rule.

	Not all attributes will respond to this function.  Those that
	will are documented on a class-by-class basis.

    INPUTS
	AttrID = the attribute tag ID understood by the object's class
	[Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) = abstract pointer to the boopsi object you are interested in
	StoragePtr = pointer to appropriate storage for the answer

    RESULT
	Returns FALSE (0) if the inquiries of attribute are not provided
	by the object's class.

    NOTES
	This function invokes the OM_GET method of the object.

    BUGS

    SEE ALSO
	[NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html), [DisposeObject()](../Includes_and_Autodocs_3._guide/node03A5.html), SetAttrs(), [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

