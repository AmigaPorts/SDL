---
title: 32 / Expansion Board Drivers / RigidDiskBlock and Alternate Filesystems
manual: libraries
chapter: libraries
section: 32-expansion-board-drivers-rigiddiskblock-and-alternate
functions: [DoIO]
libraries: [exec.library]
---

# 32 / Expansion Board Drivers / RigidDiskBlock and Alternate Filesystems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Through the use of [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) information and the FileSys.resource, it
is possible for an [autoboot](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md) driver to have access to enough information to
mount all of its device partitions and even load alternate filesystems for
use with these partitions.

The [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) specification (also known as "hardblocks") defines
blocks of data that exist on a hard disk to describe that disk.  These
blocks are created or modified with an installation utility (such as the
hard drive Prep utility for the A2090A ST506/SCSI controller card)
provided by the disk controller manufacturer, and they are read and used
by the device driver ROM (or expansion) code.  They are not generally
accessible to the user as they do not appear on any DOS device.  The
blocks are tagged with a unique identifier, checksummed, and linked
together.

The five block types currently defined are [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md), [BadBlockBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-badblockblock.md),
[PartitionBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md), [FileSysHeaderBlock](libraries/32-rigiddiskblock-and-alternate-filesystems.md), and [LoadSegBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-loadsegblock.md).

The root of these blocks is the [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md).  The RigidDiskBlock must
exist on the disk within the first RDB_LOCATION_LIMIT (16) blocks.  This
inhibits the use of the first cylinder(s) in an AmigaDOS partition:
although it is strictly possible to store the RigidDiskBlock data in the
reserved area of a partition, this practice is discouraged since the
reserved blocks of a partition are overwritten by Format, Install,
DiskCopy, etc.  The recommended disk layout, then, is to use the first
cylinder(s) to store all the drive data specified by these blocks: i.e.
partition descriptions, file system load images, drive bad block maps,
spare blocks, etc.  This allocation range is described in the
RigidDiskBlock.

The [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) contains basic information about the configuration of
the drive: number and size of blocks, tracks, and cylinders, as well as
other relevant information.  The RigidDiskBlock points to bad block,
partition, file system and drive initialization description blocks.

The [BadBlockBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-badblockblock.md) list contains a series of bad-block/good-block pairs.
Each block contains as many as will fit in a physical sector on the drive.
These mappings are to be handled by the driver on read and write requests.

The drive initialization description blocks are [LoadSegBlocks](libraries/32-rigiddiskblock-and-alternate-filesystems-loadsegblock.md) that are
loaded at boot time to perform drive-specific initialization.  They are
called with both C-style parameters on the stack, and assembler parameters
in registers as follows:


```c
      d0  =  DriveInit(lun, rdb, ior)(d0/a0/a1)
```
where lun is the SCSI logical unit number (needed to construct SCSI
commands), rdb is a pointer to a memory copy of the [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) (which
should not be altered), and ior is a standard IO request block that can be
used to access the drive with synchronous DoIO() calls.

The result of DriveInit() is either -1, 0, or 1.  A -1 signifies that an
error occurred and drive initialization cannot continue.  A 0 (zero)
result reports success. In cases -1 and 0, the code is unloaded.  A result
of 1 reports success, and causes the code to be kept loaded.  Furthermore,
this resident code will be called whenever a reset is detected on the SCSI
bus.

The [FileSysHeaderBlock](libraries/32-rigiddiskblock-and-alternate-filesystems.md) entries contain code for alternate file handlers to
be used by partitions.  There are several strategies that can be used to
determine which of them to load. The most robust would scan all drives for
those that are both required by partitions and have the highest
[fhb_Version](libraries/32-rigiddiskblock-and-alternate-filesystems.md), and load those. Whatever method is used, the loaded file
handlers are added to the Exec resource FileSystem.resource, where they
are used as needed to mount disk partitions.

The [PartitionBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md) entries contains most of the data necessary to add each
partition to the system.  They replace the Mount and DEVS:MountList
mechanism for adding these partitions. The only items required by the
expansion.library [MakeDosNode()](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md) function which are not in this partition
block are the Exec device name and unit, which is expected to be known by
driver reading this information.  The file system to be used is specified
in the [pb_Environment](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md).  If it is not the default file system (i.e.,
'DOS\\0' or 'DOS\\1'), the node created by [MakeDosNode()](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md) is modified as
specified in a FileSystem.resource's FileSysEntry before adding it to the
DOS list.

Only 512 byte blocks were supported by the pre-V36 file system, but this
proposal was forward-looking by making the block size explicit, and by
using only the first 256 bytes for all blocks but the LoadSeg and BadBlock
data.  Under the present filesystem, this allows using drives formatted
with sectors 256 bytes or larger (i.e., 256, 512, 1024, etc).  LoadSeg and
BadBlock data use whatever space is available in a sector.

 [RigidDiskBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md)    [PartitionBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md)        [LoadSegBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-loadsegblock.md) 
 [BadBlockBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-badblockblock.md)     [FileSysHeaderBlock](libraries/32-rigiddiskblock-and-alternate-filesystems.md)    [filesysres.h and .i](libraries/32-rigiddiskblock-and-alternate-filesystems-filesysres-h.md) 

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
