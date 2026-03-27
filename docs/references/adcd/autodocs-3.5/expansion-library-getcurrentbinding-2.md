---
title: expansion.library/GetCurrentBinding
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-getcurrentbinding-2
functions: []
libraries: []
---

# expansion.library/GetCurrentBinding

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetCurrentBinding - gets static board configuration area

   SYNOPSIS
	actual = GetCurrentBinding( currentBinding, size )
	                            A0              D0:16

   FUNCTION
	This function writes the contents of the "currentBinding"
	structure out of a private place.  It may be set via
	[SetCurrentBinding()](autodocs-3.5/expansion-library-setcurrentbinding-2.md).  This is really a kludge, but it is
	the only way to pass extra arguments to a newly configured
	device.

	A [CurrentBinding](autodocs-3.5/include-libraries-configvars-h.md) structure has the name of the currently
	loaded file, the product string that was associated with
	this driver, and a pointer to the head of a singly linked
	list of [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structures (linked through the cd_NextCD
	field).

	Many devices may not need this information; they have hard
	coded into themselves their manufacture number.  It is
	recommended that you at least check that you can deal with
	the product code in the linked [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structures.

   INPUTS
	currentBinding - a pointer to a [CurrentBinding](autodocs-3.5/include-libraries-configvars-h.md) structure

	size - The size of the user's binddriver structure.
	    Do not pass in less than sizeof(struct CurrentBinding).

   RESULTS
	actual - the true size of a [CurrentBinding](autodocs-3.5/include-libraries-configvars-h.md) structure is returned.

   SEE ALSO
	[SetCurrentBinding()](autodocs-3.5/expansion-library-setcurrentbinding-2.md)

