# icon.library/GetDiskObject



NAME

    GetDiskObject - read in a Workbench disk object from disk.
SYNOPSIS

```c
    diskobj = GetDiskObject(name)
      D0                      A0

    struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *GetDiskObject(char *);
```
FUNCTION

```c
    This routine reads in a Workbench disk object in from disk.  The
    name parameter will have a ".info" postpended to it, and the
    info file of that name will be read.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    Using this routine protects you from any future changes to
    the way icons are stored within the system.

    A [FreeList](../Includes_and_Autodocs_2._guide/node0135.html#line82) structure is allocated just after the [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61)
    structure; [FreeDiskObject](../Includes_and_Autodocs_2._guide/node0187.html) makes use of this to get rid of the
    memory that was allocated.
```
INPUTS

```c
    name -- name of the object (char *) or NULL if you just want a
            [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) structure allocated for you (useful when
            calling AddAppIcon in workbench.library).
```
RESULTS

    diskobj -- the Workbench disk object in question
SEE ALSO

```c
    [GetDiskObjectNew()](../Includes_and_Autodocs_2._guide/node018B.html), [PutDiskObject()](../Includes_and_Autodocs_2._guide/node018E.html), [DeleteDiskObject()](../Includes_and_Autodocs_2._guide/node0185.html),
    [FreeDiskObject()](../Includes_and_Autodocs_2._guide/node0187.html)
```
BUGS

    None
