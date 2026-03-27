# commodities.library/ParseIX



   NAME
	ParseIX -- initialize an input expression given a description string.
		   (V36)

   SYNOPSIS
	failureCode = ParseIX(description,ix);
	D0		      A0          A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) ParseIX(STRPTR,IX *);

   FUNCTION
	Given an input description string and an allocated input
	expression, sets the fields of the input expression to
	correspond to the description string.

   INPUTS
	description - the string to parse
	ix - the input expression to hold the result of the parse

   RESULTS
	failureCode -  0 if all went well,
		      -1 if tokens after end (code spec)
	              -2 if 'description' was NULL

   SEE ALSO
	[<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html), [MatchIX()](../Includes_and_Autodocs_3._guide/node00F2.html)

