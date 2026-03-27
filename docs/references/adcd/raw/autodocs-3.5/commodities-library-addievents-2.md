# commodities.library/AddIEvents



   NAME
	AddIEvents -- add input events to commodities' input stream. (V36)

   SYNOPSIS
	AddIEvents(events)
		   A0

	VOID AddIEvents(struct [InputEvent](../Includes_and_Autodocs_3._guide/node061A.html#line256) *);

   FUNCTION
	This function adds a null-terminated linked list of input events to
	the input stream processed by commodities. It is a touch easier than
	using the input device directly.

	The contents of the input events are copied into commodity messages,
	so they may be disposed of as soon as this call returns.

	The messages are initially routed to the first broker in
	commodities' object list.

   INPUTS
	events - the list of input events to add (may be NULL)

   WARNING
	The [cx_lib/InvertString()](../Includes_and_Autodocs_3._guide/node0042.html) function creates lists of input events that
	are in reverse order. Thus, passing the result of [InvertString()](../Includes_and_Autodocs_3._guide/node0042.html)
	to this function will insert a series of input events that will
	generate a string that's a mirror image of the string passed to
	[InvertString()](../Includes_and_Autodocs_3._guide/node0042.html) originally.

	The solution to the above is to either flip the string before
	passing it to [InvertString()](../Includes_and_Autodocs_3._guide/node0042.html), or flip the resulting list of input
	events.

   BUGS
	Prior to V40, this function did not copy the data pointed to by
	ie_EventAddress for any events of type IECLASS_NEWPOINTERPOS.

   SEE ALSO
	[cx_lib/FreeIEvents()](../Includes_and_Autodocs_3._guide/node003E.html)

