---
title: amiga.lib/DoSuperMethod
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-dosupermethod-2
functions: []
libraries: []
---

# amiga.lib/DoSuperMethod

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DoSuperMethod -- Perform method on object coerced to superclass.

   SYNOPSIS
	result = DoSuperMethod( cl, obj, MethodID, ... )

	ULONG DoSuperMethod( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, ULONG, ... );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object, as though it were the superclass
	of the specified class.  Equivalent to [DoSuperMethodA()](autodocs-3.5/amiga-lib-dosupermethoda-2.md),
	but allows you to build the message on the stack.

   INPUTS
	cl - pointer to boopsi class whose superclass is to
	    receive the message
	obj - pointer to boopsi object
	... - method-specific message built on the stack

   RESULT
	result - class and message-specific result.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.

   SEE ALSO
	[CoerceMethodA()](autodocs-3.5/amiga-lib-coercemethoda-2.md), [DoMethodA()](autodocs-3.5/amiga-lib-domethoda-2.md), [DoSuperMethodA()](autodocs-3.5/amiga-lib-dosupermethoda-2.md), [<intuition/classusr.h>](autodocs-3.5/include-intuition-classusr-h.md)
	ROM Kernel Manual boopsi section

