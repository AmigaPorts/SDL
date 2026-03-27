---
title: 14 / Diagnostics and Repair / Moving The Drive Head To A Specific Track
manual: devices
chapter: devices
section: 14-diagnostics-and-repair-moving-the-drive-head-to-a
functions: []
libraries: []
---

# 14 / Diagnostics and Repair / Moving The Drive Head To A Specific Track

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You move the drive head to a specific track by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the
device with [TD_SEEK](autodocs-2.0/trackdisk-device-td-seek.md) or ETD_SEEK set in io_Command, and io_Offset set to
the byte offset of the track to which the seek is to occur.


```c
    DiskIO->iotd_Req.io_Offset = (ULONG)(TRACK_SIZE * track);
    DiskIO->iotd_Req.io_Command = TD_SEEK;
    DoIO((struct IORequest *)DiskIO);
```
   Seeking is not Reading.
   -----------------------
   [TD_SEEK](autodocs-2.0/trackdisk-device-td-seek.md) and ETD_SEEK do not verify their position until the next
   read. That is, they only move the heads; they do not actually read
   any data.

