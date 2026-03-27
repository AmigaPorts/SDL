---
title: commodities.library/SetFilterIX
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-setfilterix-2
functions: [CxObjError, SetFilter]
libraries: [commodities.library]
---

# commodities.library/SetFilterIX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetFilterIX -- change the matching condition of a commodity filter.
		       (V36)

   SYNOPSIS
	SetFilterIX(filter,ix);
		    A0     A1

	VOID SetFilterIX(CxObj *,IX *);

   FUNCTION
	This function changes the matching condition of a commodity input
	filter to that described by the binary input expression pointed by
	'ix'.

	[Input](autodocs-3.5/dos-library-input-2.md) expressions are defined in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).
	It is important to remember that the first field of the input
	expression structure must indicate which version of the
	input expression structure is being used.

   INPUTS
	filter - the filter object to affect (may be NULL)
	ix - the new matching conditions for the filter

   RESULTS
	The internal error of 'filter' will have the COERR_BADFILTER
	bit set or cleared depending on the failure or success of this
	function.

   SEE ALSO
	[SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md), [CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md)

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
