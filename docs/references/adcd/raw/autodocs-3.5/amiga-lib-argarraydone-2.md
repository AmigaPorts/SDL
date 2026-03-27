# amiga.lib/ArgArrayDone



   NAME
	ArgArrayDone -- release the memory allocated by a previous call
			to [ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html). (V36)

   SYNOPSIS
	ArgArrayDone();

	VOID ArgArrayDone(VOID);

   FUNCTION
	This function frees memory and does cleanup required after a
	call to [ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html). Don't call this until you are done using
	the ToolTypes argument strings.

   SEE ALSO
	[ArgArrayInit()](../Includes_and_Autodocs_3._guide/node001F.html)

