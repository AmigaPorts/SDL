---
title: amiga.lib/CallHook
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-callhook-2
functions: [CallHookPkt]
libraries: [utility.library]
---

# amiga.lib/CallHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CallHook -- Invoke a hook given a message on the stack.

   SYNOPSIS
	result = CallHook( hookPtr, obj, ... )

	ULONG CallHook( struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, ... );

   FUNCTION
	Like [CallHookA()](autodocs-3.5/amiga-lib-callhooka-2.md), CallHook() invoke a hook on the supplied
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
	[CallHookA()](autodocs-3.5/amiga-lib-callhooka-2.md), [utility.library/CallHookPkt()](autodocs-3.5/utility-library-callhookpkt-2.md), [<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md)

---

## See Also

- [CallHookPkt — utility.library](../autodocs/utility.library.md#callhookpkt)
