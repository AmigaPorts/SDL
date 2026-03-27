---
title: trackdisk.device/TD_GETGEOMETRY
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-getgeometry-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_GETGEOMETRY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       TD_GETGEOMETRY -- return the geometry of the drive.
   FUNCTION
	This command returns a full set of information about the
	layout of the drive. The information is returned in the
	[DriveGeometry](autodocs-3.5/include-devices-trackdisk-h.md) structure pointed to by io_Data.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	TD_GETGEOMETRY
	io_Flags	0 or IOF_QUICK
	io_Data		Pointer to a [DriveGeometry](autodocs-3.5/include-devices-trackdisk-h.md) structure
	io_Length	sizeof(struct DriveGeometry)

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)

   NOTE
	This information may change when a disk in inserted when
	certain hardware is present.

   SEE ALSO
	[TD_GETDRIVETYPE](autodocs-3.5/trackdisk-device-td-getdrivetype-2.md), [TD_GETNUMTRACKS](autodocs-3.5/trackdisk-device-td-getnumtracks-2.md)

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
