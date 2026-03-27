---
title: dos.library/DateStamp
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-datestamp-2
functions: [CompareDates, DateStamp, DateToStr, StrToDate]
libraries: [dos.library]
---

# dos.library/DateStamp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	[DateStamp](autodocs-3.5/include-dos-dos-h.md) -- Obtain the date and time in internal format

    SYNOPSIS
	ds = DateStamp( ds );
	D0		D1

	struct [DateStamp](autodocs-3.5/include-dos-dos-h.md) *DateStamp(struct [DateStamp](autodocs-3.5/include-dos-dos-h.md) *)

    FUNCTION
	DateStamp() takes a structure of three longwords that is set to the
	current time.  The first element in the vector is a count of the
	number of days.  The second element is the number of minutes elapsed
	in the day.  The third is the number of ticks elapsed in the current
	minute.  A tick happens 50 times a second.  DateStamp() ensures that
	the day and minute are consistent.  All three elements are zero if
	the date is unset. DateStamp() currently only returns even
	multiples of 50 ticks.  Therefore the time you get is always an even
	number of ticks.

	Time is measured from Jan 1, 1978.

    INPUTS
	ds - pointer a struct [DateStamp](autodocs-3.5/include-dos-dos-h.md)

    RESULTS
	The array is filled as described and returned (for pre-V36
	compabability).

    SEE ALSO
	[DateToStr()](autodocs-3.5/dos-library-datetostr-2.md), [StrToDate()](autodocs-3.5/dos-library-strtodate-2.md), [SetFileDate()](autodocs-3.5/dos-library-setfiledate-2.md), [CompareDates()](autodocs-3.5/dos-library-comparedates-2.md)

---

## See Also

- [CompareDates — dos.library](../autodocs/dos.library.md#comparedates)
- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
- [DateToStr — dos.library](../autodocs/dos.library.md#datetostr)
- [StrToDate — dos.library](../autodocs/dos.library.md#strtodate)
