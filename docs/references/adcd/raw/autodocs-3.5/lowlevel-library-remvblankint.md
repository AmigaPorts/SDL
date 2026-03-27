# lowlevel.library/RemVBlankInt



   NAME
	RemVBlankInt -- remove a previously installed vertical blank routine.
			(V40)

   SYNOPSIS
	RemVBlankInt(intHandle);
		     A1

	VOID RemVBlankInt(APTR);

   FUNCTION
	Removes a vertical blank interrupt routine previously added with
	[AddVBlankInt()](../Includes_and_Autodocs_3._guide/node0463.html).

   INPUTS
	intHandle - handle obtained from [AddVBlankInt()](../Includes_and_Autodocs_3._guide/node0463.html). This may be NULL,
		    in which case this function does nothing.

   SEE ALSO
	[AddVBlankInt()](../Includes_and_Autodocs_3._guide/node0463.html)

