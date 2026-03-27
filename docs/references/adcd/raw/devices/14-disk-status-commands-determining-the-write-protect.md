# 14 / Disk Status Commands / Determining The Write-Protect Status Of A Disk


You determine the write-protect status of a disk by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to
the device with [TD_PROTSTATUS](../Includes_and_Autodocs_2._guide/node052C.html) set in io_Command.  For quick I/O, you must
set io_Flags to IOF_QUICK.

   DiskIO->iotd_Req.io_Flags = IOF_QUICK;
   DiskIO->iotd_Req.io_Command = TD_PROTSTATUS;
   BeginIO((struct IORequest *)DiskIO);

[TD_PROTSTATUS](../Includes_and_Autodocs_2._guide/node052C.html) returns the write-protect status in io_Actual. The value
will be zero if the disk is not write-protected and nonzero if the disk is
write-protected.

