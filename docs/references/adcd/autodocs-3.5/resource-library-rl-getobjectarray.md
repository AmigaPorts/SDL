---
title: resource.library/RL_GetObjectArray
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-getobjectarray
functions: []
libraries: []
---

# resource.library/RL_GetObjectArray

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_GetObjectArray - get a pointer to a group of objects (V44)

   SYNOPSIS
	group = RL_GetObjectArray(resource,object,id)
	 D0                        A0       A1    D0

	[Object](autodocs-3.5/include-intuition-classusr-h.md) **RL_GetObjectArray(RESOURCEFILE, [Object](autodocs-3.5/include-intuition-classusr-h.md) *, RESOURCEID);

   FUNCTION
	If you allocated an [Object](autodocs-3.5/include-intuition-classusr-h.md) using [RL_NewObjectA](autodocs-3.5/resource-library-rl-newobjecta.md) a lot of additional
	Objects and group of Objects may be allocated automatically. This
	functions returns a pointer to a group of objects with a given group
	ID.

	Never release the group with RL_DisposeGroupA. The group is released
	automatically if the object is released

   INPUTS
	resource -- a pointer to a resource
	object -- a pointer to an [Object](autodocs-3.5/include-intuition-classusr-h.md)
	id -- a numeric id of a object group

   RESULTS
	group -- a pointer to an array of pointers to [Object](autodocs-3.5/include-intuition-classusr-h.md)

   SEE ALSO
	[resource.library/RL_NewObjectA](autodocs-3.5/resource-library-rl-newobjecta.md)
	[resource.library/RL_NewGroupA](autodocs-3.5/resource-library-rl-newgroupa.md)

