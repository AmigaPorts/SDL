# icon.library/GetDiskObject



   NAME
	GetDiskObject - read in a Workbench disk object from disk.

   SYNOPSIS
	diskobj = GetDiskObject(name)
	  D0                      A0

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *GetDiskObject(STRPTR);

   FUNCTION
	This routine reads in a Workbench disk object in from disk.  The
	name parameter will have ".info" postpended to it, and the
	icon file of that name will be read.  If the call fails,
	it will return NULL.  The reason for the failure may be obtained
	via [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

	A [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) structure is allocated just after the [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64)
	structure; [FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html) makes use of this to get rid of the
	memory that was allocated.

   INPUTS
	name -- name of the object (STRPTR) or NULL if you just want a
	        [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) structure allocated for you (useful when
	        calling AddAppIcon() in workbench.library).

   RESULTS
	diskobj -- the Workbench disk object in question

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/DeleteDiskObject](../Includes_and_Autodocs_3._guide/node0346.html)
	[icon.library/FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html)
	[icon.library/GetDiskObjectNew](../Includes_and_Autodocs_3._guide/node034E.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	[icon.library/NewDiskObject](../Includes_and_Autodocs_3._guide/node0354.html)
	[icon.library/PutDiskObject](../Includes_and_Autodocs_3._guide/node0356.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)
	[workbench.library/AddAppIconA](../Includes_and_Autodocs_3._guide/node05BA.html)

