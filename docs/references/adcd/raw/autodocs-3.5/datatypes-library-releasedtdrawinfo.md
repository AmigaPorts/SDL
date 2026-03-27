# datatypes.library/ReleaseDTDrawInfo



    NAME
	ReleaseDTDrawInfo - Release a DataTypes object from drawing. (V44)

    SYNOPSIS
	ReleaseDTDrawInfo (o, handle);
			   a0 a1

	VOID ReleaseDTDrawInfo (Object *, APTR);

    FUNCTION
	This function is used to release the information obtained
	with [ObtainDTDrawInfoA()](../Includes_and_Autodocs_3._guide/node0113.html).

	This function invokes the object's DTM_RELEASEDRAWINFO method
	using the [opMember](../Includes_and_Autodocs_3._guide/node0636.html#line122) message structure.

    INPUTS
	handle - Pointer to an object returned by [ObtainDTDrawInfoA()](../Includes_and_Autodocs_3._guide/node0113.html).

    SEE ALSO
	[DrawDTObjectA()](../Includes_and_Autodocs_3._guide/node010C.html), ObtainDTDrawInfo()

