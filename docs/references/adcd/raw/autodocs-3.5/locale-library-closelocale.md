# locale.library/CloseLocale



   NAME
	CloseLocale -- close a locale. (V38)

   SYNOPSIS
	CloseLocale(locale);
	            A0

	VOID CloseLocale(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *);

   FUNCTION
	Concludes access to a locale.

   INPUTS
	locale - an opened locale. A NULL locale is a valid
		 parameter and is simply ignored.

   SEE ALSO
	[OpenLocale()](../Includes_and_Autodocs_3._guide/node045C.html), [<libraries/locale.h>](../Includes_and_Autodocs_3._guide/node05E3.html)

