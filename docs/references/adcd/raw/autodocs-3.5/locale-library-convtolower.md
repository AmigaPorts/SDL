# locale.library/ConvToLower



   NAME
	ConvToLower -- convert a character to lower case. (V38)

   SYNOPSIS
	char = ConvToLower(locale,character);
	D0	           A0     D0

	ULONG ConvToLower(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,ULONG);

   FUNCTION
	This function tests if the character specified is upper case. If it is
	then the lower case version of that character is returned, and if it
	isn't then the original character is returned.

   INPUTS
	locale - the locale to use for the conversion
	character - the character to convert

   RESULT
	char - a (possibly) converted character

   NOTE
	This function requires a full 32-bit character be passed-in in order
	to support multi-byte character sets.

