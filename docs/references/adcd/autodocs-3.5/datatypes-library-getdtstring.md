---
title: datatypes.library/GetDTString
manual: autodocs-3.5
chapter: autodocs-3.5
section: datatypes-library-getdtstring
functions: []
libraries: []
---

# datatypes.library/GetDTString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	GetDTString - Obtain a DataTypes string.                (V39)

    SYNOPSIS
	str = GetDTString (id);
	d0		   d0

	[STRPTR](autodocs-3.5/include-exec-types-h.md) GetDTString (ULONG id);

    FUNCTION
	This function is used to obtain a pointer to a localized
	DataTypes string.

    INPUTS
	id - ID of the string to obtain.

    RETURNS
	A pointer to a NULL terminated string.


    SEE ALSO
