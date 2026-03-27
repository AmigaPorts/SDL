# dos.library/UnLockRecords



   NAME
	UnLockRecords -- Unlock a list of records (V36)

   SYNOPSIS
	success = UnLockRecords(record_array)
	D0		             D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) UnLockRecords(struct [RecordLock](../Includes_and_Autodocs_3._guide/node0641.html#line26) *)

   FUNCTION
	This releases an array of record locks obtained using [LockRecords](../Includes_and_Autodocs_3._guide/node0189.html).
	You should NOT modify the record_array while you have the records
	locked.  Every [LockRecords()](../Includes_and_Autodocs_3._guide/node0189.html) call must be balanced with an
	UnLockRecords() call.

   INPUTS
	record_array - [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) of records to be unlocked

   RESULT
	success      - Success or failure.

   BUGS
	See [LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html)

   SEE ALSO
	[LockRecords()](../Includes_and_Autodocs_3._guide/node0189.html), [LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html), [UnLockRecord()](../Includes_and_Autodocs_3._guide/node01CA.html)

