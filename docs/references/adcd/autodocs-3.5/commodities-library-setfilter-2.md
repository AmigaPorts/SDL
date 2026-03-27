---
title: commodities.library/SetFilter
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-setfilter-2
functions: [CxObjError, SetFilterIX]
libraries: [commodities.library]
---

# commodities.library/SetFilter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetFilter -- change the matching condition of a commodity filter.
		     (V36)

   SYNOPSIS
	SetFilter(filter,text);
		  A0     A1

	VOID SetFilter(CxObj *,STRPTR);

   FUNCTION
	This function changes the matching condition of a commodity input
	filter to that described by the input description string 'text'.

   INPUTS
	filter - the filter object to affect (may be NULL)
	text - the new matching conditions for the filter

   RESULTS
	The internal error of 'filter' will have the COERR_BADFILTER
	bit set or cleared depending on the failure or success of this
	function.

   SEE ALSO
	[SetFilterIX()](autodocs-3.5/commodities-library-setfilterix-2.md), [CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md)

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
