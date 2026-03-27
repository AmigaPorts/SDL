# commodities.library/SetFilterIX



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

	[Input](../Includes_and_Autodocs_3._guide/node017F.html) expressions are defined in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).
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
	[SetFilter()](../Includes_and_Autodocs_3._guide/node00F7.html), [CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html)

