---
title: exec.library/RemDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remdevice-2
functions: [AddLibrary, Forbid, Permit]
libraries: [exec.library]
---

# exec.library/RemDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemDevice -- remove a device from the system

   SYNOPSIS
	RemDevice(device)
	          A1

	void RemDevice(struct [Device](autodocs-3.5/include-exec-devices-h.md) *);

   FUNCTION
	This function calls the device's EXPUNGE vector, which requests
	that a device delete itself.  The device may refuse to do this if
	it is busy or currently open. This is not typically called by user
	code.

	There are certain, limited circumstances where it may be
	appropriate to attempt to specifically flush a certain device.
	Example:

	 /* Attempts to flush the named device out of memory. */
	 #include [<exec/types.h>](autodocs-3.5/include-exec-types-h.md)
	 #include [<exec/execbase.h>](autodocs-3.5/include-exec-execbase-h.md)

	 void FlushDevice(name)
	 [STRPTR](autodocs-3.5/include-exec-types-h.md) name;
	 {
	 struct [Device](autodocs-3.5/include-exec-devices-h.md) *result;

	    Forbid();
	    if(result=(struct [Device](autodocs-3.5/include-exec-devices-h.md) *)FindName(&SysBase->DeviceList,name))
		RemDevice(result);
	    Permit();
	 }

   INPUTS
	device - pointer to a device node

   SEE ALSO
	[AddLibrary()](autodocs-3.5/exec-library-addlibrary-2.md)

---

## See Also

- [AddLibrary — exec.library](../autodocs/exec.library.md#addlibrary)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
