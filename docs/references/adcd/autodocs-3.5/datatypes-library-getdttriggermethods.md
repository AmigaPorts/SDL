---
title: datatypes.library/GetDTTriggerMethods
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-getdttriggermethods
functions: []
libraries: []
---

# datatypes.library/GetDTTriggerMethods

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetDTTriggerMethods - Obtain trigger methods supported by an object
```c
                                                               (V39)

    SYNOPSIS
```
	methods = GetDTTriggerMethods (object);
	d0				a0

	struct DTMethods *GetDTTriggerMethods (Object *);

    FUNCTION
	This function is used to obtain a list of trigger methods that an
	object supports.  This is so that an application can provide
	the appropriate controls for an object.  For example, an AmigaGuide
	object needs controls for "Contents", "Index", "Retrace", "Browse <",
	and "Browse >",

    INPUTS
	object - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).

    RETURNS
	Returns a pointer to a NULL terminated [DTMethod](autodocs-3.5/include-datatypes-datatypesclass-h.md) list.  This list is
	only valid until the object is disposed off.

    EXAMPLE
	To call the method:

	    [DoMethod](autodocs-3.5/amiga-lib-domethod-2.md) (object, DTM_TRIGGER, dtm[button]->dtm_Method);

    SEE ALSO
	[GetDTMethods()](autodocs-3.5/datatypes-library-getdtmethods.md)

