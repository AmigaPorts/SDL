# dos.library/MakeDosEntry



NAME

```c
    MakeDosEntry -- Creates a [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) structure (V36)
```
SYNOPSIS

```c
    newdlist = MakeDosEntry(name, type)
    D0                       D1    D2

    struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *MakeDosEntry(STRPTR, LONG)
```
FUNCTION

```c
    Create a [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) structure, including allocating a name and correctly
    null-terminating the BSTR.  It also sets the dol_Type field, and sets
    all other fields to 0.  This routine should be eliminated and replaced
    by a value passed to AllocDosObject()!
```
INPUTS

    name - name for the device/volume/assign node.
    type - type of node.
RESULT

    newdlist - The new device entry or NULL.
SEE ALSO

```c
    [AddDosEntry()](../Includes_and_Autodocs_2._guide/node027C.html), [RemDosEntry()](../Includes_and_Autodocs_2._guide/node02E6.html), [FindDosEntry()](../Includes_and_Autodocs_2._guide/node02A7.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html),
    [NextDosEntry()](../Includes_and_Autodocs_2._guide/node02D5.html), [FreeDosEntry()](../Includes_and_Autodocs_2._guide/node02B1.html)
```
