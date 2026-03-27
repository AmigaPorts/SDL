# 15 Resources / Disk Resource


The Disk resource obtains exclusive access to the floppy disk hardware
There are four disk/MFM units available, units 0-3.

Six functions are available for dealing with the floppy disk hardware.


```c
                      Disk Resource Functions
                      -----------------------
     [AllocUnit()](../Includes_and_Autodocs_2._guide/node0546.html)      Allocate one of the units of the disk
                      resource.

     [FreeUnit()](../Includes_and_Autodocs_2._guide/node0547.html)       Deallocate an allocated disk unit.

     [GetUnit()](../Includes_and_Autodocs_2._guide/node0548.html)        Allocate the disk for a driver.

     [GetUnitID()](../Includes_and_Autodocs_2._guide/node0549.html)      Return the drive ID of a specified drive
                      unit.

     [GiveUnit()](../Includes_and_Autodocs_2._guide/node054A.html)       Free the disk.

     [ReadUnitID()](../Includes_and_Autodocs_2._guide/node054B.html)     Reread and return the drive ID of a
                      specified unit.
```
The disk resource provides both a gross and a fine unit allocation scheme.
[AllocUnit()](../Includes_and_Autodocs_2._guide/node0546.html) and [FreeUnit()](../Includes_and_Autodocs_2._guide/node0547.html) are used to claim a unit for long term use, and
[GetUnit()](../Includes_and_Autodocs_2._guide/node0548.html) and [GiveUnit()](../Includes_and_Autodocs_2._guide/node054A.html) are used to claim a unit and the disk hardware
for shorter periods.

The trackdisk device uses and abides by both allocation schemes.  Because
a trackdisk unit is never closed for Amiga 3.5" drives (the file system
keeps them open) the associated resource units will always be allocated
for these drives.  [GetUnit()](../Includes_and_Autodocs_2._guide/node0548.html) and [GiveUnit()](../Includes_and_Autodocs_2._guide/node054A.html) can still be used, however, by
other applications that have not succeeded with [AllocUnit()](../Includes_and_Autodocs_2._guide/node0546.html).

You must not change the state of of a disk that the trackdisk device is
using unless you either

   a) force its removal before giving it up, or

   b) return it to the original track (with no changes to the track), or

   c) CMD_STOP the unit before [GetUnit()](../Includes_and_Autodocs_2._guide/node0548.html), update the current track number

```c
      and CMD_START it after [GiveUnit()](../Includes_and_Autodocs_2._guide/node054A.html).  This option is only available
      under V36 and higher versions of the operating system.
```
[ReadUnitID()](../Includes_and_Autodocs_2._guide/node054B.html) is provided to handle drives which use the unit number in a
dynamic manner.  Subsequent [GetUnit()](../Includes_and_Autodocs_2._guide/node0548.html) calls will return the value obtained
by ReadUnitID().

It is therefore possible to prevent the trackdisk device from using units
that have not yet been mounted by successfully performing an [AllocUnit()](../Includes_and_Autodocs_2._guide/node0546.html)
for that unit.  It is also possible to starve trackdisk usage by
performing a [GetUnit()](../Includes_and_Autodocs_2._guide/node0548.html). The appropriate companion routine ([FreeUnit()](../Includes_and_Autodocs_2._guide/node0547.html) or
[GiveUnit()](../Includes_and_Autodocs_2._guide/node054A.html)) should be called to restore the resource at the end of its use.


```c
     [Get_Disk_Unit_ID.c](../Devices_Manual_guide/node01A3.html) 
```
Additional programming information on the disk resource can be found in
the include files and the Autodocs for the disk resource.


```c
                       Disk Resource Information
                    --------------------------------
                    INCLUDES        resources/[disk.h](../Includes_and_Autodocs_2._guide/node0119.html)
                                    resources/[disk.i](../Includes_and_Autodocs_2._guide/node011B.html)

                    AUTODOCS        [disk.doc](../Includes_and_Autodocs_2._guide/node0545.html)
```
