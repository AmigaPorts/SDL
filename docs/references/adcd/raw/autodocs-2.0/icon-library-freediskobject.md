# icon.library/FreeDiskObject



NAME

    FreeDiskObject - free all memory in a Workbench disk object.
SYNOPSIS

```c
    FreeDiskObject(diskobj)
                    A0

    void FreeDiskObject(struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *);
```
FUNCTION

```c
    This routine frees all memory in a Workbench disk object, and the
    object itself.  It is implemented via [FreeFreeList()](../Includes_and_Autodocs_2._guide/node0188.html).

    [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html) takes care of all the initialization required
    to set up the object's free list.  This procedure may ONLY
    be called on a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) allocated via [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html).
```
INPUTS

```c
    diskobj -- a pointer to a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) structure
```
RESULTS

    None
SEE ALSO

```c
    [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html), [PutDiskObject()](../Includes_and_Autodocs_2._guide/node018E.html), [DeleteDiskObject()](../Includes_and_Autodocs_2._guide/node0185.html), [FreeFreeList()](../Includes_and_Autodocs_2._guide/node0188.html)
```
BUGS

    None
