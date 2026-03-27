# 14 / / Adding A Diskchange Software Interrupt Handler


The trackdisk device lets you add a software interrupt handler that will
be Cause()'ed when a disk insert or remove occurs.   Within the handler,
you may only call the status commands that can use IOF_QUICK.

You add a software interrupt handler by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device
with a pointer to an Interrupt structure set in io_Data, the length of the
structure set in io_Length and [TD_ADDCHANGEINT](../Includes_and_Autodocs_2._guide/node0523.html) set in io_Command.

   DiskIO->iotd_Req.io_Length = sizeof(struct Interrupt)
   DiskIO->iotd_Req.io_Data   = (APTR)Disk_Interrupt;
   DiskIO->iotd_Req.io_Command = TD_ADDCHANGEINT;
   SendIO((struct IORequest *)DiskIO);

   Going, going, gone.
   -------------------
   This command does not return when executed. It holds onto the
   IORequest until the [TD_REMCHANGEINT](../Includes_and_Autodocs_2._guide/node052F.html) command is executed with that
   same IORequest.  Hence, you must use SendIO() with this command.

