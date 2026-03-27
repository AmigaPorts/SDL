# dos.library/UnLockRecord



   NAME
	UnLockRecord -- Unlock a record (V36)

   SYNOPSIS
	success = UnLockRecord(fh,offset,length)
	D0		       D1   D2     D3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) UnLockRecord(BPTR,ULONG,ULONG)

   FUNCTION
	This releases the specified lock on a file.  Note that you must use
	the same filehandle you used to lock the record, and offset and length
	must be the same values used to lock it.  Every [LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html) call must
	be balanced with an UnLockRecord() call.

   INPUTS
	fh      - File handle of locked file
	offset  - Record start position
	length  - Length of record in bytes

   RESULT
	success - Success or failure.

   BUGS
	See [LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html)

   SEE ALSO
	[LockRecords()](../Includes_and_Autodocs_3._guide/node0189.html), [LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html), [UnLockRecords()](../Includes_and_Autodocs_3._guide/node01CB.html)

