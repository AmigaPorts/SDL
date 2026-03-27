---
title: locale.library/--environment_vars--
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-environment-vars
functions: []
libraries: []
---

# locale.library/--environment_vars--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	Starting with V40, locale.library maintains a global environment
	variable called "Language" which contains the name of the current
	default language as used in the system. This is the name of the
	language associated with the [Locale](autodocs-3.5/include-libraries-locale-h.md) structure returned by
	OpenLocale(NULL).

   EXAMPLE
	From a shell:

		Echo "The system language currently is: $Language"

	will print the name of the current system language ("english",
	"français", etc)

