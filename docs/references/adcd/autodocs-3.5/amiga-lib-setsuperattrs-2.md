---
title: amiga.lib/SetSuperAttrs
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-setsuperattrs-2
functions: []
libraries: []
---

# amiga.lib/SetSuperAttrs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetSuperAttrs -- Invoke OM_SET method on superclass with varargs.

   SYNOPSIS
	result = SetSuperAttrs( cl, obj, tag, ... )

	ULONG SetSuperAttrs( struct [IClass](autodocs-3.5/include-intuition-classes-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, ULONG, ... );

   FUNCTION
	Boopsi support function which invokes the OM_SET method on the
	superclass of the supplied class for the supplied object.  Allows
	the ops_AttrList to be supplied on the stack (i.e. in a varargs
	way).  The equivalent non-varargs function would simply be

	    DoSuperMethod( cl, obj, OM_SET, taglist, NULL );

   INPUTS
	cl - pointer to boopsi class whose superclass is to
	    receive the OM_SET message
	obj - pointer to boopsi object
	tag - list of tag-attribute pairs, ending in TAG_DONE

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

