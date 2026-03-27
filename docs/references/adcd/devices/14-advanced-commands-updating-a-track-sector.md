---
title: 14 / Advanced Commands / Updating A Track Sector
manual: devices
chapter: devices
section: 14-advanced-commands-updating-a-track-sector
functions: []
libraries: []
---

# 14 / Advanced Commands / Updating A Track Sector

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga trackdisk device does not write data sectors unless it is
necessary (you request that a different track be used) or until the user
requests that an update be performed. This improves system speed by
caching disk operations.  The update commands ensure that any buffered
data is flushed out to the disk. If the track buffer has not been changed
since the track was read in, the update commands do nothing.

You update a data sector by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with
[CMD_UPDATE](autodocs-2.0/trackdisk-device-cmd-update.md) or ETD_UPDATE set in io_Command.  For ETD_UPDATE, you must also
set iotd_Count to the current diskchange number.

   DiskIO->iotd_Req.io_Command = TD_UPDATE;
   DoIO((struct IORequest *)DiskIO);

