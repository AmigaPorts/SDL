---
title: 32 / / RigidDiskBlock and Alternate Filesystems / BadBlockBlock
manual: libraries
chapter: libraries
section: 32-rigiddiskblock-and-alternate-filesystems-badblockblock
functions: []
libraries: []
---

# 32 / / RigidDiskBlock and Alternate Filesystems / BadBlockBlock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the current specification for the BadBlockBlock. The end of data
occurs when bbb_Next is NULL ($FFFFFFFF), and the summed data is exhausted.


   bbb_ID                  == 'BADB'

   bbb_SummedLongs         size of this checksummed structure

```c
                           Note that this is not 64 like most of the other
                           structures.  This is the number of valid longs
                           in this image, and can be from 6 to
                           [rdb_BlockBytes](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md)/4.  The latter is the best size
                           for all blocks other than the last one.
```
   bbb_ChkSum              block checksum (longword sum to zero)

   bbb_HostID              SCSI Target ID of host

```c
                           This describes the initiator ID for the creator
                           of these blocks.  (see [rdb_HostID](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) discussion)
```
   bbb_Next                block number of the next BadBlockBlock
   bbb_Reserved            set to zeros

   bbb_BlockPairs[61]      pairs of block remapping information

```c
                           The data starts here and continues as long as
                           indicated by bbb_SummedLongs-6: e.g. if
                           bbb_SummedLongs is 128 (512 bytes), 61 pairs
                           are described here.
```
