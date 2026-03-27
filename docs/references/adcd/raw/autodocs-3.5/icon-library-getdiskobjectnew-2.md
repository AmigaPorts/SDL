# icon.library/GetDiskObjectNew



   NAME
	GetDiskObjectNew - read in a Workbench disk object from disk.    (V36)

   SYNOPSIS
	diskobj = GetDiskObjectNew(name)
	  D0                      A0

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *GetDiskObjectNew(STRPTR);

   FUNCTION
	This routine reads in a Workbench disk object in from disk.  The
	name parameter will have ".info" postpended to it, and the
	icon file of that name will be read.  If the call fails,
	it will return zero.  The reason for the failure may be obtained
	via [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

	A [FreeList](../Includes_and_Autodocs_3._guide/node05D6.html#line85) structure is allocated just after the [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64)
	structure; [FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html) makes use of this to get rid of the
	memory that was allocated.

	This call is functionally identical to [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html) with one
	exception. If its call to [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html) fails, this function calls
	[GetDefDiskObject()](../Includes_and_Autodocs_3._guide/node034C.html). This is useful when there is no .info file for the
	icon you are trying to get a disk object for. Applications that use
	workbench application windows MUST use this call if they want to handle
	the user dropping an icon (that doesn't have a ".info" file) on their
	window. The V2.0 icon editor program is an example of a Workbench
	application window that uses this call.

   INPUTS
	name -- name of the object (STRPTR) or NULL if you just want a
	        [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) structure allocated for you (useful when
	        calling AddAppIcon() in workbench.library).

   RESULTS
	diskobj -- the Workbench disk object in question

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html)
	[icon.library/GetDiskObject](../Includes_and_Autodocs_3._guide/node034D.html)
	[icon.library/PutDiskObject](../Includes_and_Autodocs_3._guide/node0356.html)
	[icon.library/DeleteDiskObject](../Includes_and_Autodocs_3._guide/node0346.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)
	[workbench.library/AddAppIconA](../Includes_and_Autodocs_3._guide/node05BA.html)

