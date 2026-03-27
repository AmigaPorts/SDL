# dos.library/RemDosEntry



NAME

```c
    RemDosEntry -- Removes a Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) entry from it's list (V36)
```
SYNOPSIS

```c
    success = RemDosEntry(dlist)
    D0                     D1

    BOOL RemDosEntry(struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *)
```
FUNCTION

```c
    This removes an entry from the Dos [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) list.  The memory associated
    with the entry is NOT freed.  NOTE: you must have locked the Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21)
    with the appropriate flags before calling this routine.  Handler
    writers should see the [AddDosEntry()](../Includes_and_Autodocs_2._guide/node027C.html) caveats about locking and use
    a similar workaround to avoid deadlocks.
```
INPUTS

```c
    dlist   - [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) list entry to be removed.
```
RESULT

    success - Success/failure indicator
SEE ALSO

```c
    [AddDosEntry()](../Includes_and_Autodocs_2._guide/node027C.html), [FindDosEntry()](../Includes_and_Autodocs_2._guide/node02A7.html), [NextDosEntry()](../Includes_and_Autodocs_2._guide/node02D5.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html),
    [MakeDosEntry()](../Includes_and_Autodocs_2._guide/node02CA.html), [FreeDosEntry()](../Includes_and_Autodocs_2._guide/node02B1.html)
```
