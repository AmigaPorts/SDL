---
title: 14 / Disk Status Commands / Determining The Number Of Tracks Of A Drive
manual: devices
chapter: devices
section: 14-disk-status-commands-determining-the-number-of-tracks-of
functions: []
libraries: []
---

# 14 / Disk Status Commands / Determining The Number Of Tracks Of A Drive

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the number of a tracks of a drive by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to
the device with [TD_GETNUMTRACKS](autodocs-2.0/trackdisk-device-td-getnumtracks.md) set in io_Command.  For quick I/O, you
must set io_Flags to IOF_QUICK.


```c
    DiskIO->iotd_Req.io_Flags = IOF_QUICK;
    DiskIO->iotd_Req.io_Command = TD_GETNUMTRACKS;
    BeginIO((struct IORequest *)DiskIO);
```
[TD_GETNUMTRACKS](autodocs-2.0/trackdisk-device-td-getnumtracks.md) returns the number of tracks on that device in io_Actual.
This is the number of tracks of TD_SECTOR * NUMSECS size. It is not the
number of cylinders. With two heads, the number of cylinders is half of
the number of tracks.  The number of cylinders is equal to the number of
tracks divided by the number of heads (surfaces).  The standard 3.5" Amiga
drive has two heads

[TD_GETGEOMETRY](autodocs-2.0/trackdisk-device-td-getgeometry.md) is the preferred over [TD_GETNUMTRACKS](autodocs-2.0/trackdisk-device-td-getnumtracks.md) for V36 and higher
versions of the operating system especially since new drive types may have
more sectors or different sector sizes, etc., than standard Amiga drives.

