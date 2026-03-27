# amiga.lib/ArgString



   NAME
	ArgString -- return a string pointer from a ToolTypes array. (V36)

   SYNOPSIS
	string = ArgString(tt,entry,defaultstring)

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) ArgString(UBYTE **,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),STRPTR);

   FUNCTION
	This function looks in the ToolTypes array 'tt' returned
	by [ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html) for 'entry' and returns the value associated
	with it. 'tt' is in standard ToolTypes format such as:

		ENTRY=Value

	This function returns a pointer to the Value string.

	If 'entry' is not found, 'defaultstring' is returned.

   INPUTS
	tt - a ToolTypes array as returned by [ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html)
	entry - the entry in the ToolTypes array to search for
	defaultstring - the value to return in case 'entry' is not found within
		        the ToolTypes array

   RESULTS
	value - the value associated with 'entry', or defaultstring if 'entry'
		is not in the ToolTypes array

   SEE ALSO
	[ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html)

