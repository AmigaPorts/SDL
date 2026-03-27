---
title: commodities.library/DeleteCxObj
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-deletecxobj-2
functions: [DeleteCxObjAll]
libraries: [commodities.library]
---

# commodities.library/DeleteCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteCxObj -- delete a commmodity object. (V36)

   SYNOPSIS
	DeleteCxObj(co);
	            A0

	VOID DeleteCxObj(CxObj *);

   FUNCTION
	Deletes a commodity object of any type. If the object
	is linked into a list, it is first removed. Note that
	the handle 'co' is invalid after this function is called.

	Also note that deleting an object which has other objects attached
	to it may be undesirable. Use the function [DeleteCxObjAll()](autodocs-3.5/commodities-library-deletecxobjall-2.md)
	to delete an entire sub-tree of objects.

   INPUTS
	co - the commodity object to delete (may be NULL)

   SEE ALSO
	[DeleteCxObjAll()](autodocs-3.5/commodities-library-deletecxobjall-2.md)

---

## See Also

- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
