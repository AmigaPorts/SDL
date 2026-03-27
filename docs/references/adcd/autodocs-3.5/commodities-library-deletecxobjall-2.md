---
title: commodities.library/DeleteCxObjAll
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-deletecxobjall-2
functions: [DeleteCxObj]
libraries: [commodities.library]
---

# commodities.library/DeleteCxObjAll

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteCxObjAll -- recursively delete a tree of commodity objects.
			  (V36)

   SYNOPSIS
	DeleteCxObjAll(co);
		       A0

	VOID DeleteCxObjAll(CxObj *);

   FUNCTION
	This function deletes the commodity object 'co', and
	recursively deletes all objects attached to it, and the
	objects attached to them, etc.

	If 'co' is linked into a list, it is first removed. Note
	that the handle 'co' is invalid after this function is called.

	This function is useful when an application exits: most
	applications can clean up completely by deleting the
	entire sub-tree of objects starting at their broker.

   INPUTS
	co - the first commodity object to delete (may be NULL)

   SEE ALSO
	[DeleteCxObj()](autodocs-3.5/commodities-library-deletecxobj-2.md)

---

## See Also

- [DeleteCxObj — commodities.library](../autodocs/commodities.library.md#deletecxobj)
