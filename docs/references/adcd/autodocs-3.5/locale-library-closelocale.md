---
title: locale.library/CloseLocale
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-closelocale
functions: [OpenLocale]
libraries: [locale.library]
---

# locale.library/CloseLocale

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseLocale -- close a locale. (V38)

   SYNOPSIS
	CloseLocale(locale);
	            A0

	VOID CloseLocale(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *);

   FUNCTION
	Concludes access to a locale.

   INPUTS
	locale - an opened locale. A NULL locale is a valid
		 parameter and is simply ignored.

   SEE ALSO
	[OpenLocale()](autodocs-3.5/locale-library-openlocale.md), [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md)

---

## See Also

- [OpenLocale — locale.library](../autodocs/locale.library.md#openlocale)
