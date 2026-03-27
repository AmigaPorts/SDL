---
title: amiga.lib/CxFilter
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-cxfilter-2
functions: [CreateCxObj, CxObjError, SetFilter, SetFilterIX]
libraries: [commodities.library]
---

# amiga.lib/CxFilter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxFilter -- create a commodity filter object. (V36)

   SYNOPSIS
	filterObj = CxFilter(description);

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxFilter(STRPTR)

   FUNCTION
	Creates an input event filter object that matches the
	'description' string. If 'description' is NULL, the filter will not
	match any messages.

	A filter may be modified by the functions [SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md), using
	a description string, and [SetFilterIX()](autodocs-3.5/commodities-library-setfilterix-2.md), which takes a
	binary [Input](autodocs-3.5/dos-library-input-2.md) Expression as a parameter.

	This function is a C-language macro for [CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), defined
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

   INPUTS
	description - the description string in the same format as strings
		      expected by [commodities.library/SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md)

   RESULTS
	filterObj - a pointer to the filter object, or NULL if there
		    was not enough memory. If there is a problem in the
		    description string, the internal error code of the filter
		    object will be set to so indicate. This error code may be
		    interrogated using the function [CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md).

   SEE ALSO
	[commodities.library/CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), [commodities.library/SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md),
	[commodities.library/SetFilterIX()](autodocs-3.5/commodities-library-setfilterix-2.md), [commodities.library/CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md)

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
