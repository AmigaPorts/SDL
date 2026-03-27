---
title: datatypes.library/ReleaseDTDrawInfo
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-releasedtdrawinfo
functions: []
libraries: []
---

# datatypes.library/ReleaseDTDrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ReleaseDTDrawInfo - Release a DataTypes object from drawing. (V44)

    SYNOPSIS
	ReleaseDTDrawInfo (o, handle);
			   a0 a1

	VOID ReleaseDTDrawInfo (Object *, APTR);

    FUNCTION
	This function is used to release the information obtained
	with [ObtainDTDrawInfoA()](autodocs-3.5/datatypes-library-obtaindtdrawinfoa.md).

	This function invokes the object's DTM_RELEASEDRAWINFO method
	using the [opMember](autodocs-3.5/include-intuition-classusr-h.md) message structure.

    INPUTS
	handle - Pointer to an object returned by [ObtainDTDrawInfoA()](autodocs-3.5/datatypes-library-obtaindtdrawinfoa.md).

    SEE ALSO
	[DrawDTObjectA()](autodocs-3.5/datatypes-library-drawdtobjecta.md), ObtainDTDrawInfo()

