---
title: trackdisk.device/TD_GETNUMTRACKS
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-getnumtracks-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_GETNUMTRACKS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TD_GETNUMTRACKS -- return the number of tracks for the type of disk
			   drive for the unit that was opened.

   FUNCTION
	This command returns the number of tracks that are available
	on the disk unit.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	TD_GETNUMTRACKS
	io_Flags	0 or IOF_QUICK

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)
	io_Actual - if io_Error is 0 this contains the drive type connected to
		    this unit.

   SEE ALSO
	[TD_GETDRIVETYPE](autodocs-3.5/trackdisk-device-td-getdrivetype-2.md)

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
