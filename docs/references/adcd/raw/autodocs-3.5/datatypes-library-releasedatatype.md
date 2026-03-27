# datatypes.library/ReleaseDataType



    NAME
	ReleaseDataType - Release a [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) structure.         (V39)

    SYNOPSIS
	ReleaseDataType (dtn);
		      a0

	VOID ReleaseDataType (struct [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) *);

    FUNCTION
	This function is used to release a [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) structure obtained
	by [ObtainDataTypeA()](../Includes_and_Autodocs_3._guide/node0112.html).

    INPUTS
	dtn - [DataType](../Includes_and_Autodocs_3._guide/node05F7.html#line174) structure returned by [ObtainDataTypeA()](../Includes_and_Autodocs_3._guide/node0112.html).  NULL
	    is a valid input.

    SEE ALSO
	[ObtainDataTypeA()](../Includes_and_Autodocs_3._guide/node0112.html)

