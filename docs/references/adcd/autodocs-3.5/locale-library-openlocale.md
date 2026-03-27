---
title: locale.library/OpenLocale
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-openlocale
functions: [CloseLocale, IoErr]
libraries: [dos.library, locale.library]
---

# locale.library/OpenLocale

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenLocale -- open a locale. (V38)

   SYNOPSIS
	locale = OpenLocale(name);
	D0                  A0

	struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *OpenLocale(STRPTR);

   FUNCTION
	This function opens a named locale. Locales contain many parameters
	that an application needs to consider when being integrated into
	different languages, territories and customs. Using the information
	stored in a locale instead of hard-coding it into an application,
	lets the application dynamically adapt to the user's environment.

	Locales originally come from disk files which are created by the
	user using the [Locale](autodocs-3.5/include-libraries-locale-h.md) preferences editor. Passing a NULL instead of
	a name causes this function to return the current default locale.
	This is what most applications will do.

	Every locale specifies a language, and special language drivers
	must be loaded from disk depending on which language is being used.
	These files include for example:

		LOCALE:Languages/français.language
		LOCALE:Languages/dansk.language
		LOCALE:Languages/italiano.language

   INPUTS
	name - the NULL-terminated name of the locale to open, or NULL to open
	       the current default locale. This should generally be NULL. The
	       name you supply must be a pathname leading to a locale
	       preferences file. This is an IFF PREF file as saved by
	       [Locale](autodocs-3.5/include-libraries-locale-h.md) prefs, that can contain both LCLE and CTRY chunks.
	       See [<prefs/locale.h>](autodocs-3.5/include-prefs-locale-h.md) for definitions.

   RESULT
	locale - a pointer to an initialized [Locale](autodocs-3.5/include-libraries-locale-h.md) structure, or NULL if the
		 locale could not be loaded. In the case of a NULL return, the
		 DOS [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) function can be called to obtain more information
		 on the failure.

		 When passing a NULL name parameter to this function, you are
		 guaranteed a valid return.

   SEE ALSO
	[CloseLocale()](autodocs-3.5/locale-library-closelocale.md), [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md), [<prefs/locale.h>](autodocs-3.5/include-prefs-locale-h.md)

---

## See Also

- [CloseLocale — locale.library](../autodocs/locale.library.md#closelocale)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
