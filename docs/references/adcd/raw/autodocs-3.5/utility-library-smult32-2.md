# utility.library/SMult32



   NAME
	SMult32 -- signed 32 by 32 bit multiply with 32 bit result. (V36)

   SYNOPSIS
	result = SMult32(arg1,arg2);
	D0               D0   D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SMult32(LONG,LONG);

   FUNCTION
	Returns the signed 32 bit result of multiplying arg1 by arg2.

   INPUTS
	arg1, arg2 - numbers to multiply

   RESULTS
	result - the signed 32 bit result of multiplying arg1 by arg2.

   NOTES
	Unlike other Amiga library function calls, the utility.library
	32 bit math routines do NOT require A6 to be loaded with a
	pointer to the library base. A6 can contain anything the application
	wishes. This is in order to avoid overhead in calling them.

	In addition, the utility.library math routines preserve all
	address registers including A0 and A1

   SEE ALSO
	[SDivMod32()](../Includes_and_Autodocs_3._guide/node05AD.html), [UDivMod32()](../Includes_and_Autodocs_3._guide/node05B5.html), [UMult32()](../Includes_and_Autodocs_3._guide/node05B6.html), [SMult64()](../Includes_and_Autodocs_3._guide/node05AF.html), [UMult64()](../Includes_and_Autodocs_3._guide/node05B7.html)

