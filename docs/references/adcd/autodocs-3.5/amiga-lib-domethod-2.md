---
title: amiga.lib/DoMethod
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-domethod-2
functions: []
libraries: []
---

# amiga.lib/DoMethod

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DoMethod -- Perform method on object.

   SYNOPSIS
	result = DoMethod( obj, MethodID, ... )

	ULONG DoMethod( [Object](autodocs-3.5/include-intuition-classusr-h.md) *, ULONG, ... );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object.  The message is invoked on the
	object's true class.  Equivalent to [DoMethodA()](autodocs-3.5/amiga-lib-domethoda-2.md), but allows
	you to build the message on the stack.

   INPUTS
	obj - pointer to boopsi object
	MethodID - which method to send (see [<intuition/classusr.h>](autodocs-3.5/include-intuition-classusr-h.md))
	... - method-specific message built on the stack

   RESULT
	result - specific to the message and the object's class.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.

   SEE ALSO
	[DoMethodA()](autodocs-3.5/amiga-lib-domethoda-2.md), [CoerceMethodA()](autodocs-3.5/amiga-lib-coercemethoda-2.md), [DoSuperMethodA()](autodocs-3.5/amiga-lib-dosupermethoda-2.md), [<intuition/classusr.h>](autodocs-3.5/include-intuition-classusr-h.md)
	ROM Kernel Manual boopsi section

