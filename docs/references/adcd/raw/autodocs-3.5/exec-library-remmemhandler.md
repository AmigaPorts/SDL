# exec.library/RemMemHandler



   NAME
	RemMemHandler - [Remove](../Includes_and_Autodocs_3._guide/node022F.html) low memory handler from exec              (V39)

   SYNOPSIS
	RemMemHandler(memHandler)
	              A1

	VOID RemMemHandler(struct [Interrupt](../Includes_and_Autodocs_3._guide/node061D.html#line21) *);

   FUNCTION
	This function removes the low memory handler from the system.
	This function can be called from within a handler.  If removing
	oneself, it is important that the handler returns MEM_ALL_DONE.

   NOTE
	When removing a handler, the handler may be called until this
	function returns.  Thus, the handler must still be valid until
	then.

   INPUTS
	memHandler - Pointer to a handler added with [AddMemHandler()](../Includes_and_Autodocs_3._guide/node01DC.html)

   SEE ALSO
	[AddMemHandler()](../Includes_and_Autodocs_3._guide/node01DC.html), exec/interrupts.i

