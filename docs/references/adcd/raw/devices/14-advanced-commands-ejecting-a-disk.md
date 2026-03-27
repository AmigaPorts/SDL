# 14 / Advanced Commands / Ejecting A Disk


Certain disk drive manufacturers allow software control of disk ejection.
The trackdisk device provides the [TD_EJECT](../Includes_and_Autodocs_2._guide/node0526.html) command to tell such drives to
eject a disk.

You eject a disk by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device with [TD_EJECT](../Includes_and_Autodocs_2._guide/node0526.html) set in
io_Command.

   DiskIO->iotd_Req.io_Command = TD_EJECT;
   DoIO((struct IORequest *)DiskIO);

   Read the Instruction Manual.
   ----------------------------
   The Commodore 3.5" drives for the Amiga and most other Amiga drive
   manufacturers do not support software disk ejects.  Attempting this
   command on those drives will result in an error condition.  Consult
   the instruction manual for your disk drive to determine whether this
   is supported.

