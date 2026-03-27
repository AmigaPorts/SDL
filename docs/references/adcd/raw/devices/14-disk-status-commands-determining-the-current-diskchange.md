# 14 / Disk Status Commands / Determining The Current Diskchange Number


You determine the current diskchange number of a disk by passing an
[IOExtTD](../Devices_Manual_guide/node00DE.html#line12) to the device with [TD_CHANGENUM](../Includes_and_Autodocs_2._guide/node0524.html) set in io_Command.  For quick I/O,
you must set io_Flags to IOF_QUICK.


```c
    DiskIO->iotd_Req.io_Flags = IOF_QUICK;
    DiskIO->iotd_Req.io_Command = TD_CHANGENUM;
    BeginIO((struct IORequest *)DiskIO);
```
[TD_CHANGENUM](../Includes_and_Autodocs_2._guide/node0524.html) returns the current value of the diskchange counter (as used
by the enhanced commands) in io_Actual. The disk change counter is
incremented each time the disk is inserted or removed.


```c
    ULONG change_count;

    DiskIO->iotd_Req.io_Flags = IOF_QUICK;
    DiskIO->iotd_Req.io_Command = TD_CHANGENUM;
    BeginIO((struct IORequest *)DiskIO);
    /* store current diskchange value */
    change_count = DiskIO->iotd_Req.io_Actual;

    DiskIO->iotd_Req.io_Length = 1;     /* Turn on the drive motor */
    DiskIO->iotd_Count = change_count;
    DiskIO->iotd_Req.io_Command = ETD_MOTOR;
    DoIO((struct IORequest *)DiskIO);
```
