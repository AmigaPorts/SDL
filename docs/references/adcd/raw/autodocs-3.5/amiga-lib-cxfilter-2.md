# amiga.lib/CxFilter



   NAME
	CxFilter -- create a commodity filter object. (V36)

   SYNOPSIS
	filterObj = CxFilter(description);

	[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *CxFilter(STRPTR)

   FUNCTION
	Creates an input event filter object that matches the
	'description' string. If 'description' is NULL, the filter will not
	match any messages.

	A filter may be modified by the functions [SetFilter()](../Includes_and_Autodocs_3._guide/node00F7.html), using
	a description string, and [SetFilterIX()](../Includes_and_Autodocs_3._guide/node00F8.html), which takes a
	binary [Input](../Includes_and_Autodocs_3._guide/node017F.html) Expression as a parameter.

	This function is a C-language macro for [CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), defined
	in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html).

   INPUTS
	description - the description string in the same format as strings
		      expected by [commodities.library/SetFilter()](../Includes_and_Autodocs_3._guide/node00F7.html)

   RESULTS
	filterObj - a pointer to the filter object, or NULL if there
		    was not enough memory. If there is a problem in the
		    description string, the internal error code of the filter
		    object will be set to so indicate. This error code may be
		    interrogated using the function [CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html).

   SEE ALSO
	[commodities.library/CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html), [commodities.library/SetFilter()](../Includes_and_Autodocs_3._guide/node00F7.html),
	[commodities.library/SetFilterIX()](../Includes_and_Autodocs_3._guide/node00F8.html), [commodities.library/CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html)

