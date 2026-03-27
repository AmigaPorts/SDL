---
title: amiga.lib/CallHookA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-callhooka-2
functions: [CallHookPkt]
libraries: [utility.library]
---

# amiga.lib/CallHookA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CallHookA -- Invoke a hook given a pointer to a message.

   SYNOPSIS
	result = CallHookA( hookPtr, obj, message )

	ULONG CallHook( struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	Invoke a hook on the supplied hook-specific data (an "object")
	and a parameter packet ("message").  This function is equivalent
	to [utility.library/CallHookPkt()](autodocs-3.5/utility-library-callhookpkt-2.md).

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
	[CallHook()](autodocs-3.5/amiga-lib-callhook-2.md), [utility.library/CallHookPkt()](autodocs-3.5/utility-library-callhookpkt-2.md), [<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md)

---

## See Also

- [CallHookPkt — utility.library](../autodocs/utility.library.md#callhookpkt)
