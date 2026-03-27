---
title: nonvolatile.library/GetCopyNV
manual: autodocs-3.5
chapter: autodocs-3.5
section: nonvolatile-library-getcopynv
functions: []
libraries: []
---

# nonvolatile.library/GetCopyNV

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetCopyNV -- return a copy of an item stored in nonvolatile storage.
		     (V40)

   SYNOPSIS
	data = GetCopyNV(appName, itemName, killRequesters);
	D0		 A0	  A1	    D1

	[APTR](autodocs-3.5/include-exec-types-h.md) GetCopyNV(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), BOOL);

   FUNCTION
	Searches the nonvolatile storage for the indicated appName and
	itemName. A pointer to a copy of this data will be returned.

	The strings appName and itemName may not contain the '/' or ':'
	characters. It is recommended that these characters be blocked
	from user input when requesting appName and itemName strings.

   INPUTS
	appName - NULL terminated string indicating the application name
		  to be found. Maximum length is 31.
	itemName - NULL terminated string indicated the item within the
		   application to be found. Maximum length is 31.
	killRequesters - Suppress system requesters flag. TRUE if all system
			 requesters are to be suppressed during this function.
			 FALSE if system requesters are allowed.

   RESULT
	data - pointer to a copy of the data found in the nonvolatile storage
	       assocated with appName and itemName. NULL will be returned
	       if there is insufficient memory or the appName/itemName does
	       not exist.

   SEE ALSO
	[FreeNVData()](autodocs-3.5/nonvolatile-library-freenvdata.md), [<libraries/nonvolatile.h>](autodocs-3.5/include-libraries-nonvolatile-h.md)

