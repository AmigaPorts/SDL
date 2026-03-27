# datatypes.library/GetDTAttrsA



    NAME
	GetDTAttrsA - Obtain attributes for an object.          (V39)

    SYNOPSIS
	retval = GetDTAttrsA (o, attrs);
	d0		      a0  a2

	ULONG GetDTAttrsA (Object *, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	retval = GetDTAttrs (o, tag1, ...);

	ULONG GetDTAttrs (Object *, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29) tag1, ...);

    FUNCTION
	This function is used to get the attributes of a data type
	object.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

	attrs - Attributes to get, terminated with TAG_DONE.  The data
	    element of each pair contains the address of the storage
	    variable.

    RETURNS
	retval - Contains the number of attributes the system was able
	    to obtain.

    SEE ALSO
	[SetDTAttrsA()](../Includes_and_Autodocs_3._guide/node0119.html), [intuition.library/GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html)

