# dos.library/FindDosEntry



NAME

```c
    FindDosEntry -- Finds a specific Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) entry (V36)
```
SYNOPSIS

```c
    newdlist = FindDosEntry(dlist,name,flags)
    D0                       D1    D2   D3

    struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *FindDosEntry(struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *,STRPTR,ULONG)
```
FUNCTION

    Locates an entry on the device list.  Starts with the entry dlist.
    NOTE: must be called with the device list locked, no references may be
    made to dlist after unlocking.
INPUTS

```c
    dlist    - The device entry to start with.
    name     - Name of device entry (without ':') to locate.
    flags    - Search control flags.  Use the flags you passed to
               [LockDosList](../Includes_and_Autodocs_2._guide/node02C7.html), or a subset of them.  LDF_READ/LDF_WRITE are
               not required for this call.
```
RESULT

    newdlist - The device entry or NULL
SEE ALSO

```c
    [AddDosEntry()](../Includes_and_Autodocs_2._guide/node027C.html), [RemDosEntry()](../Includes_and_Autodocs_2._guide/node02E6.html), [NextDosEntry()](../Includes_and_Autodocs_2._guide/node02D5.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html),
    [MakeDosEntry()](../Includes_and_Autodocs_2._guide/node02CA.html), [FreeDosEntry()](../Includes_and_Autodocs_2._guide/node02B1.html)
```
