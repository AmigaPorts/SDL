# datatypes.library/DisposeDTObject



    NAME
	DisposeDTObject - Delete a data type object.            (V39)

    SYNOPSIS
	DisposeDTObject (o);
			 a0

	VOID DisposeDTObject (Object *);

    FUNCTION
	This function is used to dispose of a data type object that was
	obtained with [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).
	    NULL is a valid input.

    SEE ALSO
	[NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html)

