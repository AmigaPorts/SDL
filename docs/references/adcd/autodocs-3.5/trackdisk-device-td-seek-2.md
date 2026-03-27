---
title: trackdisk.device/TD_SEEK
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-seek-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_SEEK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TD_SEEK/ETD_SEEK -- control positioning of the drive heads.

   FUNCTION
	These commands are currently provided for internal diagnostics,
	disk repair, and head cleaning only.

	TD_SEEK and ETD_SEEK move the drive heads to the track specified. The
	io_Offset field should be set to the (byte) offset to which the seek is
	to occur. TD_SEEK and ETD_SEEK do not verify their position until the
	next read. That is, they only move the heads; they do not actually read
	any data.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	TD_SEEK or ETD_SEEK
	io_Flags	0 or IOF_QUICK
	io_Offset	byte offset from the start of the disk describing
			where to move the head to.
	iotd_Count	(ETD_SEEK only) maximum allowable change counter
			value.

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
