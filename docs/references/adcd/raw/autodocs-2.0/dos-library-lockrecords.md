# dos.library/LockRecords



NAME

```c
    LockRecords -- Lock a series of records (V36)
```
SYNOPSIS

```c
    success = LockRecords(record_array,timeout)
    D0                       D1           D2

    BOOL LockRecords(struct [RecordLock](../Includes_and_Autodocs_2._guide/node0063.html#line28) *,ULONG)
```
FUNCTION

```c
    This locks several records within a file for exclusive access.
    Timeout is how long to wait in ticks for the records to be available.
    The wait is applied to each attempt to lock each record in the list.
    It is recommended that you always lock a set of records in the same
    order to reduce possibilities of deadlock.

    The array of [RecordLock](../Includes_and_Autodocs_2._guide/node0063.html#line28) structures is terminated by an entry with
    rec_FH of NULL.
```
INPUTS

```c
    record_array - [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) of records to be locked
    timeout      - Timeout interval.  0 is legal
```
RESULT

    success      - Success or failure
BUGS

```c
    See [LockRecord()](../Includes_and_Autodocs_2._guide/node02C8.html)
```
SEE ALSO

```c
    [LockRecord()](../Includes_and_Autodocs_2._guide/node02C8.html), [UnLockRecord()](../Includes_and_Autodocs_2._guide/node0309.html), [UnLockRecords()](../Includes_and_Autodocs_2._guide/node030A.html)
```
