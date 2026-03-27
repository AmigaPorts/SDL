---
title: datatypes.library/ReleaseDataType
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-releasedatatype
functions: []
libraries: []
---

# datatypes.library/ReleaseDataType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ReleaseDataType - Release a [DataType](autodocs-3.5/include-datatypes-datatypes-h.md) structure.         (V39)

    SYNOPSIS
	ReleaseDataType (dtn);
		      a0

	VOID ReleaseDataType (struct [DataType](autodocs-3.5/include-datatypes-datatypes-h.md) *);

    FUNCTION
	This function is used to release a [DataType](autodocs-3.5/include-datatypes-datatypes-h.md) structure obtained
	by [ObtainDataTypeA()](autodocs-3.5/datatypes-library-obtaindatatypea.md).

    INPUTS
	dtn - [DataType](autodocs-3.5/include-datatypes-datatypes-h.md) structure returned by [ObtainDataTypeA()](autodocs-3.5/datatypes-library-obtaindatatypea.md).  NULL
	    is a valid input.

    SEE ALSO
	[ObtainDataTypeA()](autodocs-3.5/datatypes-library-obtaindatatypea.md)

