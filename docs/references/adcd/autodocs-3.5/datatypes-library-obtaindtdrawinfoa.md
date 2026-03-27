---
title: datatypes.library/ObtainDTDrawInfoA
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-obtaindtdrawinfoa
functions: []
libraries: []
---

# datatypes.library/ObtainDTDrawInfoA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ObtainDTDrawInfoA - Obtain a DataTypes object for drawing. (V44)

    SYNOPSIS
	handle = ObtainDTDrawInfoA (o, attrs);
	d0			    a0 a1

	[APTR](autodocs-3.5/include-exec-types-h.md) ObtainDTDrawInfoA (Object *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	handle = ObtainDTDrawInfo (o, tag1, ...);

	[APTR](autodocs-3.5/include-exec-types-h.md) ObtainDTDrawInfo (Object *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

    FUNCTION
	This function is used to prepare a DataTypes object for
	drawing into a [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

	This function will send the DTM_OBTAINDRAWINFO method
	to the object using the [opSet](autodocs-3.5/include-intuition-classusr-h.md) message structure.

    INPUTS
	o - Pointer to an object as returned by [NewDTObjectA()](autodocs-3.5/datatypes-library-newdtobjecta.md).
	attrs - Additional attributes.

    RETURNS
	Returns a opaque handle that must be passed to [ReleaseDTDrawInfo()](autodocs-3.5/datatypes-library-releasedtdrawinfo.md)
	when the application is done drawing the object.

    NOTE
	This function implies a layout operation. Thus, you must not
	add the object in question to a window or requester and use
	ObtainDTDrawInfo() on it.

    TAGS
	none defined at this time.

    SEE ALSO
	[DrawDTObjectA()](autodocs-3.5/datatypes-library-drawdtobjecta.md), [ReleaseDTDrawInfo()](autodocs-3.5/datatypes-library-releasedtdrawinfo.md)

