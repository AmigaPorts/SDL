# icon.library/GetDefDiskObject



   NAME
	GetDefDiskObject - read default wb disk object from disk.       (V36)

   SYNOPSIS
	diskobj = GetDefDiskObject(def_type)
	  D0                          D0

	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *GetDefDiskObject(LONG);

   FUNCTION
	This routine reads in a default Workbench disk object from disk.
	The valid def_types can be found in [workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html) and
	currently include WBDISK thru WBKICK. If the call fails,
	it will return NULL. The reason for the failure may be obtained
	via [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).

	Using this routine protects you from any future changes to
	the way default icons are stored within the system.

   INPUTS
	def_type -- default icon type (WBDISK thru WBKICK).

   RESULTS
	diskobj -- the default Workbench disk object in question

   NOTES
	icon.library V36 through V40 did not support the WBDEVICE default
	icon type.

   SEE ALSO
	[dos.library/IoErr](../Includes_and_Autodocs_3._guide/node0182.html)
	[icon.library/PutDefDiskObject](../Includes_and_Autodocs_3._guide/node0355.html)
	[icon.library/PutIconTagList](../Includes_and_Autodocs_3._guide/node0357.html)

