---
title: nonvolatile.library/SetNVProtection
manual: autodocs-3.5
chapter: autodocs-3.5
section: nonvolatile-library-setnvprotection
functions: []
libraries: []
---

# nonvolatile.library/SetNVProtection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetNVProtection -- set the protection flags. (V40)

   SYNOPSIS
	success = SetNVProtection(appName, itemName, mask, killRequesters);
	D0			  A0	   A1	     D2    D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetNVProtection(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), BOOL);

   FUNCTION
	Sets the protection attributes for an item currently in the
	nonvolatile storage.

	Although 'mask' is [LONG](autodocs-3.5/include-exec-types-h.md) only the delete bit, NVEF_DELETE/NVEB_DELETE,
	may be set. If any other bits are set this function will return
	FALSE.

	The strings appName and itemName may not contain the '/' or ':'
	characters. It is recommended that these characters be blocked
	from user input when requesting AppName and ItemName strings.

   INPUTS
	appName - NULL terminated string indicating the application name
		  to be matched. Maximum length is 31.
	itemName - NULL terminated string indicated the item within the
		   application to be found. Maximum length is 31.
	mask - the new protection mask. Only set the delete bit otherwise
	       this function WILL CRASH.
	killRequesters - suppress system requesters flag. TRUE if all system
			 requesters are to be suppressed during this function.
			 FALSE if system requesters are allowed.

   RESULT
	success - FALSE if the protection could not be change (ie the data
		  does not exist).

   SEE ALSO
	[GetNVList()](autodocs-3.5/nonvolatile-library-getnvlist.md), [<libraries/nonvolatile.h>](autodocs-3.5/include-libraries-nonvolatile-h.md)

