---
title: commodities.library/EnqueueCxObj
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-enqueuecxobj-2
functions: [ClearCxObjError, CxObjError, SetCxObjPri]
libraries: [commodities.library]
---

# commodities.library/EnqueueCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	EnqueueCxObj -- insert a commodity object within a list of objects
		        based on object priority. (V36)

   SYNOPSIS
	EnqueueCxObj(headObj,co);
		     A0      A1

	VOID EnqueueCxObj(CxObj *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *);

   FUNCTION
	This function puts object 'co' into the list of object 'headObj'.
	The insertion point is determined by the object's priority. The
	objects are kept in the list from the highest priority to the
	lowest. New nodes are inserted in front of the first node with a
	lower priority. Hence a FIFO queue for nodes of equal priority.

	The priority of the commodity object can be set using [SetCxObjPri()](autodocs-3.5/commodities-library-setcxobjpri-2.md).

   INPUTS
	headObj - pointer to a list of objects. If this value is NULL, then
		  the entire tree of objects pointed to by 'co' is deleted
		  and becomes invalid.
	co - the object to add to the list (may be NULL)

   RESULTS
	If 'co' is NULL, this function will record that fact in the
	internal accumulated error of 'headObj'. This error record
	can be retrieved using [CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md) and cleared using
	[ClearCxObjError()](autodocs-3.5/commodities-library-clearcxobjerror-2.md).

   BUGS
	Until V38, passing a NULL 'headObj' parameter would cause low-memory
	access and unpredictable results.

   SEE ALSO
	[SetCxObjPri()](autodocs-3.5/commodities-library-setcxobjpri-2.md), [CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md), [ClearCxObjError()](autodocs-3.5/commodities-library-clearcxobjerror-2.md)

---

## See Also

- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetCxObjPri — commodities.library](../autodocs/commodities.library.md#setcxobjpri)
