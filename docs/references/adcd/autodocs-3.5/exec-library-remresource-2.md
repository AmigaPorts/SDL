---
title: exec.library/RemResource
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remresource-2
functions: [AddResource]
libraries: [exec.library]
---

# exec.library/RemResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemResource -- remove a resource from the system

   SYNOPSIS
	RemResource(resource)
		   A1

	void RemResource(APTR);

   FUNCTION
	This function removes an existing resource from the system resource
	list.  There must be no outstanding users of the resource.

   INPUTS
	resource - pointer to a resource node

   SEE ALSO
	[AddResource()](autodocs-3.5/exec-library-addresource-2.md)

---

## See Also

- [AddResource — exec.library](../autodocs/exec.library.md#addresource)
