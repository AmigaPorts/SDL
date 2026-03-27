---
title: 32 / / RigidDiskBlock and Alternate Filesystems / PartitionBlock
manual: libraries
chapter: libraries
section: 32-rigiddiskblock-and-alternate-filesystems-partitionblock
functions: [AllocMem]
libraries: [exec.library]
---

# 32 / / RigidDiskBlock and Alternate Filesystems / PartitionBlock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the current specification for the PartitionBlock. Note that while
reading these blocks you may encounter partitions that are not to be
mounted because the pb_HostID does not match, or because the pb_DriveName
is in use and no fallback strategy exists, or because PBF._NOMOUNT is set,
or because the proper filesystem cannot be found.  Some partitions may be
mounted but not be bootable because PBF._BOOTABLE is not set.


   pb_ID                   == 'PART'
   pb_SummedLongs          == 64
   pb_ChkSum               block checksum (longword sum to zero)

   pb_HostID               SCSI Target ID of host

```c
                           This describes the initiator ID for the owner
                           of this partition.  (see [rdb_HostID](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) discussion)
```
   pb_Next                 block number of the next PartitionBlock

   pb_Flags                see below for defines

```c
       PBF._BOOTABLE       this partition is intended to be bootable
                           (e.g. expected directories and files exist)

       PBF._NOMOUNT        this partition description is to reserve
                           space on the disk without mounting it.
                           It may be manually mounted later.
```
   pb_Reserved1[2]         set to zeros

   pb_DevFlags             preferred flags for OpenDevice
   pb_DriveName            preferred DOS device name: BSTR form


                           This name is not to be used if it is already
                           in use.
Note that pb_Reserved2 will always be at least 4 longwords so that the RAM
image of this record may be converted to the parameter packet to the
expansion.library function [MakeDosNode()](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md).


   pb_Reserved2[15]        filler to make 32 longwords so far


The specification of the location of the partition is one of the
components of the environment, below.  If possible, describe the partition
in a manner that tells the DOS about the physical layout of the partition:
specifically, where the cylinder boundaries are.  This allows the
filesystem's smart block allocation strategy to work.


   pb_Environment[17]      environment vector for this partition

```c
                           containing:

       de_TableSize        size of Environment vector
       de_SizeBlock        == 128 (for 512 bytes/logical block)
       de_SecOrg           == 0
       de_Surfaces         number of heads (see [layout discussion](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md))
       de_SectorPerBlock   == 1
       de_BlocksPerTrack   blocks per track (see [layout discussion](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md))

       de_Reserved         DOS reserved blocks at start of partition.
                           Must be >= 1.  2 is recommended.

       de_PreAlloc         DOS reserved blocks at end of partition
                           Valid only for filesystem type DOS^A (the
                           fast file system).  Zero otherwise.

       de_Interleave       DOS interleave
                           Valid only for filesystem type DOS^@ (the
                           old file system).  Zero otherwise.

       de_LowCyl           starting cylinder
       de_HighCyl          max cylinder
       de_NumBuffers       initial # DOS of buffers.

       de_BufMemType       type of mem to allocate for buffers
                           The second argument to AllocMem().

       de_MaxTransfer      max number of bytes to transfer at a time.
                           Drivers should be written to handle requests
                           of any length.

       de_Mask             address mask to block out certain memory
                           Normally $00ffffff  for DMA devices.

       de_BootPri          Boot priority for [autoboot](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md)
                           Suggested value: zero.  Keep less than
                           five, so it won't override a boot floppy.

       de_DosType          ASCII string showing filesystem type;
                           DOS^@ ($444F5300) is old filesystem,
                           DOS^A ($444F5301) is fast file system.
                           UNI<anything> is a Unix partition.
```
   pb_EReserved[15]        reserved for future environment vector

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
