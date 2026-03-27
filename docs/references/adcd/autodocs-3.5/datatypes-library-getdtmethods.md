---
title: datatypes.library/GetDTMethods
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-getdtmethods
functions: []
libraries: []
---

# datatypes.library/GetDTMethods

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetDTMethods - Obtain methods an object supports.       (V39)

    SYNOPSIS
	methods = GetDTMethods (object);
	d0			a0

	ULONG GetDTMethods (Object *);

    FUNCTION
	This function is used to obtain a list of methods that an
	object supports.

    INPUTS
	object - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

    RETURNS
	Returns a pointer to a ~0 terminated ULONG array.  This array
	is only valid until the object is disposed off.

    SEE ALSO
	[GetDTTriggerMethods()](autodocs-3.5/datatypes-library-getdttriggermethods.md)

