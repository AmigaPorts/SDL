# disk.resource/GetUnitID



NAME
   GetUnitID - find out what type of disk is out there

SYNOPSIS
   idtype = GetUnitID( unitNum ), DRResource

```c
    D0                  D0         A6

    LONG GetUnitID(LONG);
```
FUNCTION

```c
    Gets the drive ID for a given unit.  Note that this value may
    change if someone calls [ReadUnitID](../Includes_and_Autodocs_2._guide/node054B.html), and the drive id changes.
```
INPUTS

```c
    unitNum -- a legal unit number (zero through three)
```
RESULTS

    idtype -- the type of the disk drive.  Standard types are
            defined in the resource include file.
EXCEPTIONS

SEE ALSO

```c
    [ReadUnitID](../Includes_and_Autodocs_2._guide/node054B.html)
```
BUGS

