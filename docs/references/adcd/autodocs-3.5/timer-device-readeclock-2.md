---
title: timer.device/ReadEClock
manual: autodocs-3.5
chapter: autodocs-3.5
section: timer-device-readeclock-2
functions: []
libraries: []
---

# timer.device/ReadEClock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadEClock -- Get the current value of the E-Clock. (V36)

   SYNOPSIS
	E_Freq = ReadEClock( Dest )
	D0                   A0

	ULONG ReadEClock ( struct [EClockVal](autodocs-3.5/include-devices-timer-h.md) * );

   FUNCTION
	This routine calculates the current 64 bit value of the E-Clock
	and stores it in the destination [EClockVal](autodocs-3.5/include-devices-timer-h.md) structure. The count
	rate of the E-Clock is also returned.

	A0 will be left unchanged

	This is a low overhead function designed so that very short
	intervals may be timed.

   INPUTS
	Dest -- pointer to an [EClockVal](autodocs-3.5/include-devices-timer-h.md) structure.

   RETURNS
	Dest -- the [EClockVal](autodocs-3.5/include-devices-timer-h.md) structure will contain the E-Clock time
	E_Freq -- The count rate of the E-Clock (tics/sec).

   NOTES
	This function may be called from interrupts.

   SEE ALSO

   BUGS

