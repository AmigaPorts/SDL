# dos.library/NextDosEntry



NAME

```c
    NextDosEntry -- Get the next Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) entry (V36)
```
SYNOPSIS

```c
    newdlist = NextDosEntry(dlist,flags)
    D0                       D1    D2

    struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *NextDosEntry(struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *,ULONG)
```
FUNCTION

```c
    Find the next Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) entry of the right type.  You MUST have locked
    the types you're looking for.  Returns NULL if there are no more of
    that type in the list.
```
INPUTS

    dlist    - The current device entry.
    flags    - What type of entries to look for.
RESULT

    newdlist - The next device entry of the right type or NULL.
SEE ALSO

```c
    [AddDosEntry()](../Includes_and_Autodocs_2._guide/node027C.html), [RemDosEntry()](../Includes_and_Autodocs_2._guide/node02E6.html), [FindDosEntry()](../Includes_and_Autodocs_2._guide/node02A7.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html),
    [MakeDosEntry()](../Includes_and_Autodocs_2._guide/node02CA.html), [FreeDosEntry()](../Includes_and_Autodocs_2._guide/node02B1.html)
```
