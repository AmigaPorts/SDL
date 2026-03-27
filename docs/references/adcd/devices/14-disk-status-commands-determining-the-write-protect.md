---
title: 14 / Disk Status Commands / Determining The Write-Protect Status Of A Disk
manual: devices
chapter: devices
section: 14-disk-status-commands-determining-the-write-protect
functions: []
libraries: []
---

# 14 / Disk Status Commands / Determining The Write-Protect Status Of A Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the write-protect status of a disk by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to
the device with [TD_PROTSTATUS](autodocs-2.0/trackdisk-device-td-protstatus.md) set in io_Command.  For quick I/O, you must
set io_Flags to IOF_QUICK.

   DiskIO->iotd_Req.io_Flags = IOF_QUICK;
   DiskIO->iotd_Req.io_Command = TD_PROTSTATUS;
   BeginIO((struct IORequest *)DiskIO);

[TD_PROTSTATUS](autodocs-2.0/trackdisk-device-td-protstatus.md) returns the write-protect status in io_Actual. The value
will be zero if the disk is not write-protected and nonzero if the disk is
write-protected.

