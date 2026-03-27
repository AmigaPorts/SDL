# icon.library/PutDiskObject



   NAME
	PutDiskObject - write out a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) to disk.

   SYNOPSIS
	status = PutDiskObject(name, diskobj)
	 D0                    A0      A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) PutDiskObject(STRPTR, struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *);

   FUNCTION
	This routine writes out a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) structure, and its
	associated information.  The file name of the info
	file will be the name parameter with ".info" postpended
	to it.  If the call fails, FALSE will be returned.  The
	reason for the failure may be obtained via [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

	As of release V2.0, PutDiskObject() (if successful) notifies Workbench
	when an icon has been created/modified.

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

   INPUTS
	name -- name of the object (pointer to a character string)
	diskobj -- a pointer to a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64)

   RESULTS
	status -- TRUE if the call succeeded else FALSE

   NOTES
	It is recommended that if you wish to copy an icon from one place
	to another than you use [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html) and PutDiskObject()
	and do not copy them directly.

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/DeleteDiskObject](../Includes_and_Autodocs_3._guide/node0346.html)
	[icon.library/FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html)
	[icon.library/GetDiskObject](../Includes_and_Autodocs_3._guide/node034D.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)

