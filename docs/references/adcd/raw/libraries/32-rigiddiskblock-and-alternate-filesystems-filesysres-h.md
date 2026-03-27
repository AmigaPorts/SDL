# 32 / / RigidDiskBlock and Alternate Filesystems / filesysres.h and .i


The FileSysResource is created by the first code that needs to use it.  It
is added to the resource list for others to use. (Checking and creation
should be performed while [Forbid()](../Libraries_Manual_guide/node02C2.html#line9) is in effect).  Under Release 2 the
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
filesystem device, see the [SCSI Device](../Devices_Manual_guide/node0073.html) chapter of the Addison-Wesley Amiga
ROM Kernel Reference Manual: Devices. Writers of drivers for expansion
devices that perform their own DMA (direct memory access) should consult
the [Exec chapters](../Libraries_Manual_guide/node0003.html) and Autodocs for information on Release 2 processor
cache control functions including [CachePreDMA()](../Includes_and_Autodocs_2._guide/node033C.html) and [CachePostDMA()](../Includes_and_Autodocs_2._guide/node033B.html). See
the following include files for additional notes and related structures:
<libraries/[configvers.h](../Includes_and_Autodocs_2._guide/node00FC.html)> and <[.i](../Includes_and_Autodocs_2._guide/node00FF.html)>, <libraries/[configregs.h](../Includes_and_Autodocs_2._guide/node00F6.html)> and <[.i](../Includes_and_Autodocs_2._guide/node00F9.html)>,
<devices/[hardblocks.h](../Includes_and_Autodocs_2._guide/node0041.html)> and <[.i](../Includes_and_Autodocs_2._guide/node0045.html)>, <resources/[filesysres.h](../Includes_and_Autodocs_2._guide/node011D.html)> and <[.i](../Includes_and_Autodocs_2._guide/node011F.html)>, and
<libraries/[filehandler.h](../Includes_and_Autodocs_2._guide/node0100.html)> and <[.i](../Includes_and_Autodocs_2._guide/node0103.html)>.

