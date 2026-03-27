---
title: amiga.lib/CoerceMethodA
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-coercemethoda-2
functions: []
libraries: []
---

# amiga.lib/CoerceMethodA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CoerceMethodA -- Perform method on coerced object.

   SYNOPSIS
	result = CoerceMethodA( cl, obj, msg )

	ULONG CoerceMethodA( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, [Msg](autodocs-3.5/include-intuition-classusr-h.md) );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object, as though it were the specified
	class.

   INPUTS
	cl - pointer to boopsi class to receive the message
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
	Some early example code may refer to this function as CM().

   SEE ALSO
	[CoerceMethod()](autodocs-3.5/amiga-lib-coercemethod-2.md), [DoMethodA()](autodocs-3.5/amiga-lib-domethoda-2.md), [DoSuperMethodA()](autodocs-3.5/amiga-lib-dosupermethoda-2.md), [<intuition/classusr.h>](autodocs-3.5/include-intuition-classusr-h.md)
	ROM Kernel Manual boopsi section

