---
title: resource.library/RL_DisposeGroup
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-disposegroup
functions: []
libraries: []
---

# resource.library/RL_DisposeGroup

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_DisposeGroup - dispose a group of objects (V44)

   SYNOPSIS
	RL_DisposeGroup(resource, group)
	                 A0        A1

	VOID RL_DisposeGroup(RESOURCEFILE, [Object](autodocs-3.5/include-intuition-classusr-h.md) **);

   FUNCTION
	Disposes a group of objects that was allocated with [RL_NewGroupA](autodocs-3.5/resource-library-rl-newgroupa.md).
	Never dispose a object from the group with [RL_DisposeObject](autodocs-3.5/resource-library-rl-disposeobject.md),
	[DisposeObject](autodocs-3.5/intuition-library-disposeobject-2.md) or [DisposeDTObject](autodocs-3.5/datatypes-library-disposedtobject.md).

   INPUTS
	resource -- a pointer to a resource
	group -- a pointer to an array of pointers to [Object](autodocs-3.5/include-intuition-classusr-h.md). A value of
	         NULL is acceptable which means a no-op.

   RESULTS


   SEE ALSO
	[resource.library/RL_NewGroupA](autodocs-3.5/resource-library-rl-newgroupa.md)

