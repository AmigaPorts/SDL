---
title: narrator.device/CloseDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: narrator-device-closedevice-2
functions: []
libraries: []
---

# narrator.device/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseDevice - terminates access to the narrator device


   SYNOPSIS
	CloseDevice(IORequest)
		       A1

   FUNCTION
	[Close](autodocs-3.5/dos-library-close-2.md) invalidates the IO_UNIT and IO_DEVICE fields in the
	[IORequest](autodocs-3.5/include-exec-io-h.md) block, preventing subsequent IO until another
	[OpenDevice](autodocs-3.5/serial-device-opendevice-2.md).  CloseDevice also reduces the open count.  If
	the count goes to 0 and the expunge bit is set, the device
	is expunged.  If the open count goes to zero and the delayed
	expunge bit is not set, CloseDevice sets the expunge bit.


   INPUTS
	A valid [IORequest](autodocs-3.5/include-exec-io-h.md) block with its io_Message structure, and
	io_Device and io_Unit fields properly initialized.  These
	fields are initialized by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md).


   RESULTS
	CloseDevice invalidates the unit and device pointers in the
	[IORequest](autodocs-3.5/include-exec-io-h.md) block.


   SEE ALSO

