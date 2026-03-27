# utility.library/SDivMod32



   NAME
	SDivMod32 -- signed 32 by 32 bit division and modulus. (V36)

   SYNOPSIS
	quotient:remainder = SDivMod32(dividend,divisor);
	D0       D1                    D0       D1

	[LONG:LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SDivMod32(LONG,LONG);

   FUNCTION
	Divides the signed 32 bit dividend by the signed 32 bit divisor
	and returns a signed 32 bit quotient and remainder.

   INPUTS
	dividend - signed 32 bit dividend.
	divisor - signed 32 bit divisor.

   RESULTS
	quotient - signed 32 quotient of the division.
	remainder - signed 32 remainder of the division.

   NOTES
	Unlike other Amiga library function calls, the utility.library
	32 bit math routines do NOT require A6 to be loaded with a
	pointer to the library base. A6 can contain anything the application
	wishes. This is in order to avoid overhead in calling them.

	In addition, the utility.library math routines preserve all
	address registers including A0 and A1

   SEE ALSO
	[SMult32()](../Includes_and_Autodocs_3._guide/node05AE.html), [UDivMod32()](../Includes_and_Autodocs_3._guide/node05B5.html), [UMult32()](../Includes_and_Autodocs_3._guide/node05B6.html), [SMult64()](../Includes_and_Autodocs_3._guide/node05AF.html), [UMult64()](../Includes_and_Autodocs_3._guide/node05B7.html)

