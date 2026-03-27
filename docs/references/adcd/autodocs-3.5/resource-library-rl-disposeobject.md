---
title: resource.library/RL_DisposeObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-disposeobject
functions: []
libraries: []
---

# resource.library/RL_DisposeObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_DisposeObject - dispose an object (V44)

   SYNOPSIS
	RL_DisposeObject(resource, object)
	                  A0        A1

	VOID RL_DisposeObject(RESOURCEFILE, [Object](autodocs-3.5/include-intuition-classusr-h.md) *);

   FUNCTION
	Dispose an object that was allocated with [RL_NewObjectA](autodocs-3.5/resource-library-rl-newobjecta.md).

   INPUTS
	resource -- a pointer to a resource
	object -- a pointer to an [Object](autodocs-3.5/include-intuition-classusr-h.md). A value of NULL is acceptable which
	          means a no-op.

   RESULTS


   SEE ALSO
	[resource.library/RL_NewObjectA](autodocs-3.5/resource-library-rl-newobjecta.md)

