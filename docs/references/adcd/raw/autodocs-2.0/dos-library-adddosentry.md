# dos.library/AddDosEntry



NAME

```c
    AddDosEntry -- Add a Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) entry to the lists (V36)
```
SYNOPSIS

```c
    success = AddDosEntry(dlist)
    D0                     D1

    LONG AddDosEntry(struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *)
```
FUNCTION

```c
    Adds a device, volume or assign to the dos devicelist.  Can fail if it
    conflicts with an existing entry (such as another assign to the same
    name or another device of the same name).  Volume nodes with different
    dates and the same name CAN be added, or with names that conflict with
    devices or assigns.  Note: the dos list does NOT have to be locked to
    call this.  Do not access dlist after adding unless you have locked the
    Dos [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) list.

    An additional note concerning calling this from within a handler:
    in order to avoid deadlocks, your handler must either be multi-
    threaded, or it must attempt to lock the list before calling this
    function.  The code would look something like this:

    if (AttemptLockDosList(LDF_xxx|LDF_WRITE))
    {
            rc = AddDosEntry(...);
            UnLockDosList(LDF_xxx|LDF_WRITE);
    }

    If [AttemptLockDosList()](../Includes_and_Autodocs_2._guide/node0284.html) fails (i.e. it's locked already), check for
    messages at your filesystem port (don't wait!) and try the
    [AttemptLockDosList()](../Includes_and_Autodocs_2._guide/node0284.html) again.
```
INPUTS

```c
    dlist   - [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) list entry to be added.
```
RESULT

    success - Success/Failure indicator
SEE ALSO

```c
    [RemDosEntry()](../Includes_and_Autodocs_2._guide/node02E6.html), [FindDosEntry()](../Includes_and_Autodocs_2._guide/node02A7.html), [NextDosEntry()](../Includes_and_Autodocs_2._guide/node02D5.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html),
    [MakeDosEntry()](../Includes_and_Autodocs_2._guide/node02CA.html), [FreeDosEntry()](../Includes_and_Autodocs_2._guide/node02B1.html), [AttemptLockDosList()](../Includes_and_Autodocs_2._guide/node0284.html)
```
