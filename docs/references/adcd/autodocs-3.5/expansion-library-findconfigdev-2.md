---
title: expansion.library/FindConfigDev
manual: autodocs-3.5
chapter: autodocs-3.5
section: expansion-library-findconfigdev-2
functions: []
libraries: []
---

# expansion.library/FindConfigDev

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindConfigDev - find a matching [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) entry

   SYNOPSIS
	configDev = FindConfigDev( oldConfigDev, manufacturer, product )
	D0                         A0            D0            D1

   FUNCTION
	This routine searches the list of existing [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md)
	structures in the system and looks for one that has
	the specified manufacturer and product codes.

	If the oldConfigDev is NULL the the search is from the
	start of the list of configuration devices.  If it is
	not null then it searches from the first configuration
	device entry AFTER oldConfigDev.

	A code of -1 is treated as a wildcard -- e.g. it matches
	any manufacturer (or product)

   INPUTS
	oldConfigDev - a valid [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) structure, or NULL to start
		from the start of the list.
	manufacturer - the manufacturer code being searched for, or
		-1 to ignore manufacturer numbers.
	product - the product code being searched for, or -1 to
		ignore product numbers.

   RESULTS
	configDev - the next [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) entry that matches the
		manufacturer and product codes, or NULL if there
		are no more matches.

   EXCEPTIONS

   EXAMPLES
	/* to find all configdevs of the proper type */
	struct [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) *cd = NULL;

	while( cd = FindConfigDev( cd, MANUFACTURER, PRODUCT ) ) {
		/* do something with the returned [ConfigDev](autodocs-3.5/include-libraries-configvars-h.md) */
	}

   SEE ALSO

   BUGS

