---
title: misc.resource/FreeMiscResource
manual: autodocs-3.5
chapter: autodocs-3.5
section: misc-resource-freemiscresource-2
functions: []
libraries: []
---

# misc.resource/FreeMiscResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeMiscResource - make a resource available for reallocation

   SYNOPSIS
	FreeMiscResource( unitNum )
			  D0

	void FreeMiscResource(ULONG);

   FUNCTION
	This routine frees one of the resources allocated
	by [AllocMiscResource](autodocs-3.5/misc-resource-allocmiscresource-2.md).  The resource is made available
	for reuse.

	FreeMiscResource must be called from the same task that
	called [AllocMiscResource](autodocs-3.5/misc-resource-allocmiscresource-2.md).  This function may not be called from
	interrupt code.

    INPUTS
	unitNum - the number of the miscellaneous resource to be freed.

    RESULTS
	Frees the appropriate resource.

    BUGS

    SEE ALSO
	resources/misc.i, [AllocMiscResource()](autodocs-3.5/misc-resource-allocmiscresource-2.md)

