# icon.library/PutDiskObject



NAME

```c
    PutDiskObject - write out a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) to disk.
```
SYNOPSIS

```c
    status = PutDiskObject(name, diskobj)
      D0                    A0      A1

    BOOL PutDiskObject(char *, struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *);
```
FUNCTION

```c
    This routine writes out a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) structure, and its
    associated information.  The file name of the info
    file will be the name parameter with a
    ".info" postpended to it.  If the call fails, a zero will
    be returned.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    As of release V2.0, PutDiskObject (if sucessful) notifies workbench
    han an icon has been created/modified.

    Using this routine protects you from any future changes to
    the way icons are stored within the system.
```
INPUTS

```c
    name -- name of the object (pointer to a character string)
    diskobj -- a pointer to a [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61)
```
RESULTS

    status -- TRUE if the call succeeded else FALSE
NOTES

```c
    It is recommended that if you wish to copy an icon from one place
    to another than you use [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html) and PutDiskObject()
    and do not copy them directly.
```
SEE ALSO

```c
    [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html), [FreeDiskObject()](../Includes_and_Autodocs_2._guide/node0187.html), [DeleteDiskObject()](../Includes_and_Autodocs_2._guide/node0185.html)
```
BUGS

    None
