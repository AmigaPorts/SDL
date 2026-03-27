---
title: trackdisk.device/TD_CHANGESTATE
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-changestate-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_CHANGESTATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TD_CHANGESTATE -- check if a disk is currently in a drive.

   FUNCTION
	This command checks to see if there is currently a disk in a drive.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	TD_CHANGESTATE
	io_Flags	0 or IOF_QUICK

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)
	io_Actual - if io_Error is 0, this tells you whether a disk is in
		    the drive. 0 means there is a disk, while anything else
		    indicates there is no disk.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
