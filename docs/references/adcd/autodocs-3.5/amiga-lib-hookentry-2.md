---
title: amiga.lib/HookEntry
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-hookentry-2
functions: []
libraries: []
---

# amiga.lib/HookEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	HookEntry -- Assembler to HLL conversion stub for hook entry.

   SYNOPSIS
	result = HookEntry( struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [APTR](autodocs-3.5/include-exec-types-h.md) )
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

	dispatch( struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *hookPtr, [Object](autodocs-3.5/include-intuition-classusr-h.md) *obj, [APTR](autodocs-3.5/include-exec-types-h.md) msg )
	{
	    ...
	}

	Then when you initialize your hook, you would say:

	myhook.h_Entry = HookEntry;	/* amiga.lib stub */
	myhook.h_SubEntry = dispatch;	/* HLL entry */

   SEE ALSO
	[CallHook()](autodocs-3.5/amiga-lib-callhook-2.md), [CallHookA()](autodocs-3.5/amiga-lib-callhooka-2.md), [<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md)

