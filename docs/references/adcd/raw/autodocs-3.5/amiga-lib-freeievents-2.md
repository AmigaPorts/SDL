# amiga.lib/FreeIEvents



   NAME
	FreeIEvents -- free a chain of input events allocated by
		       [InvertString()](../Includes_and_Autodocs_3._guide/node0042.html). (V36)

   SYNOPSIS
	FreeIEvents(events)

	VOID FreeIEvents(struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *);

   FUNCTION
	This function frees a linked list of input events as obtained from
	[InvertString()](../Includes_and_Autodocs_3._guide/node0042.html).

   INPUTS

       events - the list of input events to free, may be NULL.
   SEE ALSO
	[InvertString()](../Includes_and_Autodocs_3._guide/node0042.html)

