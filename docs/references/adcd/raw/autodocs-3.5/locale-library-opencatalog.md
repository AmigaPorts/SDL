# locale.library/OpenCatalog



   NAME
	OpenCatalogA -- open a message catalog. (V38)
	OpenCatalog -- varargs stub for OpenCatalogA(). (V38)

   SYNOPSIS
	catalog = OpenCatalogA(locale,name,tagList);
	D0                     A0     A1   A2

	struct [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245) *OpenCatalogA(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	catalog = OpenCatalog(locale,name,firstTag, ...);

	struct [Catalog](../Includes_and_Autodocs_3._guide/node05E3.html#line245) *OpenCatalog(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),[Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

   FUNCTION
	This function opens a message catalog. Catalogs contain all the
	text strings that an application uses. These strings can easily
	be replaced by strings in a different language, which causes the
	application to magically start operating in that new language.

	Catalogs originally come from disk files. This function searches for
	them in the following places:

		PROGDIR:Catalogs/languageName/name
		LOCALE:Catalogs/languageName/name

	where languageName is the name of the language associated with the
	locale parameter. So assuming an application called WizPaint:

		catalog = OpenCatalog(NULL,
				      "WizPaint.catalog",
				      OC_BuiltInLanguage,"english",
				      TAG_DONE);

	Passing NULL as first parameter to OpenCatalog() indicates you
	wish to use the system's default locale. Assuming the default locale
	specifies "deutsch" as language, OpenCatalog() tries to open the
	catalog as:

		PROGDIR:Catalogs/deutsch/WizPaint.catalog

	and if that file is not found, then OpenCatalog() tries to open it
	as:

		LOCALE:Catalogs/deutsch/WizPaint.catalog

	PROGDIR: is not always checked before LOCALE: is. If the volume which
	PROGDIR: is assigned to is NOT currently mounted, and if the one
	which LOCALE: is assigned to IS mounted, then LOCALE: is checked
	first, followed by PROGDIR: if needed. This is done in order to
	minimize the number of disk swaps on floppy systems.

	The OC_BuiltInLanguage tag specifies the language of the strings
	that are built into the application. If the language of the
	built-in strings matches that of the locale, then no catalog
	need be loaded from disk and the built-in strings can be used
	directly.

	locale.library caches text catalogs in order to minimize disk
	access. As such, OpenCatalog() may or may not cause disk access.
	This fact should be taken into consideration. Unused catalogs are
	automatically flushed from the system when there is not enough
	memory. When there is disk access, it is possible a DOS requester
	may be opened asking for a volume to be inserted. You can avoid this
	requester opening by setting your process' pr_WindowPtr field to -1.

   INPUTS
	locale - the locale for which the catalog should be opened, or NULL.
		 When NULL, then the system's default locale is used. This
		 should generally be NULL
	name - the NULL-terminated name of the catalog to open, typically
	       the application name with a ".catalog" extension
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL

   TAGS
	OC_BuiltInLanguage (STRPTR) - language of built-in strings of the
				      application. That is, this tag identifies
				      the language used for the "defaultString"
				      parameter used in the [GetCatalogStr()](../Includes_and_Autodocs_3._guide/node0458.html)
				      function. Default is "english". Providing
				      this tag and setting its value to NULL
				      indicates that there are no built-in
				      strings.

	OC_BuiltInCodeSet (ULONG) - code set of built-in strings. Default is 0.
				    THIS TAG SHOULD ALWAYS BE SET TO 0 FOR NOW.

	OC_Language (STRPTR) - language explicitly requested for the catalog.
			       A catalog of this language will be returned if
			       possible, otherwise a catalog in one of the
			       user's preferred languages. This tag should
			       normally not be provided as it overrides the
			       user's preferences.

	OC_Version (UWORD) - catalog version number required. Default is 0
			     which means to accept any version of the catalog
			     that is found. Note that if a version is
			     specified, the catalog's version much match it
			     exactly. This is different from version numbers
			     used by [OpenLibrary()](../Includes_and_Autodocs_3._guide/node0222.html).

   RESULT
	catalog - a message catalog to use with [GetCatalogStr()](../Includes_and_Autodocs_3._guide/node0458.html) or NULL.
		  A NULL result does not necessarily indicate an error.
		  If OpenCatalog() determines that the built-in strings of
		  the application can be used instead of an external catalog
		  from disk, then NULL is returned. To determine whether
		  a NULL result actually indicates an error, look at the
		  return value of [dos.library/IoErr()](../Includes_and_Autodocs_3._guide/node0182.html). 0 means no error.

		  [GetCatalogStr()](../Includes_and_Autodocs_3._guide/node0458.html) interprets a NULL catalog as meaning to use
		  the built-in strings.

   NOTE
	In most cases, failing to open a catalog should not be considered a
	fatal error, and the application should continue operating and
	simply use the built-in set of strings instead of the disk-based
	catalog. Note that [GetCatalogStr()](../Includes_and_Autodocs_3._guide/node0458.html) accepts a NULL catalog pointer for
	this very reason.

	Also note that displaying an error message when a catalog fails to
	open can be a meaningless endeavor as the message is likely in a
	language the user does not understand.

   SEE ALSO
	[CloseCatalog()](../Includes_and_Autodocs_3._guide/node0452.html), [GetCatalogStr()](../Includes_and_Autodocs_3._guide/node0458.html)

