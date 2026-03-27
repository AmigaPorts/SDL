---
title: commodities.library/SetCxObjPri
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-setcxobjpri-2
functions: [EnqueueCxObj, RemoveCxObj, SetCxObjPri]
libraries: [commodities.library]
---

# commodities.library/SetCxObjPri

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetCxObjPri -- set the priority of a commodity object. (V36)

   SYNOPSIS
	oldPri = SetCxObjPri(co,pri)
	D0                   A0 D0

	[LONG](autodocs-3.5/include-exec-types-h.md) SetCxObjPri(CxObj *,LONG);

   FUNCTION
	This function sets the priority of a commodity object for the
	purposes of [EnqueueCxObj()](autodocs-3.5/commodities-library-enqueuecxobj-2.md).

	It is strongly recommended that the ToolTypes environment be
	utilized to provide end-user control over the priority of
 	brokers, but application specific ordering of other objects
	within their lists is not dictated.

   INPUTS
	co - the commodity object to affect (may be NULL)
	pri - the object's new priority in the range -128 to +127. A value
	      of 0 is normal.

   RESULTS
	oldPri - the previous priority of the object or 0 if 'co' was NULL.
		 This value is only returned in V38 and beyond.

   BUGS
	This function will not reposition an object within its list when
	its priority changes. To attain the same effect, first remove the
	object from its list using [RemoveCxObj()](autodocs-3.5/commodities-library-removecxobj-2.md), set its priority using
	SetCxObjPri(), and reinsert it in the list using [EnqueueCxObj()](autodocs-3.5/commodities-library-enqueuecxobj-2.md).

   SEE ALSO
	[EnqueueCxObj()](autodocs-3.5/commodities-library-enqueuecxobj-2.md)

---

## See Also

- [EnqueueCxObj — commodities.library](../autodocs/commodities.library.md#enqueuecxobj)
- [RemoveCxObj — commodities.library](../autodocs/commodities.library.md#removecxobj)
- [SetCxObjPri — commodities.library](../autodocs/commodities.library.md#setcxobjpri)
