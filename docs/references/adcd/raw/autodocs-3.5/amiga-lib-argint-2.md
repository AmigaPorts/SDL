# amiga.lib/ArgInt



   NAME
	ArgInt -- return an integer value from a ToolTypes array. (V36)

   SYNOPSIS
	value = ArgInt(tt,entry,defaultval)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ArgInt(UBYTE **,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),LONG);

   FUNCTION
	This function looks in the ToolTypes array 'tt' returned
	by [ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html) for 'entry' and returns the value associated
	with it. 'tt' is in standard ToolTypes format such as:

		ENTRY=Value

	The Value string is passed to atoi() and the result is returned by
	this function.

	If 'entry' is not found, the integer 'defaultval' is returned.

   INPUTS
	tt - a ToolTypes array as returned by [ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html)
	entry - the entry in the ToolTypes array to search for
	defaultval - the value to return in case 'entry' is not found within
		     the ToolTypes array

   RESULTS
	value - the value associated with 'entry', or defaultval if 'entry'
		is not in the ToolTypes array

   NOTES
	This function requires that dos.library V36 or higher be opened.

   SEE ALSO
	[ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html)

