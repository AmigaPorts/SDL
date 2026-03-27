# locale.library/--environment_vars--



	Starting with V40, locale.library maintains a global environment
	variable called "Language" which contains the name of the current
	default language as used in the system. This is the name of the
	language associated with the [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) structure returned by
	OpenLocale(NULL).

   EXAMPLE
	From a shell:

		Echo "The system language currently is: $Language"

	will print the name of the current system language ("english",
	"français", etc)

