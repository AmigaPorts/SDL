---
title: expansion.library/AllocConfigDev
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-allocconfigdev-2
functions: []
libraries: []
---

# expansion.library/AllocConfigDev

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocConfigDev - allocate a [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structure

   SYNOPSIS
	configDev = AllocConfigDev()
	D0

   FUNCTION
	This routine returns the address of a [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structure.
	It is provided so new fields can be added to the structure
	without breaking old, existing code.  The structure is cleared
	when it is returned to the user.

   INPUTS

   RESULTS
	configDev - either a valid [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structure or NULL.

   EXCEPTIONS

   SEE ALSO
	[FreeConfigDev()](autodocs-3.5/expansion-library-freeconfigdev-2.md)

   BUGS

