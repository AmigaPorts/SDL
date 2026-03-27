# disk.resource/GiveUnit



NAME
   GiveUnit - Free the disk back up

SYNOPSIS
   GiveUnit(), DRResource

```c
                A6

    void GiveUnit();
```
FUNCTION

    This routine frees the disk after a driver is done with it.
    If others are waiting, it will notify them.
INPUTS

RESULTS

EXCEPTIONS

SEE ALSO

```c
    [GetUnit](../Includes_and_Autodocs_2._guide/node0548.html)
```
BUGS

    In pre-V36, GiveUnit didn't check if you owned the unit.  A patch
    for this was part of 1.3.1 SetPatch.  Fixed in V36.
