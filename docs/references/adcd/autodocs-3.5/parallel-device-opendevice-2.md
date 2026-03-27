---
title: parallel.device/OpenDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-opendevice-2
functions: [CloseDevice, Open]
libraries: [dos.library, exec.library]
---

# parallel.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	[Open](autodocs-3.5/dos-library-open-2.md) -- a request to open the parallel port

   SYNOPSIS
	error = OpenDevice("parallel.device", unit, ioExtPar, flags)
	D0                  A0                D0    A1        D1

   FUNCTION
	This function allows the requestor software access to the parallel
	device.  Unless the shared-access bit (bit 5 of io_ParFlags) is
	set, exclusive use is granted and no other access is allowed
	until the owner closes the device.

	A FAST_MODE, can be specified (bit 3 of io_Parflags) to speed up
	transfers to high-speed printers. Rather than waiting for the printer
	to acknowledge a character using the *ACK interrupt, this mode will
	send out data as long as the BUSY signal is low. The printer must be
	able to raise the BUSY signal within 3 micro-seconds on A2630s,
	otherwise data will be lost. Should be used only in an exclusive-
	access [Open()](autodocs-3.5/dos-library-open-2.md).

	A SLOWMODE mode can be specified (bit 4 of io_ParFlags) when very
	slow printers are used. If the printer acknowledges data at less
	than 5000 bytes per second, then this mode will actually save CPU
	time, although it consumes much more with high-speed printers.

	The PTermArray of the ioExtPar is initialized only if the EOFMODE
	bit (bit 1 of io_ParFlags) is set. The PTermArray can be further
	modified using the [PDCMD_SETPARAMS](autodocs-3.5/parallel-device-pdcmd-setparams-2.md) command.

   INPUTS
	"parallel.device" - a pointer to literal string "parallel.device"
	unit - Must be zero for future compatibility
	ioExtPar - pointer to an IO [Request](autodocs-3.5/intuition-library-request-2.md) block of structure IOExtPar to
		   be initialized by the [Open()](autodocs-3.5/dos-library-open-2.md) function. The io_ParFlags
		   field must be set as desired.
	flags - Must be zero for future compatibility

   RESULTS
	d0 -- same as io_Error
	io_Error -- if the [Open](autodocs-3.5/dos-library-open-2.md) succeded, then io_Error will be null.
		    If the [Open](autodocs-3.5/dos-library-open-2.md) failed, then io_Error will be non-zero.

   SEE ALSO
	[exec/CloseDevice()](autodocs-3.5/serial-device-closedevice-2.md)

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [Open — dos.library](../autodocs/dos.library.md#open)
