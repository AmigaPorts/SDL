# amiga.lib/CallHookA



   NAME
	CallHookA -- Invoke a hook given a pointer to a message.

   SYNOPSIS
	result = CallHookA( hookPtr, obj, message )

	ULONG CallHook( struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) );

   FUNCTION
	Invoke a hook on the supplied hook-specific data (an "object")
	and a parameter packet ("message").  This function is equivalent
	to [utility.library/CallHookPkt()](../Includes_and_Autodocs_3._guide/node0599.html).

   INPUTS
	hookPtr - A system-standard hook
	obj - hook-specific data object
	message - The hook-specific message you wish to send

   RESULT
	result - a hook-specific result.

   NOTES
	This function first appeared in the V37 release of amiga.lib.
	However, it does not depend on any particular version of the OS,
	and works fine even in V34.

   SEE ALSO
	[CallHook()](../Includes_and_Autodocs_3._guide/node0024.html), [utility.library/CallHookPkt()](../Includes_and_Autodocs_3._guide/node0599.html), [<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html)

