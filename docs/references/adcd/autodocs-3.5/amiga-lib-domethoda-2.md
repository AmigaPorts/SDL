---
title: amiga.lib/DoMethodA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-domethoda-2
functions: []
libraries: []
---

# amiga.lib/DoMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DoMethodA -- Perform method on object.

   SYNOPSIS
	result = DoMethodA( obj, msg )

	ULONG DoMethodA( [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [Msg](autodocs-3.5/include-intuition-classusr-h.md) );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object.  The message is invoked on the
	object's true class.

   INPUTS
	obj - pointer to boopsi object
	msg - pointer to method-specific message to send

   RESULT
	result - specific to the message and the object's class.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.
	Some early example code may refer to this function as DM().

   SEE ALSO
	[DoMethod()](autodocs-3.5/amiga-lib-domethod-2.md), [CoerceMethodA()](autodocs-3.5/amiga-lib-coercemethoda-2.md), [DoSuperMethodA()](autodocs-3.5/amiga-lib-dosupermethoda-2.md), [<intuition/classusr.h>](autodocs-3.5/include-intuition-classusr-h.md)
	ROM Kernel Manual boopsi section

