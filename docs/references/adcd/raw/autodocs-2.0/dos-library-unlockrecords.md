# dos.library/UnLockRecords



NAME

```c
    UnLockRecords -- Unlock a list of records (V36)
```
SYNOPSIS

```c
    success = UnLockRecords(record_array)
    D0                           D1

    BOOL UnLockRecords(struct [RecordLock](../Includes_and_Autodocs_2._guide/node0063.html#line28) *)
```
FUNCTION

```c
    This releases an array of record locks obtained using [LockRecords](../Includes_and_Autodocs_2._guide/node02C9.html).
    You should NOT modify the record_array while you have the records
    locked.  Every [LockRecords()](../Includes_and_Autodocs_2._guide/node02C9.html) call must be balanced with an
    UnLockRecords() call.
```
INPUTS

```c
    record_array - [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) of records to be unlocked
```
RESULT

    success      - Success or failure.
BUGS

```c
    See [LockRecord()](../Includes_and_Autodocs_2._guide/node02C8.html)
```
SEE ALSO

```c
    [LockRecords()](../Includes_and_Autodocs_2._guide/node02C9.html), [LockRecord()](../Includes_and_Autodocs_2._guide/node02C8.html), [UnLockRecord()](../Includes_and_Autodocs_2._guide/node0309.html)
```
