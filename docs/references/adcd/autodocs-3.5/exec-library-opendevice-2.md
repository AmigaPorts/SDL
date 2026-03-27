---
title: exec.library/OpenDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-opendevice-2
functions: [AbortIO, CheckIO, CloseDevice, DoIO, SendIO, WaitIO]
libraries: [exec.library, timer.device]
---

# exec.library/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	OpenDevice -- gain access to a device

   SYNOPSIS
	error = OpenDevice(devName, unitNumber, iORequest, flags)
	D0		   A0	    D0		A1	   D1

	[BYTE](autodocs-3.5/include-exec-types-h.md) OpenDevice(STRPTR,ULONG,struct [IORequest](autodocs-3.5/include-exec-io-h.md) *,ULONG);

   FUNCTION
	This function opens the named device/unit and initializes the given
	I/O request block.  Specific documentation on opening procedures
	may come with certain devices.

	The device may exist in memory, or on disk; this is transparent to
	the OpenDevice caller.

	A full path name for the device name is legitimate.  For example
	"test:devs/fred.device".  This allows the use of custom devices
	without requiring the user to copy the device into the system's
	DEVS: directory.

   NOTES
	All calls to OpenDevice should have matching calls to CloseDevice!

	Devices on disk cannot be opened until after DOS has been
	started.

	As of V36 tasks can safely call OpenDevice, though DOS may open
	system requesters (e.g., asking the user to insert the Workbench
	disk if DEVS: is not online).  You must call this function from a
	DOS [Process](autodocs-3.5/include-dos-dosextens-h.md) if you want to turn off DOS requesters.

   INPUTS
	devName - requested device name

	unitNumber - the unit number to open on that device.  The format of
		the unit number is device specific.  If the device does
		not have separate units, send a zero.

	iORequest - the I/O request block to be returned with
		appropriate fields initialized.

	flags - additional driver specific information.  This is sometimes
		used to request opening a device with exclusive access.

   RESULTS
	error - Returns a sign-extended copy of the io_Error field
		of the [IORequest](autodocs-3.5/include-exec-io-h.md).  Zero if successful, else an error code
		is returned.

   BUGS
	AmigaDOS file names are not case sensitive, but Exec lists are.  If
	the library name is specified in a different case than it exists on
	disk, unexpected results may occur.

	Prior to V36, tasks could not make OpenDevice calls requiring disk
	access (since tasks are not allowed to make dos.library calls).
	Now OpenDevice is protected from tasks.

   SEE ALSO
	[CloseDevice()](autodocs-3.5/exec-library-closedevice-2.md), [DoIO()](autodocs-3.5/exec-library-doio-2.md), [SendIO()](autodocs-3.5/exec-library-sendio-2.md), [CheckIO()](autodocs-3.5/exec-library-checkio-2.md), [AbortIO()](autodocs-3.5/exec-library-abortio-2.md), [WaitIO()](autodocs-3.5/exec-library-waitio-2.md)

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
- [CheckIO — exec.library](../autodocs/exec.library.md#checkio)
- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
