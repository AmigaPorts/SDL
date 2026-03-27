---
title: 11 SCSI Device / SCSI Device Commands and Functions
manual: devices
chapter: devices
section: 11-scsi-device-scsi-device-commands-and-functions
functions: [AbortIO, AllocMem, AllocSignal, CheckIO, CloseDevice, DoIO, FreeMem, FreeSignal, OpenDevice, WaitIO]
libraries: [exec.library, timer.device]
---

# 11 SCSI Device / SCSI Device Commands and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

SCSI Device Command  Operation
-------------------  ---------
[HD_SCSICMD](devices/11-scsi-device-scsi-direct.md)           Issue a SCSI-direct command to a SCSI unit.


Trackdisk Device Commands Supported by the SCSI Device
------------------------------------------------------
[TD_CHANGESTATE](autodocs-2.0/trackdisk-device-td-changestate.md)       Return the disk present/not-present status of a drive.
[TD_FORMAT](autodocs-2.0/trackdisk-device-td-format.md)            Initialize one or more tracks with a data buffer.
[TD_PROTSTATUS](autodocs-2.0/trackdisk-device-td-protstatus.md)        Return the write-protect status of a disk.
[TD_SEEK](autodocs-2.0/trackdisk-device-td-seek.md)              Move the head to a specific track.


Exec Commands Supported by SCSI Device
--------------------------------------
CMD_READ             Read one or more sectors from a disk.
CMD_START            Restart a SCSI unit that was previously stopped with
                     CMD_STOP.
CMD_STOP             Stop a SCSI unit.
CMD_WRITE            Write one or more sectors to a disk.


Exec Functions as Used in This Chapter
--------------------------------------
[AbortIO()](autodocs-2.0/exec-library-abortio.md)            Abort an I/O request to the SCSI device.
[AllocMem()](autodocs-2.0/exec-library-allocmem.md)           Allocate a block of memory.
[AllocSignal()](autodocs-2.0/exec-library-allocsignal.md)        Allocate a signal bit.
[CheckIO()](autodocs-2.0/exec-library-checkio.md)            Return the status of an I/O request.
[CloseDevice()](autodocs-2.0/exec-library-closedevice.md)        Relinquish use of the SCSI device. All requests must

                     be complete before closing.
[DoIO()](autodocs-2.0/exec-library-doio.md)               Initiate a command and wait for completion

```c
                     (synchronous request).
```
[FreeMem()](autodocs-2.0/exec-library-freemem.md)            Free a block of previously allocated memory.
[FreeSignal()](autodocs-2.0/exec-library-freesignal.md)         Free a previously allocated signal.
[OpenDevice()](autodocs-2.0/exec-library-opendevice.md)         Obtain use of the SCSI device.  You specify the type

```c
                     of unit and its characteristics in the call to
                     OpenDevice().
```
[WaitIO()](autodocs-2.0/exec-library-waitio.md)             Wait for completion of an I/O request and remove it


                     from the reply port.
Exec Support Functions as Used in This Chapter
----------------------------------------------
[CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md)        Create an extended [IORequest](autodocs-2.0/includes-exec-io-h.md) structure for use in

                     communicating with the SCSI device.
[CreatePort()](autodocs-2.0/amiga-lib-createport.md)         Create a message port for reply messages from the

                     SCSI device.  Exec will signal a task when a message
                     arrives at the port.
[DeleteExtIO()](autodocs-2.0/amiga-lib-deleteextio.md)        Delete the extended [IORequest](autodocs-2.0/includes-exec-io-h.md) structure created by

```c
                     [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md).
```
[DeletePort()](autodocs-2.0/amiga-lib-deleteport.md)         Delete the message port created by [CreatePort()](autodocs-2.0/amiga-lib-createport.md).

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [FreeMem — exec.library](../autodocs/exec.library.md#freemem)
- [FreeSignal — exec.library](../autodocs/exec.library.md#freesignal)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
