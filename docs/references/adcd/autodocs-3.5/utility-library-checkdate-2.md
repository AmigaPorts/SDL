---
title: utility.library/CheckDate
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-checkdate-2
functions: [Amiga2Date, Date2Amiga]
libraries: [utility.library]
---

# utility.library/CheckDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CheckDate -- checks a [ClockData](autodocs-3.5/include-utility-date-h.md) structure for legal date. (V36)

   SYNOPSIS
	seconds = CheckDate(date);
	D0                  A0

	ULONG CheckDate(struct [ClockData](autodocs-3.5/include-utility-date-h.md) *);

   FUNCTION
	Determines if the [ClockData](autodocs-3.5/include-utility-date-h.md) structure contains legal date information
	and returns the number of seconds from 01-Jan-1978 to that date, or 0
	if the [ClockData](autodocs-3.5/include-utility-date-h.md) structure contains illegal data.

   INPUTS
	date - a filled-in [ClockData](autodocs-3.5/include-utility-date-h.md) structure

   RESULTS
	seconds	- 0 if date is invalid, otherwise the number of seconds from
		  01-Jan-1978 to the date

   BUGS
	The wday field of the [ClockData](autodocs-3.5/include-utility-date-h.md) structure is not checked.

   SEE ALSO
	[Amiga2Date()](autodocs-3.5/utility-library-amiga2date-2.md), [Date2Amiga()](autodocs-3.5/utility-library-date2amiga-2.md)

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
