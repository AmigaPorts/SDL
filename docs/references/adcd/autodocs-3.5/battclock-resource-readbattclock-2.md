---
title: battclock.resource/ReadBattClock
manual: autodocs-3.5
chapter: autodocs-3.5
section: battclock-resource-readbattclock-2
functions: []
libraries: []
---

# battclock.resource/ReadBattClock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReadBattClock -- [Read](autodocs-3.5/dos-library-read-2.md) time from clock chip.  (V36)

   SYNOPSIS
	AmigaTime = ReadBattClock( )

	ULONG ReadBattClock( void );
	D0

   FUNCTION
	This routine reads the time from the clock chip and returns it
	as the number of seconds from 01-jan-1978.

   INPUTS

   RESULTS
	AmigaTime       The number of seconds from 01-Jan-1978 that
	                    the clock chip thinks it is.

   NOTES
	If the clock chip returns an invalid date, the clock chip is
	reset and 0 is returned.

   SEE ALSO

   BUGS

