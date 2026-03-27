---
title: amiga.lib/TimeDelay
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-timedelay-2
functions: []
libraries: []
---

# amiga.lib/TimeDelay

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	TimeDelay -- Return after a period of time has elapsed.

   SYNOPSIS
	Error = TimeDelay( [Unit](autodocs-3.5/include-exec-devices-h.md), Seconds, MicroSeconds )
	D0                 D0    D1       D2

	[LONG](autodocs-3.5/include-exec-types-h.md) TimeDelay( [LONG](autodocs-3.5/include-exec-types-h.md), ULONG, ULONG );

   FUNCTION
	Waits for the period of time specified before returning to the
	the caller.

   INPUTS
	[Unit](autodocs-3.5/include-exec-devices-h.md) -- timer.device unit to open for this command.
	Seconds -- The seconds field of a [timerequest](autodocs-3.5/include-devices-timer-h.md) is filled with
	    this value. Check the documentation for what a particular
	    timer.device unit expects there.
	MicroSeconds -- The microseconds field of a [timerequest](autodocs-3.5/include-devices-timer-h.md) is
	    filled with this value. Check the documentation for what
	    a particular timer.device units expects there.

   RESULTS
	Error -- will be zero if all went well; otherwise, non-zero.

   NOTES
	Two likely reasons for failures are invalid unit numbers or
	no more free signal bits for this task.

	While this function first appears in V37 amiga.lib, it works
	on Kickstart V33 and higher.

   SEE ALSO
	[timer.device/TR_ADDREQUEST](autodocs-3.5/timer-device-tr-addrequest-2.md),
	timer.device/TR_WAITUNTIL,
	timer.device/WaitUnitl()

   BUGS

