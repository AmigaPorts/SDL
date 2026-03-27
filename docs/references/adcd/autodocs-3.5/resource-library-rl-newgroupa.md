---
title: resource.library/RL_NewGroupA
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-newgroupa
functions: []
libraries: []
---

# resource.library/RL_NewGroupA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_NewGroupA - allocate a group of objects (V44)

   SYNOPSIS
	group = RL_NewGroupA(resource,id,taglist)
	 D0                   A0      D0  A1

	[Object](autodocs-3.5/include-intuition-classusr-h.md) **RL_NewGroupA(RESOURCEFILE, RESOURCEID, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

   FUNCTION
	The routine allocates a group of objects with a given numeric id.

   INPUTS
	resource -- a pointer to a resource
	id -- a numeric id
	taglist -- a pointer to an array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md). Currently no tags are
	           defined.

   RESULTS
	group -- a pointer to an array of pointers to [Object](autodocs-3.5/include-intuition-classusr-h.md) or NULL.

   SEE ALSO
	[resource.library/RL_DisposeGroup](autodocs-3.5/resource-library-rl-disposegroup.md)
	[resource.library/RL_GetObjectArray](autodocs-3.5/resource-library-rl-getobjectarray.md)

