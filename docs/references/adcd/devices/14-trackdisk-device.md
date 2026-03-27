---
title: 14 Trackdisk Device
manual: devices
chapter: devices
section: 14-trackdisk-device
functions: []
libraries: []
---

# 14 Trackdisk Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga trackdisk device directly drives the disk, controls the disk
motors, reads raw data from the tracks, and writes raw data to the tracks.
Normally, you use the AmigaDOS functions to write or read data from the
disk. The trackdisk device is the lowest-level software access to the disk
data and is used by AmigaDOS to access the disks.  The trackdisk device
supports the usual commands such as [CMD_WRITE](devices/14-device-interface-writing-to-the-trackdisk-device.md) and [CMD_READ](devices/14-device-interface-reading-from-the-trackdisk-device.md).  In addition,
it supports an extended form of these commands to allow additional control
over the trackdisk device.


```c
                    NEW FEATURES FOR VERSION 2.0

                    Feature            Description
                --------------       --------------
                [TD_GETGEOMETRY](devices/14-advanced-commands-determining-the-drive-geometry-table.md)       Device Command
                [TD_EJECT](devices/14-advanced-commands-ejecting-a-disk.md)             Device Command
                IOTF_INDEXSYNC       Device Command Flag
                IOTF_WORDSYNC        Device Command Flag
                Fast RAM Buffers     Now Supported
```
   Compatibility Warning:
   ----------------------
   The new features for 2.0 are not backwards compatible.

 [Trackdisk Device Commands and Functions](devices/14-trackdisk-device-trackdisk-device-commands-and-functions.md) 
 [Device Interface](devices/14-trackdisk-device-device-interface.md) 
 [Advanced Commands](devices/14-trackdisk-device-advanced-commands.md) 
 [Disk Status Commands](devices/14-trackdisk-device-disk-status-commands.md) 
 [Commands for Diagnostics and Repair](devices/14-trackdisk-device-commands-for-diagnostics-and-repair.md) 
 [Notification of Disk Changes](devices/14-trackdisk-device-notification-of-disk-changes.md) 
 [Commands for Low-Level Access](devices/14-trackdisk-device-commands-for-low-level-access.md) 
 [Trackdisk Device Errors](devices/14-trackdisk-device-trackdisk-device-errors.md) 
 [Example Trackdisk Program](devices/devices-dev-examples-track-copy-c.md) 
 [Additional Information on the Trackdisk Device](devices/14-trackdisk-device-additional-information-on-the-trackdisk.md) 

