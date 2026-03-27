---
title: trackdisk.device/TD_GETDRIVETYPE
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-getdrivetype-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_GETDRIVETYPE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TD_GETDRIVETYPE -- return the type of disk drive for the unit that was
			   opened.

   FUNCTION
	This command returns the type of the disk drive to the user.
	This number will be a small integer and will come from the set of
	DRIVEXXX constants defined in [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md).

	The only way you can actually use this command is if the trackdisk
	device understands the drive type of the hardware that is plugged in.
	This is because the [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md) call will fail if the trackdisk device
	does not understand the drive type. To find raw drive identifiers see
	the disk.resource's DR_GETUNITID entry point.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	TD_GETDRIVETYPE
	io_Flags	0 or IOF_QUICK

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)
	io_Actual - if io_Error is 0 this contains the drive type connected to
		    this unit.

   SEE ALSO
	[TD_GETNUMTRACKS](autodocs-3.5/trackdisk-device-td-getnumtracks-2.md), [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
