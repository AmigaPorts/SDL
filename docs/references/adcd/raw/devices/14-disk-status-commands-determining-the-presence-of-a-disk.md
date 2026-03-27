# 14 / Disk Status Commands / Determining The Presence Of A Disk


You determine the presence of a disk in a drive by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to
the device with [TD_CHANGESTATE](../Includes_and_Autodocs_2._guide/node0525.html) set in io_Command.  For quick I/O, you must
set io_Flags to IOF_QUICK.

   DiskIO->iotd_Req.io_Flags = IOF_QUICK;
   DiskIO->iotd_Req.io_Command = TD_CHANGESTATE;
   BeginIO((struct IORequest *)DiskIO);

[TD_CHANGESTATE](../Includes_and_Autodocs_2._guide/node0525.html) returns the presence indicator of a disk in io_Actual. The
value returned will be zero if a disk is currently in the drive and
nonzero if the drive has no disk.

