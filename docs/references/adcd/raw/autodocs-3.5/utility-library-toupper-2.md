# utility.library/ToUpper



   NAME
	ToUpper -- convert a character to upper case. (V37)

   SYNOPSIS
	char = ToUpper(char);
	D0	       D0

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) ToUpper(UBYTE);

   FUNCTION
	Converts a character to upper case, handling international character
	sets.

   INPUTS
	char - character to be converted.

   RESULTS
	char - upper case version of input character.

   NOTES
	Whenever locale.library is installed in a system, this function is
	replaced by language-specific code. This means that depending on
	which language the user has currently selected, a given character may
	return different results when passed to this function. This fact must
	be taken into consideration when using this function.

   SEE ALSO
	ToUpper(), [locale.library/ConvToLower()](../Includes_and_Autodocs_3._guide/node0454.html)

