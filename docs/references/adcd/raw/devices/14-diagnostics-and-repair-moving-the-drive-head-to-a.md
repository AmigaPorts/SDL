# 14 / Diagnostics and Repair / Moving The Drive Head To A Specific Track


You move the drive head to a specific track by passing an [IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the
device with [TD_SEEK](../Includes_and_Autodocs_2._guide/node0530.html) or ETD_SEEK set in io_Command, and io_Offset set to
the byte offset of the track to which the seek is to occur.


```c
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track);
    DiskIO->iotd_Req.io_Command = TD_SEEK;
    DoIO((struct IORequest *)DiskIO);
```
   Seeking is not Reading.
   -----------------------
   [TD_SEEK](../Includes_and_Autodocs_2._guide/node0530.html) and ETD_SEEK do not verify their position until the next
   read. That is, they only move the heads; they do not actually read
   any data.

