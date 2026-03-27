---
title: commodities.library/CxObjError
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-cxobjerror-2
functions: [ActivateCxObj, AttachCxObj, ClearCxObjError, SetFilter, SetFilterIX]
libraries: [commodities.library]
---

# commodities.library/CxObjError

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxObjError -- obtain a commodity object's accumulated error. (V36)

   SYNOPSIS
	error = CxObjError(co);
	D0		   A0

	[LONG](autodocs-3.5/include-exec-types-h.md) CxObjError(CxObj *);

   FUNCTION
	When a function acting on an object fails, it records the failure
	in the object. This function returns the accumulated error value.
	The values are represented by flag bits defined in
	[<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md). Several errors may be recorded by multiple
	bits in 'error'.

	The currently defined errors are:

	COERR_ISNULL
	  The value of parameter 'co' was in fact NULL. This error
	  means "the problem with the object you inquire about is
	  that it failed to be created."

  	COERR_NULLATTACH
	  Using the commodities' list manipulation functions, an attempt was
	  made to add a NULL object to the list belonging to 'co'. This allows
	  a line of code as follows to exist in an error-tolerant program:

	    AttachCxObj(filter,CxSender(myport,MY_ID));

  	COERR_BADFILTER
	  The most recent filter specification for a filter object
	  was faulty. This happens if no sense can be made out of a
	  description string, or if an input expression (IX) has an
	  invalid format or version byte. When this bit is set in a
	  filter's error field, the filter will match nothing, but this
	  is not the proper way to "turn off" a filter, use [ActivateCxObj()](autodocs-3.5/commodities-library-activatecxobj-2.md).

  	COERR_BADTYPE
	  A type specific operation, such as [SetFilterIX()](autodocs-3.5/commodities-library-setfilterix-2.md), was called
	  for object 'co', but 'co' isn't of the proper type.

   INPUTS
	co - the commodity object to get the accumulated error from (may be
	     NULL)

   RESULTS
	error - the accumulated error, or 0 if 'co' is NULL

   SEE ALSO
	[SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md), [SetFilterIX()](autodocs-3.5/commodities-library-setfilterix-2.md), [AttachCxObj()](autodocs-3.5/commodities-library-attachcxobj-2.md), [ActivateCxObj()](autodocs-3.5/commodities-library-activatecxobj-2.md),
	[ClearCxObjError()](autodocs-3.5/commodities-library-clearcxobjerror-2.md)

---

## See Also

- [ActivateCxObj — commodities.library](../autodocs/commodities.library.md#activatecxobj)
- [AttachCxObj — commodities.library](../autodocs/commodities.library.md#attachcxobj)
- [ClearCxObjError — commodities.library](../autodocs/commodities.library.md#clearcxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
- [SetFilterIX — commodities.library](../autodocs/commodities.library.md#setfilterix)
