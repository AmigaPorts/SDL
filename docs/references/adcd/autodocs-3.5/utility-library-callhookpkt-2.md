---
title: utility.library/CallHookPkt
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-callhookpkt-2
functions: []
libraries: []
---

# utility.library/CallHookPkt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CallHookPkt -- invoke a [Hook](autodocs-3.5/include-utility-hooks-h.md) function callback. (V36)

   SYNOPSIS
	return = CallHookPkt(hook,object,message);
	D0		     A0   A2	 A1

	ULONG CallHookPkt(struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *,[APTR](autodocs-3.5/include-exec-types-h.md),APTR);

   FUNCTION
	Performs the callback standard defined by a [Hook](autodocs-3.5/include-utility-hooks-h.md) structure.
	This function is really very simple; it effectively performs
	a JMP to Hook->h_Entry.

	It is probably just as well to do this operation in an
	assembly language function linked in to your program, possibly
	from a compiler supplied library or a builtin function.

	It is anticipated that C programs will often call a 'varargs'
	variant of this function which will be named [CallHook](autodocs-3.5/amiga-lib-callhook-2.md). This
	function must be provided in a compiler specific library, but
	an example of use would be:

	result = CallHook(hook,dataobject,COMMAND_ID,param1,param2);

	The function [CallHook()](autodocs-3.5/amiga-lib-callhook-2.md) can be implemented in many C compilers
	like this:

	ULONG CallHook(struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *hook, [APTR](autodocs-3.5/include-exec-types-h.md) object, ULONG command, ... )
	{
	    return(CallHookPkt(hook,object,(APTR)&command));
	}

   INPUTS
	hook - pointer to an initialized [Hook](autodocs-3.5/include-utility-hooks-h.md) structure as defined in
	       [<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md)
	object - useful data structure in the particular context the hook is
		 being used for.
	message - pointer to a message to be passed to the hook. This is not
		  an Exec [Message](autodocs-3.5/include-exec-ports-h.md) structure, but is a message in the OOP sense.

   RESULTS
	return - the value returned by the hook function.

   WARNING
	The functions called through this function should follow normal
	register conventions unless EXPLICITLY documented otherwise (and
	they have a good reason too).

   SEE ALSO
	[<utility/hooks.h>](autodocs-3.5/include-utility-hooks-h.md)

