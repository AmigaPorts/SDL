---
title: commodities.library/AttachCxObj
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-attachcxobj-2
functions: [ClearCxObjError, CxObjError]
libraries: [commodities.library]
---

# commodities.library/AttachCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AttachCxObj -- attach a commodity object to the end of an existing
		       list of objects. (V36)

   SYNOPSIS
	AttachCxObj(headObj,co);
		    A0      A1

	VOID AttachCxObj(CxObj *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *);

   FUNCTION
	Adds 'co' to the list of objects pointed to by 'headObj'. The
	new object is added at the end of the list.

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
	[CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md), [ClearCxObjError()](autodocs-3.5/commodities-library-clearcxobjerror-2.md)

---

## See Also

- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
