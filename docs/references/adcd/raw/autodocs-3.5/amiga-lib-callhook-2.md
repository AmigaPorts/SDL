# amiga.lib/CallHook



   NAME
	CallHook -- Invoke a hook given a message on the stack.

   SYNOPSIS
	result = CallHook( hookPtr, obj, ... )

	ULONG CallHook( struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, ... );

   FUNCTION
	Like [CallHookA()](../Includes_and_Autodocs_3._guide/node0025.html), CallHook() invoke a hook on the supplied
	hook-specific data (an "object") and a parameter packet ("message").
	However, CallHook() allows you to build the message on your stack.

   INPUTS
	hookPtr - A system-standard hook
	obj - hook-specific data object
	... - The hook-specific message you wish to send.  The hook is
	    expecting a pointer to the message, so a pointer into your
	    stack will be sent.

   RESULT
	result - a hook-specific result.

   NOTES
	This function first appeared in the V37 release of amiga.lib.
	However, it does not depend on any particular version of the OS,
	and works fine even in V34.

   EXAMPLE
	If your hook's message was

	    struct myMessage
	    {
		ULONG mm_FirstGuy;
		ULONG mm_SecondGuy;
		ULONG mm_ThirdGuy;
	    };

	You could write:

	    result = CallHook( hook, obj, firstguy, secondguy, thirdguy );

	as a shorthand for:

	    struct myMessage msg;

	    msg.mm_FirstGuy = firstguy;
	    msg.mm_SecondGuy = secondguy;
	    msg.mm_ThirdGuy = thirdguy;

	    result = CallHookA( hook, obj, &msg );

   SEE ALSO
	[CallHookA()](../Includes_and_Autodocs_3._guide/node0025.html), [utility.library/CallHookPkt()](../Includes_and_Autodocs_3._guide/node0599.html), [<utility/hooks.h>](../Includes_and_Autodocs_3._guide/node0617.html)

