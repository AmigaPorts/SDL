---
title: 32 / / RigidDiskBlock and Alternate Filesystems / RigidDiskBlock
manual: libraries
chapter: libraries
section: 32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock
functions: []
libraries: []
---

# 32 / / RigidDiskBlock and Alternate Filesystems / RigidDiskBlock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the current specification for the RigidDiskBlock:


   rdb_ID              == 'RDSK'
   rdb_SummedLongs     == 64

   rdb_ChkSum          block checksum (longword sum to zero)

   rdb_HostID          SCSI Target ID of host

```c
                       This is the initiator ID of the creator of this
                       RigidDiskBlock.  It is intended that
                       modification of the RigidDiskBlock, or of any
                       of the blocks pointed to by it, by another
                       initiator (other than the one specified here)
                       be allowed only after a suitable warning.  The
                       user is then expected to perform an audio
                       lock out ("Hey, is anyone else setting up SCSI
                       stuff on this bus?").  The rdb_HostID may
                       become something other than the initiator ID
                       when connected to a real network: that is an
                       area for future standardization.
```
   rdb_BlockBytes      size of disk blocks

                       Under pre-V36 filesystem, this must be 512 for
                       a disk with any AmigaDOS partitions on it.
                       Present filesystem supports 256, 512, 1024, etc.
   rdb_Flags           longword of flags:



```c
       RDBF._LAST          no disks exist to be configured after this
                           one on this controller (SCSI bus).

       RDBF._LASTLUN       no LUNs exist to be configured greater
                           than this one at this SCSI Target ID

       RDBF._LASTTID       no Target IDs exist to be configured
                           greater than this one on this SCSI bus

       RDBF._NORESELECT    don't bother trying to perform reselection
                           when talking to this drive

       RDBF._DISKID        rdb_Disk... identification variables below
                           contain valid data.

       RDBF._CTRLRID       rdb_Controller... identification variables
                           below contain valid data.

       RDBF._SYNCH         drive supports scsi synchronous mode
                           CAN BE DANGEROUS TO USE IF IT DOESN'T!
```
These fields point to other blocks on the disk which are not a part of any
filesystem.  All block pointers referred to are block numbers on the drive.


   rdb_BadBlockList        optional bad block list

```c
                           A singly linked list of blocks of type
                           [PartitionBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md)
```
   rdb_PartitionList       optional first partition block

```c
                           A singly linked list of blocks of type
                           [PartitionBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md)
```
   rdb_FileSysHeaderList   optional file system header block

```c
                           A singly linked list of blocks of type
                           [FileSysHeaderBlock](libraries/32-rigiddiskblock-and-alternate-filesystems.md)
```
   rdb_DriveInit           optional drive-specific init code

```c
                           A singly linked list of blocks of type
                           [LoadSegBlock](libraries/32-rigiddiskblock-and-alternate-filesystems-loadsegblock.md) containing initialization code.
                           Called as DriveInit(lun,rdb,ior)(d0/a0/a1).
```
   rdb_Reserved1[6]        set to $ffffffffs


                           These are reserved for future block lists.
                           Since NULL for block lists is $ffffffff, these
                           reserved entries must be set to $ffffffff.
These fields describe the physical layout of the drive.


   rdb_Cylinders           number of drive cylinders
   rdb_Sectors             sectors per track
   rdb_Heads               number of drive heads

   rdb_Interleave          interleave

                           This drive interleave is independent from, and
                           unknown to, the DOS's understanding of
                           interleave as set in the partition's
                           environment vector.
   rdb_Park                landing zone cylinder
   rdb_Reserved2[3]        set to zeros


These fields are intended for ST506 disks.  They are generally unused for
SCSI devices and set to zero.


   rdb_WritePreComp        starting cylinder: write precompensation
   rdb_ReducedWrite        starting cylinder: reduced write current
   rdb_StepRate            drive step rate
   rdb_Reserved3[5]        set to zeros


These fields are used while partitions are set up to constrain the
partitionable area and help describe the relationship between the drive's
logical and physical layout.


   rdb_RDBlocksLo          low block of the range allocated for

                           blocks described here.  Replacement blocks
                           for bad blocks may also live in this range.
   rdb_RDBlocksHi          high block of this range (inclusive)

   rdb_LoCylinder          low cylinder of partitionable disk area

                           Blocks described by this include file will
                           generally be found in cylinders below this one.
   rdb_HiCylinder          high cylinder of partitionable data area

                           Usually rdb_Cylinders-1.
   rdb_CylBlocks           number of blocks available per cylinder

                           This may be rdb_Sectors*rdb_Heads, but a SCSI
                           disk that, for example, reserves one block per
                           cylinder for  bad block mapping would use
                           rdb_Sectors*rdb_Heads-1.
   rdb_AutoParkSeconds     number of seconds to wait before parking

                           drive heads automatically.  If zero, this
                           feature is not desired.
   rdb_HighRDSKBlock       highest block used by these drive definitions

```c
                           Must be less than or equal to rdb_RDBBlocksHi.
                           All replacements for bad blocks should be
                           between rdb_HighRDSKBlock+1 and rdb_RDBBlocksHi
                           (inclusive).
```
   rdb_Reserved4           set to zeros


These fields are of the form available from a SCSI Identify command.
Their purpose is to help the user identify the disk during setup.  Entries
exist for both controller and disk for non-embedded SCSI disks.


   rdb_DiskVendor          vendor name of the disk
   rdb_DiskProduct         product name of the disk
   rdb_DiskRevision        revision code of the disk
   rdb_ControllerVendor    vendor name of the disk controller
   rdb_ControllerProduct   product name of the disk controller
   rdb_ControllerRevision  revision code of the disk controller
   rdb_Reserved5[10]       set to zeros

