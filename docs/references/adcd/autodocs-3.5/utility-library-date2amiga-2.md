---
title: utility.library/Date2Amiga
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-date2amiga-2
functions: [Amiga2Date, CheckDate]
libraries: [utility.library]
---

# utility.library/Date2Amiga

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Date2Amiga -- calculate seconds from 01-Jan-1978. (V36)

   SYNOPSIS
	seconds = Date2Amiga(date);
	D0                   A0

	ULONG Date2Amiga(struct [ClockData](autodocs-3.5/include-utility-date-h.md) *);

   FUNCTION
	Calculates the number of seconds from 01-Jan-1978 to the date
	specified in the [ClockData](autodocs-3.5/include-utility-date-h.md) structure.

   INPUTS
	date - pointer to a [ClockData](autodocs-3.5/include-utility-date-h.md) structure containing the date of
	       interest.

   RESULTS
	seconds	- the number of seconds from 01-Jan-1978 to the date specified.

   WARNING
	This function does no sanity checking of the data in the [ClockData](autodocs-3.5/include-utility-date-h.md)
	structure.

   SEE ALSO
	[Amiga2Date()](autodocs-3.5/utility-library-amiga2date-2.md), [CheckDate()](autodocs-3.5/utility-library-checkdate-2.md)

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
