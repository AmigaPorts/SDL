---
title: commodities.library/InsertCxObj
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-insertcxobj-2
functions: [ClearCxObjError, CxObjError]
libraries: [commodities.library]
---

# commodities.library/InsertCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	InsertCxObj -- insert a commodity object in a list after a given
		       object. (V36)

   SYNOPSIS
	InsertCxObj(headObj,co,pred);
		    A0      A1 A2

	VOID InsertCxObj(CxObj *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *);

   FUNCTION
	Adds 'co' to the list of objects pointed to by 'headObj' after
	object 'pred'.

   INPUTS
	headObj - pointer to a list of objects. If this value is NULL, then
		  the entire tree of objects pointed to by 'co' is deleted
		  and becomes invalid.
	co - the object to add to the list (may be NULL)
	pred - the object after which 'co' should be inserted. If this is NULL
	       then 'co' is added to the head of the list.

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
