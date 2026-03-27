# disk.resource/AllocUnit



   NAME

       AllocUnit - allocate a unit of the disk
   SYNOPSIS
```c
       Success = AllocUnit( unitNum ), DRResource
```
	D0     	             D0         A6

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AllocUnit(LONG);

   FUNCTION
	This routine allocates one of the units of the disk.  It should
	be called before trying to use the disk (via GetUnit).

	In reality, it is perfectly fine to use [GetUnit/GiveUnit](../Includes_and_Autodocs_3._guide/node0130.html) if AllocUnit
	fails.  Do NOT call [FreeUnit](../Includes_and_Autodocs_3._guide/node012D.html) if AllocUnit did not succeed.  This
	has been the case for all revisions of disk.resource.

   INPUTS
	unitNum -- a legal unit number (zero through three)

   RESULTS
	Success -- nonzero if successful.  zero on failure.

   EXCEPTIONS

   SEE ALSO

   BUGS

