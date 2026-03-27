---
title: 32 / / RigidDiskBlock and Alternate Filesystems / LoadSegBlock
manual: libraries
chapter: libraries
section: 32-rigiddiskblock-and-alternate-filesystems-loadsegblock
functions: []
libraries: []
---

# 32 / / RigidDiskBlock and Alternate Filesystems / LoadSegBlock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the current specification of the LoadSegBlock. The end of data
occurs when lsb_Next is NULL ($FFFFFFFF), and the summed data is exhausted.


   lsb_ID                  == 'LSEG'

   lsb_SummedLongs         size of this checksummed structure

```c
                           Note that this is not 64 like most of the other
                           structures.  This is the number of valid longs
                           in this image, like [bbb_SummedLongs](libraries/32-rigiddiskblock-and-alternate-filesystems-badblockblock.md).
```
   lsb_ChkSum              block checksum (longword sum to zero)

   lsb_HostID              SCSI Target ID of host

```c
                           This describes the initiator ID for the creator
                           of these blocks.  (see [rdb_HostID](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md) discussion)
```
   lsb_Next                block number of the next LoadSegBlock

   lsb_LoadData            data for "loadseg"

```c
                           The data starts here and continues as long
                           as indicated by lsb_SummedLongs-5: e.g. if
                           lsb_SummedLongs is 128 (ie. for 512 byte
                           blocks), 123 longs of data are valid here.
```
