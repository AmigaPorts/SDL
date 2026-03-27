# 14 / Disk Status Commands / Determining The Drive Type


You determine the drive type of a unit by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device
with [TD_GETDRIVETYPE](../Includes_and_Autodocs_2._guide/node0528.html) set in io_Command.  For quick I/O, you must set
io_Flags to IOF_QUICK.

   DiskIO->iotd_Req.io_Flags = IOF_QUICK;
   DiskIO->iotd_Req.io_Command = TD_GETDRIVETYPE;
   BeginIO((struct IORequest *)DiskIO);

[TD_GETDRIVETYPE](../Includes_and_Autodocs_2._guide/node0528.html) returns the drive type for the unit that was opened in
io_Actual. The value will be DRIVE3_5 for 3.5" drives and DRIVE5_25 for
5.25" drives.  The unit can be opened only if the device understands the
drive type it is connected to.

