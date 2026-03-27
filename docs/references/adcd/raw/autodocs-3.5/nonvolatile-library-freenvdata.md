# nonvolatile.library/FreeNVData



   NAME
	FreeNVData -- release the memory allocated by a function of this
		      library. (V40)

   SYNOPSIS
	FreeNVData(data);
		   A0

	VOID FreeNVData(APTR);

   FUNCTION
	Frees a block of memory that was allocated by any of the following:
	[GetCopyNV()](../Includes_and_Autodocs_3._guide/node04DE.html), [GetNVInfo()](../Includes_and_Autodocs_3._guide/node04DF.html), [GetNVList()](../Includes_and_Autodocs_3._guide/node04E0.html).

   INPUTS
	data - pointer to the memory block to be freed. If passed NULL,
	       this function does nothing.

   SEE ALSO
	[GetCopyNV()](../Includes_and_Autodocs_3._guide/node04DE.html), [GetNVInfo()](../Includes_and_Autodocs_3._guide/node04DF.html), [GetNVList()](../Includes_and_Autodocs_3._guide/node04E0.html)

