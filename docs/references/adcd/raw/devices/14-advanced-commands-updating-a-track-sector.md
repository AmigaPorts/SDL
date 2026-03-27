# 14 / Advanced Commands / Updating A Track Sector


The Amiga trackdisk device does not write data sectors unless it is
necessary (you request that a different track be used) or until the user
requests that an update be performed. This improves system speed by
caching disk operations.  The update commands ensure that any buffered
data is flushed out to the disk. If the track buffer has not been changed
since the track was read in, the update commands do nothing.

You update a data sector by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device with
[CMD_UPDATE](../Includes_and_Autodocs_2._guide/node0521.html) or ETD_UPDATE set in io_Command.  For ETD_UPDATE, you must also
set iotd_Count to the current diskchange number.

   DiskIO->iotd_Req.io_Command = TD_UPDATE;
   DoIO((struct IORequest *)DiskIO);

