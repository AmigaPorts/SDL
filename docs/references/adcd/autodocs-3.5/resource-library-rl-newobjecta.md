---
title: resource.library/RL_NewObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: resource-library-rl-newobjecta
functions: []
libraries: []
---

# resource.library/RL_NewObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RL_NewObjectA - create a new object (V44)

   SYNOPSIS
	object = RL_NewObjectA(resource,id,taglist)
	 D0                     A0      D0  A1

	[Object](autodocs-3.5/include-intuition-classusr-h.md) *RL_NewObjectA(RESOURCEFILE, RESOURCEID, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);;

   FUNCTION
	The routine creates a new object with a given numeric id.

   INPUTS
	resource -- a pointer to a resource
	id -- a numeric id
	taglist -- a pointer to an array of [TagItem](autodocs-3.5/include-utility-tagitem-h.md). The tags are moved
	           forward to the call of NewObjectA, [NewDTObjectA](autodocs-3.5/datatypes-library-newdtobjecta.md) or
	           whatever is called to create the object

   RESULTS
	object -- a pointer to an [Object](autodocs-3.5/include-intuition-classusr-h.md) or NULL.

   SEE ALSO
	intuition.library/NewObjectA
	[datatypes.library/NewDTObjectA](autodocs-3.5/datatypes-library-newdtobjecta.md)
	[resource.library/RL_DisposeObject](autodocs-3.5/resource-library-rl-disposeobject.md)

