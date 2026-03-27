# commodities.library/CxObjError



   NAME
	CxObjError -- obtain a commodity object's accumulated error. (V36)

   SYNOPSIS
	error = CxObjError(co);
	D0		   A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CxObjError(CxObj *);

   FUNCTION
	When a function acting on an object fails, it records the failure
	in the object. This function returns the accumulated error value.
	The values are represented by flag bits defined in
	[<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html). Several errors may be recorded by multiple
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
	  is not the proper way to "turn off" a filter, use [ActivateCxObj()](../Includes_and_Autodocs_3._guide/node00E0.html).

  	COERR_BADTYPE
	  A type specific operation, such as [SetFilterIX()](../Includes_and_Autodocs_3._guide/node00F8.html), was called
	  for object 'co', but 'co' isn't of the proper type.

   INPUTS
	co - the commodity object to get the accumulated error from (may be
	     NULL)

   RESULTS
	error - the accumulated error, or 0 if 'co' is NULL

   SEE ALSO
	[SetFilter()](../Includes_and_Autodocs_3._guide/node00F7.html), [SetFilterIX()](../Includes_and_Autodocs_3._guide/node00F8.html), [AttachCxObj()](../Includes_and_Autodocs_3._guide/node00E2.html), [ActivateCxObj()](../Includes_and_Autodocs_3._guide/node00E0.html),
	[ClearCxObjError()](../Includes_and_Autodocs_3._guide/node00E3.html)

