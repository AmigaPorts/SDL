# icon.library/FreeDiskObject



   NAME
	FreeDiskObject - free all memory in a Workbench disk object.

   SYNOPSIS
	FreeDiskObject(diskobj)
	               A0

	void FreeDiskObject(struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *);

   FUNCTION
	This routine frees all memory in a Workbench disk object, and the
	object itself.  It is implemented via [FreeFreeList()](../Includes_and_Autodocs_3._guide/node034B.html).

	[GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html) takes care of all the initialization required
	to set up the object's free list.  This procedure may ONLY
	be called on a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) allocated via [GetDiskObject()](../Includes_and_Autodocs_3._guide/node034D.html).

   INPUTS
	diskobj -- a pointer to a [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) structure; as of V44,
	    a NULL diskobj pointer will be ignored.

   SEE ALSO
	[icon.library/GetDiskObject](../Includes_and_Autodocs_3._guide/node034D.html)
	[icon.library/PutDiskObject](../Includes_and_Autodocs_3._guide/node0356.html)
	[icon.library/DeleteDiskObject](../Includes_and_Autodocs_3._guide/node0346.html)
	[icon.library/FreeFreeList](../Includes_and_Autodocs_3._guide/node034B.html)
	[icon.library/GetIconTagList](../Includes_and_Autodocs_3._guide/node0350.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)

