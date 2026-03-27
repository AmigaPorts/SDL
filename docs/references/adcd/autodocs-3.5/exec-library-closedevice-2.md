---
title: exec.library/CloseDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-closedevice-2
functions: [CloseDevice, OpenDevice]
libraries: [exec.library]
---

# exec.library/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CloseDevice -- conclude access to a device

   SYNOPSIS
	CloseDevice(iORequest)
		    A1

	void CloseDevice(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	This function informs the device that access to a device/unit
	previously opened has been concluded.  The device may perform
	certain house-cleaning operations.

	The user must ensure that all outstanding IORequests have been
	returned before closing the device.  The [AbortIO](autodocs-3.5/timer-device-abortio-2.md) function can kill
	any stragglers.

	After a close, the I/O request structure is free to be reused.
	Starting with V36 exec it is safe to CloseDevice() with an
	[IORequest](autodocs-3.5/include-exec-io-h.md) that is either cleared to zeros, or failed to
	open.

   INPUTS
	iORequest - pointer to an I/O request structure

   SEE ALSO
	[OpenDevice()](autodocs-3.5/exec-library-opendevice-2.md)

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
