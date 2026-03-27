# nonvolatile.library/StoreNV



   NAME
	StoreNV -- store data in nonvolatile storage. (V40)

   SYNOPSIS
	error = StoreNV(appName, itemName, data, length, killRequesters);
	D0		A0	 A1	   A2    D0	 D1

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) StoreNV(STRPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37), ULONG, BOOL);

   FUNCTION
	Saves some data in nonvolatile storage. The data is tagged with
	AppName and ItemName so it can be retrieved later. No single
	item should be larger than one fourth of the maximum storage as
	returned by [GetNVInfo()](../Includes_and_Autodocs_3._guide/node04DF.html).

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
	[GetCopyNV()](../Includes_and_Autodocs_3._guide/node04DE.html), [GetNVInfo()](../Includes_and_Autodocs_3._guide/node04DF.html)

