---
title: timer.device/AddTime
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-addtime-2
functions: [CmpTime, SubTime]
libraries: [timer.device]
---

# timer.device/AddTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddTime -- Add one time request to another.

   SYNOPSIS
	AddTime( Dest, Source )
	         A0    A1

	void AddTime( struct [timeval](autodocs-3.5/include-devices-timer-h.md) *, struct [timeval](autodocs-3.5/include-devices-timer-h.md) *);

   FUNCTION
	This routine adds one [timeval](autodocs-3.5/include-devices-timer-h.md) structure to another.  The
	results are stored in the destination (Dest + Source -> Dest)

	A0 and A1 will be left unchanged

   INPUTS
	Dest, Source -- pointers to [timeval](autodocs-3.5/include-devices-timer-h.md) structures.

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/CmpTime()](autodocs-3.5/timer-device-cmptime-2.md),
	[timer.device/SubTime()](autodocs-3.5/timer-device-subtime-2.md)

   BUGS

---

## See Also

- [CmpTime — timer.device](../autodocs/timer.device.md#cmptime)
- [SubTime — timer.device](../autodocs/timer.device.md#subtime)
