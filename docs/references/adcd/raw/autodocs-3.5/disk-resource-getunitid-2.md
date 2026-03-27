# disk.resource/GetUnitID



   NAME

       GetUnitID - find out what type of disk is out there
   SYNOPSIS
```c
       idtype = GetUnitID( unitNum ), DRResource
```
	D0	            D0         A6

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) GetUnitID(LONG);

   FUNCTION
	Gets the drive ID for a given unit.  Note that this value may
	change if someone calls [ReadUnitID](../Includes_and_Autodocs_3._guide/node0131.html), and the drive id changes.

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS
	idtype -- the type of the disk drive.  Standard types are
		defined in the resource include file.

   EXCEPTIONS

   SEE ALSO
	[ReadUnitID()](../Includes_and_Autodocs_3._guide/node0131.html)

   BUGS

