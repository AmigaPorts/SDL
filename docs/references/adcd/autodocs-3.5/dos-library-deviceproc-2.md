---
title: dos.library/DeviceProc
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-deviceproc-2
functions: [AssignPath, DupLock, FreeDeviceProc, GetDeviceProc, IoErr, UnLock]
libraries: [dos.library]
---

# dos.library/DeviceProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DeviceProc -- Return the process [MsgPort](autodocs-3.5/include-exec-ports-h.md) of specific I/O handler

    SYNOPSIS
	process = DeviceProc( name )
	D0		      D1

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *DeviceProc (STRPTR)

    FUNCTION
	DeviceProc() returns the process identifier of the process which
	handles the device associated with the specified name. If no
	process handler can be found then the result is zero. If the name
	refers to an assign then a directory lock is returned in [IoErr()](autodocs-3.5/dos-library-ioerr-2.md).
	This lock should not be UnLock()ed or Examine()ed (if you wish to do
	so, [DupLock()](autodocs-3.5/dos-library-duplock-2.md) it first).

    BUGS
	In V36, if you try to DeviceProc() something relative to an assign
	made with [AssignPath()](autodocs-3.5/dos-library-assignpath-2.md), it will fail.  This is because there's no
	way to know when to unlock the lock.  If you're writing code for
	V36 or later, it is highly advised you use [GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md) instead,
	or make your code conditional on V36 to use GetDeviceProc()/
	[FreeDeviceProc()](autodocs-3.5/dos-library-freedeviceproc-2.md).

    SEE ALSO
	[GetDeviceProc()](autodocs-3.5/dos-library-getdeviceproc-2.md), [FreeDeviceProc()](autodocs-3.5/dos-library-freedeviceproc-2.md), [DupLock()](autodocs-3.5/dos-library-duplock-2.md), [UnLock()](autodocs-3.5/dos-library-unlock-2.md), [Examine()](autodocs-3.5/dos-library-examine-2.md)

---

## See Also

- [AssignPath — dos.library](../autodocs/dos.library.md#assignpath)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [FreeDeviceProc — dos.library](../autodocs/dos.library.md#freedeviceproc)
- [GetDeviceProc — dos.library](../autodocs/dos.library.md#getdeviceproc)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
