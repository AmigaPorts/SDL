---
title: 14 / Disk Status Commands / Determining The Drive Type
manual: devices
chapter: devices
section: 14-disk-status-commands-determining-the-drive-type
functions: []
libraries: []
---

# 14 / Disk Status Commands / Determining The Drive Type

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the drive type of a unit by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device
with [TD_GETDRIVETYPE](autodocs-2.0/trackdisk-device-td-getdrivetype.md) set in io_Command.  For quick I/O, you must set
io_Flags to IOF_QUICK.

   DiskIO->iotd_Req.io_Flags = IOF_QUICK;
   DiskIO->iotd_Req.io_Command = TD_GETDRIVETYPE;
   BeginIO((struct IORequest *)DiskIO);

[TD_GETDRIVETYPE](autodocs-2.0/trackdisk-device-td-getdrivetype.md) returns the drive type for the unit that was opened in
io_Actual. The value will be DRIVE3_5 for 3.5" drives and DRIVE5_25 for
5.25" drives.  The unit can be opened only if the device understands the
drive type it is connected to.

