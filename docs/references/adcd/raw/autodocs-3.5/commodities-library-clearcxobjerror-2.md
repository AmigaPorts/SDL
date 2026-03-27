# commodities.library/ClearCxObjError



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
	[CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html)

