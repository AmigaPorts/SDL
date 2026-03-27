---
title: dos.library/SetOwner
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setowner
functions: []
libraries: []
---

# dos.library/SetOwner

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	SetOwner -- Set owner information for a file or directory (V39)

    SYNOPSIS
	success = SetOwner( name, owner_info )
	D0		     D1       D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetOwner (STRPTR, LONG)

    FUNCTION
	SetOwner() sets the owner information for the file or directory.
	This value is a 32-bit value that is normally split into 16 bits
	of owner user id (bits 31-16), and 16 bits of owner group id (bits
	15-0).  However, other than returning them as shown by Examine()/
	[ExNext()/ExAll()](autodocs-3.5/dos-library-exall-2.md), the filesystem take no interest in the values.
	These are primarily for use by networking software (clients and
	hosts), in conjunction with the FIBF_OTR_xxx and FIBF_GRP_xxx
	protection bits.

	This entrypoint did not exist in V36, so you must open at least V37
	dos.library to use it.  V37 dos.library will return FALSE to this
	call.

    INPUTS
	name	   - pointer to a null-terminated string
	owner_info - owner uid (31:16) and group id (15:0)

    RESULTS
	success - boolean

    SEE ALSO
	SetProtect(), [Examine()](autodocs-3.5/dos-library-examine-2.md), [ExNext()](autodocs-3.5/dos-library-exnext-2.md), [ExAll()](autodocs-3.5/dos-library-exall-2.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md)

