---
title: 11 / RigidDiskBlock - Fields and Implementation / Alien Filing Systems
manual: devices
chapter: devices
section: 11-rigiddiskblock-fields-and-implementation-alien-filing
functions: [AddResource, LoadSeg]
libraries: [dos.library, exec.library]
---

# 11 / RigidDiskBlock - Fields and Implementation / Alien Filing Systems

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a filing system other than the ROM filing system is to be used, the
following steps take place.

   1. First, open filesystem.resource in preparation for finding the

```c
      filesystem segment we want.  If filesystem.resource doesn't exist
      then create it and add it via [AddResource()](autodocs-2.0/exec-library-addresource.md).  Under 2.0 the resource
      is created by the system early on in the initialization sequence.
      Under pre-V36 Kickstart, it is the responsibility of the first RDB
      driver to create it.
```
   2. Scan filesystem.resource looking for a filesystem that matches the

      DosType and version that we want.  If it exists go to step 4.
   3. Since the driver couldn't find the filesystem it needed, it will have

```c
      to load it from the RDB area.  The list of [FileSysHeaderBlocks](devices/11-scsi-device-rigiddiskblock-fields-and-implementation.md)
      (pointed to by the "RDSK" block) is scanned for a filesystem of the
      required DosType and version.  If none is found then the driver will
      give up and abort the mounting of the partition.  If the required
      filesystem is found, then it is [LoadSeg()](autodocs-2.0/dos-library-loadseg.md)'ed from the "LSEG" blocks
      and added as a new entry to the filesystem.resource.
```
   4. The SegList pointer of the found or loaded filesystem is held in the

```c
      [FileSysEntry](autodocs-2.0/includes-resources-filesysres-h.md) structure (which is basically an environment vector for
      this filing system).  Using the patch flags, the driver now patches
      the newly created environment vector (pointed to by the new DosNode)
      using the values in the FileSysEntry being used.  This ensures that
      the partition will have the correct filing system set up with the
      correct mount variables using a shared SegList.
```
The eb_Mountlist will now be set up with prioritized bootnodes and maybe
some non-bootable, but mounted partitions.  The system bootstrap will now
take over.

---

## See Also

- [AddResource — exec.library](../autodocs/exec.library.md#addresource)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
