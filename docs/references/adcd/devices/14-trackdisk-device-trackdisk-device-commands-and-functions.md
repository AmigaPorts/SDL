---
title: 14 Trackdisk Device / Trackdisk Device Commands and Functions
manual: devices
chapter: devices
section: 14-trackdisk-device-trackdisk-device-commands-and-functions
functions: [AbortIO, CloseDevice, DoIO, OpenDevice]
libraries: [exec.library, timer.device]
---

# 14 Trackdisk Device / Trackdisk Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Command          Operation
--------         ----------
[CMD_CLEAR](devices/14-advanced-commands-clearing-the-track-buffer.md)        Mark track buffer as invalid. Forces the track to be
ETD_CLEAR        re-read.  ETD_CLEAR also checks for a diskchange.

[CMD_READ](devices/14-device-interface-reading-from-the-trackdisk-device.md)         Read one or more sectors from a disk.  ETD_READ also
[ETD_READ](devices/14-device-interface-reading-from-the-trackdisk-device.md)         reads the sector label area and checks for a diskchange.

[CMD_UPDATE](devices/14-advanced-commands-updating-a-track-sector.md)       Write out track buffer if it has been changed. ETD_UPDATE
ETD_UPDATE       also checks for a diskchange.

[CMD_WRITE](devices/14-device-interface-writing-to-the-trackdisk-device.md)        Write one or more sectors to a disk.  ETD_WRITE also
[ETD_WRITE](devices/14-device-interface-writing-to-the-trackdisk-device.md)        writes the sector label area and checks for a diskchange.

[TD_ADDCHANGEINT](devices/14-adding-a-diskchange-software-interrupt-handler.md)  Add an interrupt handler to be activated on a diskchange.

[TD_CHANGENUM](devices/14-disk-status-commands-determining-the-current-diskchange.md)     Return the current value of the diskchange counter used

                 by the ETD commands to determine if a diskchange has
                 occurred.
[TD_CHANGESTATE](devices/14-disk-status-commands-determining-the-presence-of-a-disk.md)   Return the disk present/not-present status of a drive.

[TD_EJECT](devices/14-advanced-commands-ejecting-a-disk.md)         Eject a disk from a drive.  This command will only work

```c
                 on drives that support an eject command (V36).
```
[TD_FORMAT](devices/14-advanced-commands-formatting-a-track.md)        Initialize one or more tracks with a data buffer.
ETD_FORMAT       ETD_FORMAT also initializes the sector label area.

[TD_GETDRIVETYPE](devices/14-disk-status-commands-determining-the-drive-type.md)  Return the type of disk drive in use by the unit.

[TD_GETGEOMETRY](devices/14-advanced-commands-determining-the-drive-geometry-table.md)   Return the disk geometry table (V36).

[TD_GETNUMTRACKS](devices/14-disk-status-commands-determining-the-number-of-tracks-of.md)  Return the number of tracks usable with the unit.

[TD_MOTOR](devices/14-advanced-commands-controlling-the-drive-motor.md)         Turn the motor on or off.  ETD_MOTOR also checks for a
ETD_MOTOR        diskchange.

[TD_PROTSTATUS](devices/14-disk-status-commands-determining-the-write-protect.md)    Return the write-protect status of a disk.

[TD_RAWREAD](devices/14-commands-for-low-level-access-reading-raw-data-from-a.md)       Read RAW sector data from disk (unencoded MFM).
[ETD_RAWREAD](devices/14-commands-for-low-level-access-reading-raw-data-from-a.md)      ETD_RAWREAD also checks for a diskchange.

[TD_RAWWRITE](devices/14-commands-for-low-level-access-writing-raw-data-to-a-disk.md)      Write RAW sector data to disk.  ETD_RAWWRITE also checks
[ETD_RAWWRITE](devices/14-commands-for-low-level-access-writing-raw-data-to-a-disk.md)     for a diskchange.

[TD_REMCHANGEINT](devices/14-removing-a-diskchange-software-interrupt-handler.md)  Remove a diskchange interrupt handler.

[TD_SEEK](devices/14-diagnostics-and-repair-moving-the-drive-head-to-a.md)          Move the head to a specific track.  ETD_SEEK also checks

                 for a
[ETD_SEEK](devices/14-diagnostics-and-repair-moving-the-drive-head-to-a.md)         diskchange.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)        Abort a command to the trackdisk device.

BeginIO()        Initiate a command and return immediately (asynchronous

```c
                 request).
```
[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)    Relinquish use of a disk unit.

[DoIO()](autodocs-2.0/exec-library-doio.md)           Initiate a command and wait for completion (synchronous

```c
                 request).
```
[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)     Obtain exclusive use of a particular disk unit.


Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)    Create an extended I/O request structure of type [IOExtTD](devices/14-trackdisk-device-device-interface.md).

                 This structure will be used to communicate commands to
                 the trackdisk device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)     Create a signal message port for reply messages from the

                 trackdisk device.  Exec will signal a task when a message
                 arrives at the reply port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)    Delete an I/O request structure created by [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).

[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)     Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
