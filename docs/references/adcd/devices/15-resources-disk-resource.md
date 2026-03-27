---
title: 15 Resources / Disk Resource
manual: devices
chapter: devices
section: 15-resources-disk-resource
functions: []
libraries: []
---

# 15 Resources / Disk Resource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Disk resource obtains exclusive access to the floppy disk hardware
There are four disk/MFM units available, units 0-3.

Six functions are available for dealing with the floppy disk hardware.


```c
                      Disk Resource Functions
                      -----------------------
     [AllocUnit()](autodocs-2.0/disk-resource-allocunit.md)      Allocate one of the units of the disk
                      resource.

     [FreeUnit()](autodocs-2.0/disk-resource-freeunit.md)       Deallocate an allocated disk unit.

     [GetUnit()](autodocs-2.0/disk-resource-getunit.md)        Allocate the disk for a driver.

     [GetUnitID()](autodocs-2.0/disk-resource-getunitid.md)      Return the drive ID of a specified drive
                      unit.

     [GiveUnit()](autodocs-2.0/disk-resource-giveunit.md)       Free the disk.

     [ReadUnitID()](autodocs-2.0/disk-resource-readunitid.md)     Reread and return the drive ID of a
                      specified unit.
```
The disk resource provides both a gross and a fine unit allocation scheme.
[AllocUnit()](autodocs-2.0/disk-resource-allocunit.md) and [FreeUnit()](autodocs-2.0/disk-resource-freeunit.md) are used to claim a unit for long term use, and
[GetUnit()](autodocs-2.0/disk-resource-getunit.md) and [GiveUnit()](autodocs-2.0/disk-resource-giveunit.md) are used to claim a unit and the disk hardware
for shorter periods.

The trackdisk device uses and abides by both allocation schemes.  Because
a trackdisk unit is never closed for Amiga 3.5" drives (the file system
keeps them open) the associated resource units will always be allocated
for these drives.  [GetUnit()](autodocs-2.0/disk-resource-getunit.md) and [GiveUnit()](autodocs-2.0/disk-resource-giveunit.md) can still be used, however, by
other applications that have not succeeded with [AllocUnit()](autodocs-2.0/disk-resource-allocunit.md).

You must not change the state of of a disk that the trackdisk device is
using unless you either

   a) force its removal before giving it up, or

   b) return it to the original track (with no changes to the track), or

   c) CMD_STOP the unit before [GetUnit()](autodocs-2.0/disk-resource-getunit.md), update the current track number

```c
      and CMD_START it after [GiveUnit()](autodocs-2.0/disk-resource-giveunit.md).  This option is only available
      under V36 and higher versions of the operating system.
```
[ReadUnitID()](autodocs-2.0/disk-resource-readunitid.md) is provided to handle drives which use the unit number in a
dynamic manner.  Subsequent [GetUnit()](autodocs-2.0/disk-resource-getunit.md) calls will return the value obtained
by ReadUnitID().

It is therefore possible to prevent the trackdisk device from using units
that have not yet been mounted by successfully performing an [AllocUnit()](autodocs-2.0/disk-resource-allocunit.md)
for that unit.  It is also possible to starve trackdisk usage by
performing a [GetUnit()](autodocs-2.0/disk-resource-getunit.md). The appropriate companion routine ([FreeUnit()](autodocs-2.0/disk-resource-freeunit.md) or
[GiveUnit()](autodocs-2.0/disk-resource-giveunit.md)) should be called to restore the resource at the end of its use.


```c
     [Get_Disk_Unit_ID.c](devices/devices-dev-examples-get-disk-unit-id-c.md) 
```
Additional programming information on the disk resource can be found in
the include files and the Autodocs for the disk resource.


```c
                       Disk Resource Information
                    --------------------------------
                    INCLUDES        resources/[disk.h](autodocs-2.0/includes-resources-disk-h.md)
                                    resources/[disk.i](autodocs-2.0/includes-resources-disk-i.md)

                    AUTODOCS        [disk.doc](autodocs-2.0/disk-doc.md)
```
