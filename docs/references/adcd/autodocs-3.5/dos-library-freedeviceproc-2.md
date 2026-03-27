---
title: dos.library/FreeDeviceProc
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-freedeviceproc-2
functions: [AssignLate, AssignLock, AssignPath, FreeDeviceProc, GetDeviceProc]
libraries: [dos.library]
---

# dos.library/FreeDeviceProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeDeviceProc -- Releases port returned by [GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md) (V36)

   SYNOPSIS
	FreeDeviceProc(devproc)
			 D1

	void FreeDeviceProc(struct [DevProc](autodocs-3.5/include-dos-dosextens-h.md) *)

   FUNCTION
	Frees up the structure created by [GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md), and any associated
	temporary locks.

	Decrements the counter incremented by [GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md).  The counter
	is in an extension to the 1.3 process structure.  After calling
	FreeDeviceProc(), do not use the port or lock again!  It is safe to
	call FreeDeviceProc(NULL).

   INPUTS
	devproc - A value returned by [GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md)

   BUGS
	Counter not currently active in 2.0.

   SEE ALSO
	[GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md), [DeviceProc()](autodocs-3.5/dos-library-deviceproc-2.md), [AssignLock()](autodocs-3.5/dos-library-assignlock-2.md), [AssignLate()](autodocs-3.5/dos-library-assignlate-2.md),
	[AssignPath()](autodocs-3.5/dos-library-assignpath-2.md)

---

## See Also

- [AssignLate — dos.library](../autodocs/dos.library.md#assignlate)
- [AssignLock — dos.library](../autodocs/dos.library.md#assignlock)
- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [FreeDeviceProc — dos.library](../autodocs/dos.library.md#freedeviceproc)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
