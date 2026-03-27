---
title: 32 / / RigidDiskBlock and Alternate Filesystems / filesysres.h and .i
manual: libraries
chapter: libraries
section: 32-rigiddiskblock-and-alternate-filesystems-filesysres-h
functions: [CachePostDMA, CachePreDMA, Forbid]
libraries: [exec.library]
---

# 32 / / RigidDiskBlock and Alternate Filesystems / filesysres.h and .i

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FileSysResource is created by the first code that needs to use it.  It
is added to the resource list for others to use. (Checking and creation
should be performed while [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md) is in effect).  Under Release 2 the
resource is created by the system early on in the initialization sequence.
Under 1.3 it is the responsibility of the first RDB driver to create it.


 FileSysResource

   fsr_Node              on resource list with the name FileSystem.resource
   fsr_Creator           name of creator of this resource
   fsr_FileSysEntries    list of FileSysEntry structs


 FileSysEntry

   fse_Node              on fsr_FileSysEntries list
                         ln_Name is of creator of this entry
   fse_DosType           DosType of this FileSys
   fse_Version           release version of this FileSys

                         Usually MSW is version, LSW is revision.
   fse_PatchFlags        bits set for those of the following that

                         need to be substituted into a standard
                         device node for this file system: e.g.
                         $180 for substitute SegList & GlobalVec
   fse_Type              device node type: zero
   fse_Task              standard dos "task" field
   fse_Lock              not used for devices: zero
   fse_Handler           filename to loadseg (if SegList is null)
   fse_StackSize         stacksize to use when starting task
   fse_Priority          task priority when starting task
   fse_Startup           startup msg: FileSysStartupMsg for disks
   fse_SegList           segment of code to run to start new task
   fse_GlobalVec         BCPL global vector when starting task

   No more entries need exist than those implied by fse_PatchFlags, so
   entries do not have a fixed size.


For additional information on initializing and booting a Rigid Disk Block
filesystem device, see the [SCSI Device](devices/11-scsi-device.md) chapter of the Addison-Wesley Amiga
ROM Kernel Reference Manual: Devices. Writers of drivers for expansion
devices that perform their own DMA (direct memory access) should consult
the [Exec chapters](libraries/exec-library.md) and Autodocs for information on Release 2 processor
cache control functions including [CachePreDMA()](autodocs-2.0/exec-library-cachepredma.md) and [CachePostDMA()](autodocs-2.0/exec-library-cachepostdma.md). See
the following include files for additional notes and related structures:
<libraries/[configvers.h](autodocs-2.0/includes-libraries-configvars-h.md)> and <[.i](autodocs-2.0/includes-libraries-configvars-i.md)>, <libraries/[configregs.h](autodocs-2.0/includes-libraries-configregs-h.md)> and <[.i](autodocs-2.0/includes-libraries-configregs-i.md)>,
<devices/[hardblocks.h](autodocs-2.0/includes-devices-hardblocks-h.md)> and <[.i](autodocs-2.0/includes-devices-hardblocks-i.md)>, <resources/[filesysres.h](autodocs-2.0/includes-resources-filesysres-h.md)> and <[.i](autodocs-2.0/includes-resources-filesysres-i.md)>, and
<libraries/[filehandler.h](autodocs-2.0/includes-libraries-filehandler-h.md)> and <[.i](autodocs-2.0/includes-libraries-filehandler-i.md)>.

---

## See Also

- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
