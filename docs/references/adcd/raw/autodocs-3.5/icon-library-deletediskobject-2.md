# icon.library/DeleteDiskObject



   NAME
	DeleteDiskObject - Delete a Workbench disk object from disk.     (V37)

   SYNOPSIS
	result = DeleteDiskObject(name)
	  D0                      A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) DeleteDiskObject(STRPTR);

   FUNCTION
	This routine will try to delete a Workbench disk object from disk.
	The name parameter will have ".info" postpended to it, and the
	icon file of that name will be deleted.  If the call fails,
	it will return FALSE. The reason for the failure may be obtained
	via [dos.library/IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

	This call also updates the Workbench screen if needed.

	Using this routine protects you from any future changes to
	the way icons are stored within the system.

   INPUTS
	name -- name of the object (char *)

   RESULTS
	result -- TRUE if it worked, FALSE if not.

   EXAMPLE

	error = 0;

	/* Check if you have the right library version */
	if(IconBase->lib_Version > 36)
	{
	    if (!DeleteDiskObject(name))
	        error = IoErr();
	}
	else
	{
	    /* Delete name plus ".info" */
	}

	if (error != 0)
	{
	    /* Do error routine...*/
	}

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/PutDiskObject](../Includes_and_Autodocs_3._guide/node0356.html)
	[icon.library/GetDiskObject](../Includes_and_Autodocs_3._guide/node034D.html)
	[icon.library/FreeDiskObject](../Includes_and_Autodocs_3._guide/node034A.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)

