---
title: commodities.library/RemoveCxObj
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-removecxobj-2
functions: [AttachCxObj, EnqueueCxObj, InsertCxObj]
libraries: [commodities.library]
---

# commodities.library/RemoveCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemoveCxObj -- remove a commodity object from a list. (V36)

   SYNOPSIS
	RemoveCxObj(co);
		    A0

	VOID RemoveCxObj(CxObj *);

   FUNCTION
	This function removes 'co' from any list it may be a part of.
	Will not crash if 'co' is NULL, or if it has not been inserted
	in a list.

   INPUTS
	co - the object to remove (may be NULL)

   SEE ALSO
	[AttachCxObj()](autodocs-3.5/commodities-library-attachcxobj-2.md), [EnqueueCxObj()](autodocs-3.5/commodities-library-enqueuecxobj-2.md), [InsertCxObj()](autodocs-3.5/commodities-library-insertcxobj-2.md)

---

## See Also

- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [EnqueueCxObj — commodities.library](../autodocs/commodities.library.md#enqueuecxobj)
- [InsertCxObj — commodities.library](../autodocs/commodities.library.md#insertcxobj)
