---
title: locale.library/GetLocaleStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-getlocalestr
functions: [CloseLocale, OpenLocale]
libraries: [locale.library]
---

# locale.library/GetLocaleStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetLocaleStr -- get a standard string from a locale. (V38)

   SYNOPSIS
	string = GetLocaleStr(locale,stringNum);
	D0                    A0     D0

	[STRPTR](autodocs-3.5/include-exec-types-h.md) GetLocaleStr(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,ULONG);

   FUNCTION
	This function returns a specific string associated with the given
	locale.

   INPUTS
	locale - a valid locale
	stringNum - the number of the string to get a pointer to. See the
		    constants defined in [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md) for the
		    possible values.

   RESULT
	string - a pointer to a NULL-terminated string, or NULL if the
		 requested string number was out of bounds. The returned
		 string is READ-ONLY, do NOT modify! This string pointer
		 is valid only as long as the locale remains open.

   SEE ALSO
	[OpenLocale()](autodocs-3.5/locale-library-openlocale.md), [CloseLocale()](autodocs-3.5/locale-library-closelocale.md), [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md)

---

## See Also

- [CloseLocale — locale.library](../autodocs/locale.library.md#closelocale)
- [OpenLocale — locale.library](../autodocs/locale.library.md#openlocale)
