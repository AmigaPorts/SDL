---
title: 14 / Advanced Commands / Clearing The Track Buffer
manual: devices
chapter: devices
section: 14-advanced-commands-clearing-the-track-buffer
functions: []
libraries: []
---

# 14 / Advanced Commands / Clearing The Track Buffer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ETD_CLEAR and [CMD_CLEAR](autodocs-2.0/trackdisk-device-cmd-clear.md) mark the track buffer as invalid, forcing a reread
of the disk on the next operation. ETD_UPDATE or [CMD_UPDATE](autodocs-2.0/trackdisk-device-cmd-update.md) would be used
to force data out to the disk before turning the motor off. ETD_CLEAR or
[CMD_CLEAR](autodocs-2.0/trackdisk-device-cmd-clear.md) is usually used after having locked out the trackdisk device via
the use of the disk resource, when you wish to prevent the track from
being updated, or when you wish to force the track to be re-read.
ETD_CLEAR or [CMD_CLEAR](autodocs-2.0/trackdisk-device-cmd-clear.md) will not do an update, nor will an update command
do a clear.

You clear the track buffer by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with
[CMD_CLEAR](autodocs-2.0/trackdisk-device-cmd-clear.md) or ETD_CLEAR set in io_Command.  For ETD_CLEAR, you must also
set iotd_Count to the current diskchange number.

   DiskIO->iotd_Req.io_Command = TD_CLEAR;
   DoIO((struct IORequest *)DiskIO);

