# nonvolatile.library/SetNVProtection



   NAME
	SetNVProtection -- set the protection flags. (V40)

   SYNOPSIS
	success = SetNVProtection(appName, itemName, mask, killRequesters);
	D0			  A0	   A1	     D2    D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetNVProtection(STRPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), BOOL);

   FUNCTION
	Sets the protection attributes for an item currently in the
	nonvolatile storage.

	Although 'mask' is [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) only the delete bit, NVEF_DELETE/NVEB_DELETE,
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
	[GetNVList()](../Includes_and_Autodocs_3._guide/node04E0.html), [<libraries/nonvolatile.h>](../Includes_and_Autodocs_3._guide/node0635.html)

