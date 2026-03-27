# disk.resource/ReadUnitID



NAME
   ReadUnitID - reread and return the type of drive (V37)

SYNOPSIS
   idtype = ReadUnitID( unitNum ), DRResource

```c
    D0                     D0         A6

    ULONG ReadUnitID(LONG);
```
FUNCTION

```c
    Rereads the drive id for a specific unit (for handling drives
    that change ID according to what sort of disk is in them.  You
    MUST have done a [GetUnit](../Includes_and_Autodocs_2._guide/node0548.html) before calling this function!
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
    [GetUnitID](../Includes_and_Autodocs_2._guide/node0549.html)
```
BUGS

