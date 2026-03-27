---
title: 11 / RigidDiskBlock-Fields and Implementation / How A Driver Uses RDB
manual: devices
chapter: devices
section: 11-rigiddiskblock-fields-and-implementation-how-a-driver
functions: []
libraries: []
---

# 11 / RigidDiskBlock-Fields and Implementation / How A Driver Uses RDB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The information contained in the [RigidDiskBlock](devices/11-scsi-device-rigiddiskblock-fields-and-implementation.md) and subsequent
[PartitionBlocks](devices/11-scsi-device-rigiddiskblock-fields-and-implementation.md), et al., is used by a driver in the following manner.

After determining that the target device is a hard disk (using the
SCSI-direct command INQUIRY), the driver will scan the first
RDB_LOCATION_LIMIT (16) blocks looking for a block with the "RDSK"
identifier and a correct sum-to-zero checksum.  If no RDB is found then
the driver will give up and not attempt to mount any partitions for this
unit.  If the RDB is found then the driver looks to see if there's a
partition list for this unit (rdb_PartitionList). If none, then just the
rdb_Flags will be used to determine if there are any LUNs or units after
this one.  This is used for early termination of the search for units on
bootup.

If a partition list is present, and the partition blocks have the correct
ID and checksum, then for each partition block the driver does the
following.

   1. Checks the PBFB_NOMOUNT flag.  If set then this partition is just

      reserving space.  Skip to the next partition without mounting the
      current one.
   2. If PBFB_NOMOUNT is false, then the partition is to be mounted.  The

```c
      driver fetches the given drive name from pb_DriveName.  This name
      will be of the form dh0, work, wb_2.x etc.  A check is made to see if
      this name already exists on eb_MountList or DOS's device list. If it
      does, then the name is algorithmically altered to remove duplicates.
      The A590, A2091 and A3000 append .n (where n is a number) unless
      another name ending with .n is found.  In that case the name is
      changed to .n+1 and the search for duplicates is retried.
```
   3. Next the driver constructs a parameter packet for [MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md) using

```c
      the (possibly altered) drive name and information about the Exec
      device name and unit number.  MakeDosNode() is called to create a DOS
      device node.  MakeDosNode() constructs a filesystem startup message
      from the given information and fills in defaults for the ROM filing
      system.
```
   4. If [MakeDosNode()](autodocs-2.0/expansion-library-makedosnode.md) succeeds then the driver checks to see if the entry

```c
      is using a standard ("DOS\0") filing system.  If not then the
      routine for patching in non-standard filing systems is called (see
      "[Alien File Systems](devices/11-rigiddiskblock-fields-and-implementation-alien-filing.md)" below).
```
   5. Now that the DOS node has been set up and the correct filing system

```c
      segment has been associated with it, the driver checks PBFB_BOOTABLE
      to see if this partition is marked as bootable.  If the partition is
      not bootable, or this is not autoboot time (DiagArea == 0) then the
      driver simply calls [AddDosNode()](autodocs-2.0/expansion-library-adddosnode.md) to enqueue the DOS device node.  If
      the partition is bootable, then the driver constructs a boot node and
      enqueues it on eb_MountList using the boot priority from the
      environment vector.  If this boot priority is -128 then the partition
      is not considered bootable.
```
