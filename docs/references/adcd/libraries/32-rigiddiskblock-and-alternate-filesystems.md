---
title: 32 / / RigidDiskBlock and Alternate Filesystems / FileSysHeaderBlock
manual: libraries
chapter: libraries
section: 32-rigiddiskblock-and-alternate-filesystems
functions: []
libraries: []
---

# 32 / / RigidDiskBlock and Alternate Filesystems / FileSysHeaderBlock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The current specification for the FileSysHeaderBlock follows.


   fhb_ID                  == 'FSHD'
   fhb_SummedLongs         == 64
   fhb_ChkSum              block checksum (longword sum to zero)

   fhb_HostID              SCSI Target ID of host

```c
                           This describes the initiator ID for the
                           creator of this block.  (see [rdb_HostID](libraries/32-rigiddiskblock-and-alternate-filesystems-rigiddiskblock.md)
                           discussion)
```
   fhb_Next                block number of next FileSysHeaderBlock
   fhb_Flags               see below for defines
   fhb_Reserved1[2]        set to zero


The following information is used to construct a FileSysEntry node in the
FileSystem.resource.


   fhb_DosType             file system description

```c
                           This is matched with a partition environment's
                           [de_DosType](libraries/32-rigiddiskblock-and-alternate-filesystems-partitionblock.md) entry.
```
   fhb_Version             release version of this load image

                           Usually MSW is version, LSW is revision.
   fhb_PatchFlags          patch flags

                           These are bits set for those of the following
                           that need to be substituted into a standard
                           device node for this file system, lsb first:
                           e.g. 0x180 to substitute SegList & GlobalVec
   fhb_Type                device node type: zero
   fhb_Task                standard dos "task" field: zero
   fhb_Lock                not used for devices: zero
   fhb_Handler             filename to loadseg: zero placeholder
   fhb_StackSize           stacksize to use when starting task
   fhb_Priority            task priority when starting task
   fhb_Startup             startup msg: zero placeholder

   fhb_SegListBlocks       first of linked list of [LoadSegBlocks](libraries/32-rigiddiskblock-and-alternate-filesystems-loadsegblock.md):

```c
                           Note that if the fhb_PatchFlags bit for this
                           entry is set (bit 7), the blocks pointed to by
                           this entry must be LoadSeg'd and the resulting
                           BPTR put in the FileSysEntry node.
```
   fhb_GlobalVec           BCPL global vector when starting task

                           Zero or -1.
   fhb_Reserved2[23]       (those reserved by PatchFlags)
   fhb_Reserved3[21]       set to zero

