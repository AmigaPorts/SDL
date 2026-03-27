# amiga.lib/HookEntry



   NAME
	HookEntry -- Assembler to HLL conversion stub for hook entry.

   SYNOPSIS
	result = HookEntry( struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) )
	D0                  A0             A2        A1

   FUNCTION
	By definition, a standard hook entry-point must receive the
	hook in A0, the object in A2, and the message in A1.  If your
	hook entry-point is written in a high-level language and is
	expecting its parameters on the stack, then HookEntry() will
	put the three parameters on the stack and invoke the function
	stored in the hook h_SubEntry field.

	This function is only useful to hook implementers, and is
	never called from C.

   INPUTS
	hook - pointer to hook being invoked
	object - pointer to hook-specific data
	msg - pointer to hook-specific message

   RESULT
	result - a hook-specific result.

   NOTES
	This function first appeared in the V37 release of amiga.lib.
	However, it does not depend on any particular version of the OS,
	and works fine even in V34.

   EXAMPLE
	If your hook dispatcher is this:

	dispatch( struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *hookPtr, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *obj, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) msg )
	{
	    ...
	}

	Then when you initialize your hook, you would say:

	myhook.h_Entry = HookEntry;	/* amiga.lib stub */
	myhook.h_SubEntry = dispatch;	/* HLL entry */

   SEE ALSO
	[CallHook()](../Includes_and_Autodocs_3._guide/node0024.html), [CallHookA()](../Includes_and_Autodocs_3._guide/node0025.html), [<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html)

