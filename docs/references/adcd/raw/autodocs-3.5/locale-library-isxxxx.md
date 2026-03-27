# locale.library/IsXXXX



   NAME
	IsXXXX -- determine whether a character is of a certain type. (V38)

   SYNOPSIS
	state = IsXXXX(locale,character);
	D0	       A0     D0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) IsXXXX(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,ULONG);

   FUNCTION
	These functions determine whether the character specified is of a
	certain type, according to the supplied locale.

	IsAlNum() - test if alphanumeric character
	IsAlpha() - test if alphabetical character
	IsCntrl() - test if control character
	IsDigit() - test if decimal digit character
	IsGraph() - test if visible character
	IsLower() - test if lower case character
	IsPrint() - test if blank
	IsPunct() - test if punctuation character
	IsSpace() - test if white space character
	IsUpper() - test if upper case character
	IsXDigit() - test if hexadecimal digit

   INPUTS
	locale - the locale to use for the test
	character - the character to test

   RESULT
	state - TRUE if the character is of the required type, FALSE otherwise

   NOTE
	These functions require full 32-bit characters be passed-in in order
	to support multi-byte character sets.

