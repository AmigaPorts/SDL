---
title: amiga.lib/DoSuperMethodA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-dosupermethoda-2
functions: []
libraries: []
---

# amiga.lib/DoSuperMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DoSuperMethodA -- Perform method on object coerced to superclass.

   SYNOPSIS
	result = DoSuperMethodA( cl, obj, msg )

	ULONG DoSuperMethodA( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [Msg](autodocs-3.5/include-intuition-classusr-h.md) );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object, as though it were the superclass
	of the specified class.

   INPUTS
	cl - pointer to boopsi class whose superclass is to
	    receive the message
	obj - pointer to boopsi object
	msg - pointer to method-specific message to send

   RESULT
	result - class and message-specific result.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.
	Some early example code may refer to this function as DSM().

   SEE ALSO
	[CoerceMethodA()](autodocs-3.5/amiga-lib-coercemethoda-2.md), [DoMethodA()](autodocs-3.5/amiga-lib-domethoda-2.md), [DoSuperMethod()](autodocs-3.5/amiga-lib-dosupermethod-2.md), [<intuition/classusr.h>](autodocs-3.5/include-intuition-classusr-h.md)
	ROM Kernel Manual boopsi section

