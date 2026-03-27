---
title: 14 / Disk Status Commands / Determining The Presence Of A Disk
manual: devices
chapter: devices
section: 14-disk-status-commands-determining-the-presence-of-a-disk
functions: []
libraries: []
---

# 14 / Disk Status Commands / Determining The Presence Of A Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You determine the presence of a disk in a drive by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to
the device with [TD_CHANGESTATE](autodocs-2.0/trackdisk-device-td-changestate.md) set in io_Command.  For quick I/O, you must
set io_Flags to IOF_QUICK.

   DiskIO->iotd_Req.io_Flags = IOF_QUICK;
   DiskIO->iotd_Req.io_Command = TD_CHANGESTATE;
   BeginIO((struct IORequest *)DiskIO);

[TD_CHANGESTATE](autodocs-2.0/trackdisk-device-td-changestate.md) returns the presence indicator of a disk in io_Actual. The
value returned will be zero if a disk is currently in the drive and
nonzero if the drive has no disk.

