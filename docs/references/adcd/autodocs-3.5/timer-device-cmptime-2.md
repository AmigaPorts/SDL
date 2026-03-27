---
title: timer.device/CmpTime
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-cmptime-2
functions: [AddTime, SubTime]
libraries: [timer.device]
---

# timer.device/CmpTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CmpTime -- Compare two [timeval](autodocs-3.5/include-devices-timer-h.md) structures.

   SYNOPSIS
	result = CmpTime( Dest, Source )
	D0                A0    A1

	[LONG](autodocs-3.5/include-exec-types-h.md) CmpTime( struct [timeval](autodocs-3.5/include-devices-timer-h.md) *, struct [timeval](autodocs-3.5/include-devices-timer-h.md) *);

   FUNCTION
	This routine compares [timeval](autodocs-3.5/include-devices-timer-h.md) structures

	A0 and A1 will be left unchanged

   INPUTS
	Dest, Source -- pointers to [timeval](autodocs-3.5/include-devices-timer-h.md) structures.

   RESULTS
	result will be   0 if Dest has same time as source
	                -1 if Dest has more time than source
	                +1 if Dest has less time than source

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/AddTime()](autodocs-3.5/timer-device-addtime-2.md),
	[timer.device/SubTime()](autodocs-3.5/timer-device-subtime-2.md)

   BUGS
	Older version of this document had the sense of the return
	codes wrong; the code hasn't changed but the document has.

---

## See Also

- [AddTime — timer.device](../autodocs/timer.device.md#addtime)
- [SubTime — timer.device](../autodocs/timer.device.md#subtime)
