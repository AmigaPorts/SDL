# dos.library/Examine



NAME

    Examine -- Examine a directory or file associated with a lock
SYNOPSIS

```c
    success = Examine( lock, [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) )
    D0                  D1        D2

    BOOL Examine(BPTR,struct [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) *)
```
FUNCTION

```c
    Examine() fills in information in the [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) concerning the
    file or directory associated with the lock. This information
    includes the name, size, creation date and whether it is a file or
    directory.  [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) must be longword aligned.  Examine() gives
    a return code of zero if it fails.

    You may make a local copy of the [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62), as long as it is
    never passed to [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html).
```
INPUTS

```c
    lock      - BCPL pointer to a lock
    infoBlock - pointer to a [FileInfoBlock](../Includes_and_Autodocs_2._guide/node0068.html#line62) (MUST be longword aligned)
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
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html), [ExNext()](../Includes_and_Autodocs_2._guide/node02A0.html), [ExamineFH()](../Includes_and_Autodocs_2._guide/node029D.html), [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html), [AllocDosObject()](../Includes_and_Autodocs_2._guide/node027F.html),
    [ExAll()](../Includes_and_Autodocs_2._guide/node029B.html)
```
