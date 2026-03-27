---
title: nonvolatile.library/DeleteNV
manual: autodocs-3.5
chapter: autodocs-3.5
section: nonvolatile-library-deletenv
functions: []
libraries: []
---

# nonvolatile.library/DeleteNV

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteNV -- remove an entry from nonvoltatile storage. (V40)

   SYNOPSIS
	success = DeleteNV(appName, itemName, killRequesters);
	D0		   A0	    A1	      D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) DeleteNV(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), BOOL);

   FUNCTION
	Searches the nonvolatile storage for the indicated entry and removes
	it.

	The strings appName and itemName may not contain the '/' or ':'
	characters. It is recommended that these characters be blocked
	from user input when requesting AppName and ItemName strings.

   INPUTS
	appName - NULL terminated string identifing the application that
		  created the data. Maximum length is 31.
	ItemName - NULL terminated string uniquely identifing the data
		   within the application. Maximum length is 31.
	killRequesters - suppress system requesters flag. TRUE if all system
			 requesters are to be suppressed during this function.
			 FALSE if system requesters are allowed.

   RESULT
	success - TRUE will be returned if the entry is found and deleted.
		  If the entry is not found, FALSE will be returned.

