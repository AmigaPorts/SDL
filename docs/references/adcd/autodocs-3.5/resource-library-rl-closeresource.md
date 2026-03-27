---
title: resource.library/RL_CloseResource
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-closeresource
functions: []
libraries: []
---

# resource.library/RL_CloseResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_CloseResource - close and free a resource object (V44)

   SYNOPSIS
	RL_CloseResource(resource)
	                   A0

	VOID RL_CloseResource(RESOURCEFILE);

   FUNCTION
	This routine closes a resource object that was previously opened with
	[RL_OpenResource](autodocs-3.5/resource-library-rl-openresource.md). It frees all objects and object groups.

   INPUTS
	resource -- a pointer to a resource. A value of NULL is acceptable
	            which means a no-op.

   RESULTS


   SEE ALSO
	[resource.library/RL_OpenResource](autodocs-3.5/resource-library-rl-openresource.md)

