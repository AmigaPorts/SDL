# datatypes.library/GetDTMethods



    NAME
	GetDTMethods - Obtain methods an object supports.       (V39)

    SYNOPSIS
	methods = GetDTMethods (object);
	d0			a0

	ULONG GetDTMethods (Object *);

    FUNCTION
	This function is used to obtain a list of methods that an
	object supports.

    INPUTS
	object - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

    RETURNS
	Returns a pointer to a ~0 terminated ULONG array.  This array
	is only valid until the object is disposed off.

    SEE ALSO
	[GetDTTriggerMethods()](../Includes_and_Autodocs_3._guide/node0110.html)

