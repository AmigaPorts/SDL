# icon.library/GetDefDiskObject



NAME

```c
    GetDefDiskObject - read default wb disk object from disk.       (V36)
```
SYNOPSIS

```c
    diskobj = GetDefDiskObject(def_type)
     D0                          D0

    struct [DiskObject](../Includes_and_Autodocs_2._guide/node0135.html#line61) *GetDefDiskObject(LONG);
```
FUNCTION

```c
    This routine reads in a default Workbench disk object from disk.
    The valid def_types can be found in [workbench/workbench.h](../Includes_and_Autodocs_2._guide/node0135.html) and
    currently include WBDISK thru WBGARBAGE.  If the call fails,
    it will return zero.  The reason for the failure may be obtained
    via [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).

    Using this routine protects you from any future changes to
    the way default icons are stored within the system.
```
INPUTS

```c
    def_type - default icon type (WBDISK thru WBKICK).  Note that the
               define 'WBDEVICE' is not currently supported.
```
RESULTS

    diskobj -- the default Workbench disk object in question
SEE ALSO

```c
    [PutDefDiskObject](../Includes_and_Autodocs_2._guide/node018D.html)
```
BUGS

    None
