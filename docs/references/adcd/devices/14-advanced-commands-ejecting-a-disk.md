---
title: 14 / Advanced Commands / Ejecting A Disk
manual: devices
chapter: devices
section: 14-advanced-commands-ejecting-a-disk
functions: []
libraries: []
---

# 14 / Advanced Commands / Ejecting A Disk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Certain disk drive manufacturers allow software control of disk ejection.
The trackdisk device provides the [TD_EJECT](autodocs-2.0/trackdisk-device-td-eject.md) command to tell such drives to
eject a disk.

You eject a disk by passing an [IOExtTD](devices/14-trackdisk-device-device-interface.md) to the device with [TD_EJECT](autodocs-2.0/trackdisk-device-td-eject.md) set in
io_Command.

   DiskIO->iotd_Req.io_Command = TD_EJECT;
   DoIO((struct IORequest *)DiskIO);

   Read the Instruction Manual.
   ----------------------------
   The Commodore 3.5" drives for the Amiga and most other Amiga drive
   manufacturers do not support software disk ejects.  Attempting this
   command on those drives will result in an error condition.  Consult
   the instruction manual for your disk drive to determine whether this
   is supported.

