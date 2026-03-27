# 14 / Advanced Commands / Clearing The Track Buffer


ETD_CLEAR and [CMD_CLEAR](../Includes_and_Autodocs_2._guide/node051F.html) mark the track buffer as invalid, forcing a reread
of the disk on the next operation. ETD_UPDATE or [CMD_UPDATE](../Includes_and_Autodocs_2._guide/node0521.html) would be used
to force data out to the disk before turning the motor off. ETD_CLEAR or
[CMD_CLEAR](../Includes_and_Autodocs_2._guide/node051F.html) is usually used after having locked out the trackdisk device via
the use of the disk resource, when you wish to prevent the track from
being updated, or when you wish to force the track to be re-read.
ETD_CLEAR or [CMD_CLEAR](../Includes_and_Autodocs_2._guide/node051F.html) will not do an update, nor will an update command
do a clear.

You clear the track buffer by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device with
[CMD_CLEAR](../Includes_and_Autodocs_2._guide/node051F.html) or ETD_CLEAR set in io_Command.  For ETD_CLEAR, you must also
set iotd_Count to the current diskchange number.

   DiskIO->iotd_Req.io_Command = TD_CLEAR;
   DoIO((struct IORequest *)DiskIO);

