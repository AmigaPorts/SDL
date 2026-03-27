# dos.library/ExNext



NAME

    ExNext -- Examine the next entry in a directory
SYNOPSIS

```c
    success = ExNext( lock, [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) )
    D0                 D1        D2

    BOOL ExNext(BPTR, struct [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) *)
```
FUNCTION

```c
    This routine is passed a directory lock and a [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) that
    have been initialized by a previous call to [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), or updated
    by a previous call to ExNext().  ExNext() gives a return code of zero
    on failure.  The most common cause of failure is reaching the end
    of the list of files in the owning directory.  In this case, [IoErr](../Includes_and_Autodocs_2._guide/node02C2.html)
    will return ERROR_NO_MORE_ENTRIES and a good exit is appropriate.

    So, follow these steps to examine a directory:
    1) Pass a Lock and a [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) to [Examine()](../Includes_and_Autodocs_2._guide/node029C.html).  The lock must
       be on the directory you wish to examine.
    2) Pass ExNext() the same lock and [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62).
    3) Do something with the information returned in the [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62).
       Note that the fib_DirEntryType field is positive for directories,
       negative for files.
    4) Keep calling ExNext() until it returns FALSE.  Check [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html)
       to ensure that the reason for failure was ERROR_NO_MORE_ENTRIES.

    Note: if you wish to recursively scan the file tree and you find
    another directory while ExNext()ing you must Lock that directory and
    [Examine()](../Includes_and_Autodocs_2._guide/node029C.html) it using a new [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62).  Use of the same
    [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) to enter a directory would lose important state
    information such that it will be impossible to continue scanning
    the parent directory.  While it is permissible to [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html) and [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html)
    the parent directory between ExNext() calls, this is NOT recommended.
    Important state information is associated with the parent lock, so
    if it is freed between ExNext() calls this information has to be
    rebuilt on each new ExNext() call, and will significantly slow down
    directory scanning.

    It is NOT legal to [Examine()](../Includes_and_Autodocs_2._guide/node029C.html) a file, and then to ExNext() from that
    [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62).       You may make a local copy of the [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62), as
    long as it is never passed back to the operating system.
```
INPUTS

```c
    lock - BCPL pointer to a lock originally used for the [Examine()](../Includes_and_Autodocs_2._guide/node029C.html) call
    infoBlock - pointer to a [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) used on the previous [Examine()](../Includes_and_Autodocs_2._guide/node029C.html)
                or ExNext() call.
```
RESULTS

    success - boolean
SPECIAL NOTE

```c
    [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) must be longword-aligned.  [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html) will
    allocate them correctly for you.
```
SEE ALSO

```c
    [Examine()](../Includes_and_Autodocs_2._guide/node029C.html), [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html), [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html), [ExamineFH()](../Includes_and_Autodocs_2._guide/node029D.html), [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html),
    [ExAll()](../Includes_and_Autodocs_2._guide/node029B.html)
```
