---
title: exec.library/AddDevice
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-adddevice-2
functions: [CloseDevice, OpenDevice, RemDevice]
libraries: [exec.library]
---

# exec.library/AddDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddDevice -- add a device to the system

   SYNOPSIS
	AddDevice(device)
		  A1

	void AddDevice(struct [Device](autodocs-3.5/include-exec-devices-h.md) *);

   FUNCTION
	This function adds a new device to the system device list, making
	it available to other programs.  The device must be ready to be
	opened at this time.

   INPUTS
	device - pointer to a properly initialized device node

   SEE ALSO
	[RemDevice()](autodocs-3.5/exec-library-remdevice-2.md), [OpenDevice()](autodocs-3.5/exec-library-opendevice-2.md), [CloseDevice()](autodocs-3.5/exec-library-closedevice-2.md), [MakeLibrary()](autodocs-3.5/exec-library-makelibrary-2.md)

---

## See Also

- [CloseDevice — exec.library](../autodocs/exec.library.md#closedevice)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [RemDevice — exec.library](../autodocs/exec.library.md#remdevice)
