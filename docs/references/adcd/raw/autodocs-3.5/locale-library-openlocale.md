# locale.library/OpenLocale



   NAME
	OpenLocale -- open a locale. (V38)

   SYNOPSIS
	locale = OpenLocale(name);
	D0                  A0

	struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *OpenLocale(STRPTR);

   FUNCTION
	This function opens a named locale. Locales contain many parameters
	that an application needs to consider when being integrated into
	different languages, territories and customs. Using the information
	stored in a locale instead of hard-coding it into an application,
	lets the application dynamically adapt to the user's environment.

	Locales originally come from disk files which are created by the
	user using the [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) preferences editor. Passing a NULL instead of
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
	       [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) prefs, that can contain both LCLE and CTRY chunks.
	       See [<prefs/locale.h>](../Includes_and_Autodocs_3._guide/node05F4.html) for definitions.

   RESULT
	locale - a pointer to an initialized [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) structure, or NULL if the
		 locale could not be loaded. In the case of a NULL return, the
		 DOS [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) function can be called to obtain more information
		 on the failure.

		 When passing a NULL name parameter to this function, you are
		 guaranteed a valid return.

   SEE ALSO
	[CloseLocale()](../Includes_and_Autodocs_3._guide/node0453.html), [<libraries/locale.h>](../Includes_and_Autodocs_3._guide/node05E3.html), [<prefs/locale.h>](../Includes_and_Autodocs_3._guide/node05F4.html)

