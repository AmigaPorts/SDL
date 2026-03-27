# icon.library/PutDefDiskObject



   NAME
	PutDefDiskObject - write disk object as the default for its type.  (V36)

   SYNOPSIS
	status = PutDefDiskObject(diskobj)
	  D0                        A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) PutDefDiskObject(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *);

   FUNCTION
	This routine writes out a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) structure, and its
	associated information.  If the call fails, FALSE will
	be returned.  The reason for the failure may be obtained
	via [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

	Note that this function calls [PutDiskObject()](../Includes_and_Autodocs_3._guide/node0356.html) internally which means
	that this call (if sucessful) notifies workbench than an icon has
	been created/modified.

	Using this routine protects you from any future changes to
	the way default icons are stored within the system.

   INPUTS
	diskobj -- a pointer to a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64)

   RESULTS
	status -- TRUE if the call succeeded else FALSE

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/GetDefDiskObject](../Includes_and_Autodocs_3._guide/node034C.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	[icon.library/PutDiskObject](../Includes_and_Autodocs_3._guide/node0356.html)

