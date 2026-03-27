---
title: datatypes.library/DisposeDTObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-disposedtobject
functions: []
libraries: []
---

# datatypes.library/DisposeDTObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DisposeDTObject - Delete a data type object.            (V39)

    SYNOPSIS
	DisposeDTObject (o);
			 a0

	VOID DisposeDTObject (Object *);

    FUNCTION
	This function is used to dispose of a data type object that was
	obtained with [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).
	    NULL is a valid input.

    SEE ALSO
	[NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md)

