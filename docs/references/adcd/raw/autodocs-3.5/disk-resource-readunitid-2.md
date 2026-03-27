# disk.resource/ReadUnitID



   NAME

```c
       ReadUnitID - reread and return the type of drive (V37)
```
   SYNOPSIS
```c
       idtype = ReadUnitID( unitNum ), DRResource
```
	D0	               D0         A6

	ULONG ReadUnitID(LONG);

   FUNCTION
	Rereads the drive id for a specific unit (for handling drives
	that change ID according to what sort of disk is in them.  You
	MUST have done a [GetUnit](../Includes_and_Autodocs_3._guide/node012E.html) before calling this function!

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS
	idtype -- the type of the disk drive.  Standard types are
		defined in the resource include file.

   EXCEPTIONS

   SEE ALSO
	[GetUnitID()](../Includes_and_Autodocs_3._guide/node012F.html)

   BUGS

