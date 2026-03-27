---
title: exec.library/AddResource
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addresource-2
functions: [OpenResource, RemResource]
libraries: [exec.library]
---

# exec.library/AddResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddResource -- add a resource to the system

   SYNOPSIS
	AddResource(resource)
		    A1

	void AddResource(APTR);

   FUNCTION
	This function adds a new resource to the system and makes it
	available to other users.  The resource must be ready to be called
	at this time.

	Resources currently have no system-imposed structure, however they
	must start with a standard named node (LN_SIZE), and should with
	a standard [Library](autodocs-3.5/include-exec-libraries-h.md) node (LIB_SIZE).

   INPUTS
	resource - pointer an initialized resource node

   SEE ALSO
	[RemResource()](autodocs-3.5/exec-library-remresource-2.md), [OpenResource()](autodocs-3.5/exec-library-openresource-2.md), [MakeLibrary()](autodocs-3.5/exec-library-makelibrary-2.md)

---

## See Also

- [OpenResource — exec.library](../autodocs/exec.library.md#openresource)
- [RemResource — exec.library](../autodocs/exec.library.md#remresource)
