# lowlevel.library/RemKBInt



  NAME
	RemKBInt -- remove a previously installed keyboard interrupt. (V40)

  SYNOPSIS
	RemKBInt(intHandle);
	         A1

	VOID RemKBInt(APTR);

  FUNCTION
	[Remove](../Includes_and_Autodocs_3._guide/node022F.html) a keyboard interrupt routine previously added with [AddKBInt()](../Includes_and_Autodocs_3._guide/node0461.html).

  INPUTS
	intHandle - handle obtained from [AddKBInt()](../Includes_and_Autodocs_3._guide/node0461.html). This may be NULL,
		    in which case this function does nothing.

  SEE ALSO
	[AddKBInt()](../Includes_and_Autodocs_3._guide/node0461.html)

