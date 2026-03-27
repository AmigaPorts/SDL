---
title: 14 / Disk Status Commands / Determining The Current Diskchange Number
manual: devices
chapter: devices
section: 14-disk-status-commands-determining-the-current-diskchange
functions: []
libraries: []
---

# 14 / Disk Status Commands / Determining The Current Diskchange Number

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the current diskchange number of a disk by passing an
[IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with [TD_CHANGENUM](autodocs-2.0/trackdisk-device-td-changenum.md) set in io_Command.  For quick I/O,
you must set io_Flags to IOF_QUICK.


```c
    DiskIO->iotd_Req.io_Flags = IOF_QUICK;
    DiskIO->iotd_Req.io_Command = TD_CHANGENUM;
    BeginIO((struct IORequest *)DiskIO);
```
[TD_CHANGENUM](autodocs-2.0/trackdisk-device-td-changenum.md) returns the current value of the diskchange counter (as used
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
