# commodities.library/SetFilter



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
	[SetFilterIX()](../Includes_and_Autodocs_3._guide/node00F8.html), [CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html)

