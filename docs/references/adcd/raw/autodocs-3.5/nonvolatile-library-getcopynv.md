# nonvolatile.library/GetCopyNV



   NAME
	GetCopyNV -- return a copy of an item stored in nonvolatile storage.
		     (V40)

   SYNOPSIS
	data = GetCopyNV(appName, itemName, killRequesters);
	D0		 A0	  A1	    D1

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) GetCopyNV(STRPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), BOOL);

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
	[FreeNVData()](../Includes_and_Autodocs_3._guide/node04DD.html), [<libraries/nonvolatile.h>](../Includes_and_Autodocs_3._guide/node0635.html)

