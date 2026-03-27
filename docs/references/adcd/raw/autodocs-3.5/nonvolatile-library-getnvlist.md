# nonvolatile.library/GetNVList



   NAME
	GetNVList -- return a list of the items stored in nonvolatile
		     storage. (V40)

   SYNOPSIS
	list = GetNVList(appName, killRequesters);
	D0		 A0	  D1

	struct [MinList](../Includes_and_Autodocs_3._guide/node0628.html#line30) *GetNVList(STRPTR, BOOL);

   FUNCTION
	Returns a pointer to an Exec list of nonvolatile Items associated
	with the appName requested.

	The string appName may not contain the '/' or ':' characters.
	It is recommended that these characters be blocked from user input
	when requesting an appName string.

   INPUTS
	appName - NULL terminated string indicating the application name
		  to be matched. Maximum length is 31.
	killRequesters - Suppress system requesters flag. TRUE if all system
			 requesters are to be suppressed during this function.
			 FALSE if system requesters are allowed.

   RESULT
	list - a pointer to an Exec [MinList](../Includes_and_Autodocs_3._guide/node0628.html#line30) of NVEntries. A NULL will be
	       returned if there is insufficient memory. If there are no
	       entries in the nonvolatile storage for the AppName, an
	       empty list will be returned.

   NOTE
	The protection field contains more bits than are required for
	storing the delete protection status. These bits are reserved
	for other system usage and may not be zero. When checking for
	the delete status use either the field mask NVIF_DELETE, or the
	bit definition NVIB_DELETE.

   SEE ALSO
	[FreeNVData()](../Includes_and_Autodocs_3._guide/node04DD.html), [SetNVProtection()](../Includes_and_Autodocs_3._guide/node04E1.html)

