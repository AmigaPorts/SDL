---
title: commodities.library/ClearCxObjError
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-clearcxobjerror-2
functions: [CxObjError]
libraries: [commodities.library]
---

# commodities.library/ClearCxObjError

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ClearCxObjError -- clear the accumulated error value of a commodity
			   object. (V36)

   SYNOPSIS
	ClearCxObjError(co);
	      	        A0

	VOID ClearCxObjError(CxObj *);

   FUNCTION
	This function clears the accumulated error value of commodity object
	'co'.

	It is unwise to do this to a filter if COERR_BADFILTER is set.
	This will fool commodities into thinking the filter is OK. Set
	another valid filter, or leave the error value alone.

   INPUTS
	co - the object to affect (may be NULL)

   SEE ALSO
	[CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md)

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
