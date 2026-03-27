# dos.library/StrToLong



   NAME
	StrToLong -- string to long value (decimal) (V36)

   SYNOPSIS
	characters = StrToLong(string,value)
	D0                       D1    D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) StrToLong(STRPTR, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *)

   FUNCTION
	Converts decimal string into [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) value.  Returns number of characters
	converted.  Skips over leading spaces & tabs (included in count).  If
	no decimal digits are found (after skipping leading spaces & tabs),
	StrToLong returns -1 for characters converted, and puts 0 into value.

   INPUTS
	string - [Input](../Includes_and_Autodocs_3._guide/node017F.html) string.
	value  - Pointer to long value.  Set to 0 if no digits are converted.

   RESULT
	result - Number of characters converted or -1.

   BUGS
	Before V39, if there were no convertible characters it returned the
	number of leading white-space characters (space and tab in this case).

