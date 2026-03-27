---
title: timer.device/GetSysTime
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-getsystime-2
functions: []
libraries: []
---

# timer.device/GetSysTime

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetSysTime -- Get the system time. (V36)

   SYNOPSIS
	GetSysTime( Dest )
	            A0

	void GetSysTime( struct [timeval](autodocs-3.5/include-devices-timer-h.md) * );

   FUNCTION
	Ask the system what time it is.  The system time starts off at
	zero at power on, but may be initialized via the [TR_SETSYSTIME](autodocs-3.5/timer-device-tr-setsystime-2.md)
	timer.device command.

	System time is monotonocally increasing and guarenteed to be
	unique (except when the system time is set back).

	A0 will be left unchanged.

	This function is less expensive to use than the [TR_GETSYSTIME](autodocs-3.5/timer-device-tr-getsystime-2.md)
	[IORequest](autodocs-3.5/include-exec-io-h.md).

   INPUTS
	Dest -- pointer to a [timeval](autodocs-3.5/include-devices-timer-h.md) structure to hold the system time.

   RESULTS
	Dest -- the [timeval](autodocs-3.5/include-devices-timer-h.md) structure will contain the system time.

   NOTES
	This function may be called from interrupts.

   SEE ALSO
	[timer.device/TR_GETSYSTIME](autodocs-3.5/timer-device-tr-getsystime-2.md),
	[timer.device/TR_SETSYSTIME](autodocs-3.5/timer-device-tr-setsystime-2.md),

   BUGS

