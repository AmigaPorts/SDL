# dos.library/LockRecords



   NAME
	LockRecords -- [Lock](../Includes_and_Autodocs_3._guide/node0186.html) a series of records (V36)

   SYNOPSIS
	success = LockRecords(record_array,timeout)
	D0                       D1           D2

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) LockRecords(struct [RecordLock](../Includes_and_Autodocs_3._guide/node0641.html#line26) *,ULONG)

   FUNCTION
	This locks several records within a file for exclusive access.
	Timeout is how long to wait in ticks for the records to be available.
	The wait is applied to each attempt to lock each record in the list.
	It is recommended that you always lock a set of records in the same
	order to reduce possibilities of deadlock.

	The array of [RecordLock](../Includes_and_Autodocs_3._guide/node0641.html#line26) structures is terminated by an entry with
	rec_FH of NULL.

   INPUTS
	record_array - [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) of records to be locked
	timeout      - Timeout interval.  0 is legal

   RESULT
	success      - Success or failure

   BUGS
	See [LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html)

   SEE ALSO
	[LockRecord()](../Includes_and_Autodocs_3._guide/node0188.html), [UnLockRecord()](../Includes_and_Autodocs_3._guide/node01CA.html), [UnLockRecords()](../Includes_and_Autodocs_3._guide/node01CB.html)

