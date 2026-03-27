# disk.resource/GiveUnit



   NAME

       GiveUnit - Free the disk back up
   SYNOPSIS

```c
       GiveUnit(), DRResource
           	    A6
```
	void GiveUnit();

   FUNCTION
	This routine frees the disk after a driver is done with it.
	If others are waiting, it will notify them.

   INPUTS

   RESULTS

   EXCEPTIONS

   SEE ALSO
	[GetUnit()](../Includes_and_Autodocs_3._guide/node012E.html)

   BUGS
	In pre-V36, GiveUnit didn't check if you owned the unit.  A patch
	for this was part of 1.3.1 SetPatch.  Fixed in V36.

