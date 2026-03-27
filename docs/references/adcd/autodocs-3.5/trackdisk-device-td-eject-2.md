---
title: trackdisk.device/TD_EJECT
manual: autodocs-3.5
chapter: autodocs-3.5
section: trackdisk-device-td-eject-2
functions: [OpenDevice]
libraries: [exec.library]
---

# trackdisk.device/TD_EJECT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       TD_EJECT -- eject (or load) the disk in the drive, if possible.
```
   FUNCTION
	This command causes the drive to attempt to eject the disk in
	it, if any.  Note that the current trackdisk.device does not
	implement this command, but it might in the future, and other
	trackdisk-compatible drivers may implement this command.  Some
	devices may be able to load disks on command also.

   IO REQUEST INPUT
	io_Device	preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice()](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	TD_EJECT
	io_Flags	0 or IOF_QUICK
	io_Length	0 (load, if supported) or 1 (eject)

   IO REQUEST RESULT
	io_Error - 0 for success, or an error code as defined in
	           [<devices/trackdisk.h>](autodocs-3.5/include-devices-trackdisk-h.md)

   BUGS
	The pre-V40 autodoc didn't mention io_Length.  Because of this, for
	devices that can never support load, a driver might want to eject if
	io_Length is 0.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
