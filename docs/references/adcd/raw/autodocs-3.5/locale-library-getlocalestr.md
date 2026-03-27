# locale.library/GetLocaleStr



   NAME
	GetLocaleStr -- get a standard string from a locale. (V38)

   SYNOPSIS
	string = GetLocaleStr(locale,stringNum);
	D0                    A0     D0

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) GetLocaleStr(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,ULONG);

   FUNCTION
	This function returns a specific string associated with the given
	locale.

   INPUTS
	locale - a valid locale
	stringNum - the number of the string to get a pointer to. See the
		    constants defined in [<libraries/locale.h>](../Includes_and_Autodocs_3._guide/node05E3.html) for the
		    possible values.

   RESULT
	string - a pointer to a NULL-terminated string, or NULL if the
		 requested string number was out of bounds. The returned
		 string is READ-ONLY, do NOT modify! This string pointer
		 is valid only as long as the locale remains open.

   SEE ALSO
	[OpenLocale()](../Includes_and_Autodocs_3._guide/node045C.html), [CloseLocale()](../Includes_and_Autodocs_3._guide/node0453.html), [<libraries/locale.h>](../Includes_and_Autodocs_3._guide/node05E3.html)

