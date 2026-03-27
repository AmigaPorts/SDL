---
title: nonvolatile.library/StoreNV
manual: autodocs-3.5
chapter: autodocs-3.5
section: nonvolatile-library-storenv
functions: []
libraries: []
---

# nonvolatile.library/StoreNV

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StoreNV -- store data in nonvolatile storage. (V40)

   SYNOPSIS
	error = StoreNV(appName, itemName, data, length, killRequesters);
	D0		A0	 A1	   A2    D0	 D1

	[UWORD](autodocs-3.5/include-exec-types-h.md) StoreNV(STRPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), [APTR](autodocs-3.5/include-exec-types-h.md), ULONG, BOOL);

   FUNCTION
	Saves some data in nonvolatile storage. The data is tagged with
	AppName and ItemName so it can be retrieved later. No single
	item should be larger than one fourth of the maximum storage as
	returned by [GetNVInfo()](autodocs-3.5/nonvolatile-library-getnvinfo.md).

	There is no data compression associated with this function.

	The strings, AppName and ItemName, should be short, but descriptive.
	They need to be short since the string is stored with the data and
	the nonvolatile storage for a stand alone game system is limited.
	The game system allows the user to selectively remove entries from
	storage, so the string should be desriptive.

	The strings AppName and ItemName may not contain the '/' or ':'
	characters. It is recommended that these characters be blocked
	from user input when requesting AppName and ItemName strings.

   INPUTS
	appName - NULL terminated string identifying the application
		  creating the data. Maximum length is 31.
	itemName - NULL terminated string uniquely identifying the data
		   within the application. Maximum length is 31.
	data - pointer to the memory block to be stored.
	length - number of bytes to be stored in the units of tens of
		 bytes. For example, if you have 23 bytes to store length = 3;
		 147 byte then length = 15.
	killRequesters - suppress system requesters flag. TRUE if all system
			 requesters are to be suppressed during this function.
			 FALSE if system requesters are allowed.

   RESULT
	error - 0                means no error,
	        NVERR_BADNAME    error in AppName, or ItemName.
	        NVERR_WRITEPROT  Nonvolatile storage is read only.
	        NVERR_FAIL       Failure in writing data (nonvolatile storage
				 full, or write protected).
	        NVERR_FATAL      Fatal error when accessing nonvolatile
				 storage, possible loss of previously saved
				 nonvolatile data.

   SEE ALSO
	[GetCopyNV()](autodocs-3.5/nonvolatile-library-getcopynv.md), [GetNVInfo()](autodocs-3.5/nonvolatile-library-getnvinfo.md)

