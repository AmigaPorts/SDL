# 14 / / Removing A Diskchange Software Interrupt Handler


You remove a software interrupt handler by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the
device with a pointer to an Interrupt structure set in io_Data, the length
of the structure set in io_Length and [TD_REMCHANGEINT](../Includes_and_Autodocs_2._guide/node052F.html) set in io_Command.
You must pass it the same Interrupt structure used to add the handler.


```c
    DiskIO->iotd_Req.io_Length = sizeof(struct Interrupt)
    DiskIO->iotd_Req.io_Data   = (APTR)Disk_Interrupt;
    DiskIO->iotd_Req.io_Command = TD_REMCHANGEINT;
    DoIO((struct IORequest *)DiskIO);
```
   Don't use with pre-V36 and earlier versions.
   --------------------------------------------
   Under pre-V36 and earlier versions of the Amiga system software,
   [TD_REMCHANGEINT](../Includes_and_Autodocs_2._guide/node052F.html) does not work and should not be used.  Instead, use
   the workaround listed in the "trackdisk.doc" of the Amiga ROM
   Kernel Reference Manual: Includes and Autodocs.

