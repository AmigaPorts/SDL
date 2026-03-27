---
title: timer.device/SubTime
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-subtime-2
functions: [AddTime, CmpTime]
libraries: [timer.device]
---

# timer.device/SubTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SubTime -- Subtract one time request from another.

   SYNOPSIS
	SubTime( Dest, Source )
	         A0    A1

	void SubTime( struct [timeval](autodocs-3.5/include-devices-timer-h.md) *, struct [timeval](autodocs-3.5/include-devices-timer-h.md) *);

   FUNCTION
	This routine subtracts one [timeval](autodocs-3.5/include-devices-timer-h.md) structure from another.  The
	results are stored in the destination (Dest - Source -> Dest)

	A0 and A1 will be left unchanged

   INPUTS
	Dest, Source -- pointers to [timeval](autodocs-3.5/include-devices-timer-h.md) structures.

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/AddTime()](autodocs-3.5/timer-device-addtime-2.md),
	[timer.device/CmpTime()](autodocs-3.5/timer-device-cmptime-2.md)

   BUGS

---

## See Also

- [AddTime — timer.device](../autodocs/timer.device.md#addtime)
- [CmpTime — timer.device](../autodocs/timer.device.md#cmptime)
