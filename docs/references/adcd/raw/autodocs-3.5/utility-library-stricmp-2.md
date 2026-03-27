# utility.library/Stricmp



   NAME
	Stricmp	-- case-insensitive string comparison. (V37)

   SYNOPSIS
	result = Stricmp(string1,string2);
	D0		 A0      A1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Stricmp(STRPTR,STRPTR);

   FUNCTION
	This function compares two strings, ignoring case using a generic
	case conversion routine. If the strings have different lengths,
	the shorter is treated as if it were extended with zeros.

   INPUTS
	string1, string2 - strings to be compared

   RESULTS
	result - relationship between string1 and string2
			<0 means string1 < string2
			=0 means string1 = string2
			>0 means string1 > string2

   NOTES
	Whenever locale.library is installed in a system, this function is
	replaced by language-specific code. This means that depending on
	which language the user has currently selected, identical pairs of
	strings may return different values when passed to this function.
	This fact must be taken into consideration when using this function.

   SEE ALSO
	[Strnicmp()](../Includes_and_Autodocs_3._guide/node05B1.html), [locale.library/StrnCmp()](../Includes_and_Autodocs_3._guide/node045F.html)

