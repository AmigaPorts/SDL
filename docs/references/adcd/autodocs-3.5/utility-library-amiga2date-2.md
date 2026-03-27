---
title: utility.library/Amiga2Date
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-amiga2date-2
functions: [CheckDate, Date2Amiga]
libraries: [utility.library]
---

# utility.library/Amiga2Date

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Amiga2Date -- fill in a [ClockData](autodocs-3.5/include-utility-date-h.md) structure based on a system
		      time stamp (V36)

   SYNOPSIS
	Amiga2Date(seconds,result);
	           D0      A0

	VOID Amiga2Date(ULONG,struct [ClockData](autodocs-3.5/include-utility-date-h.md) *);

   FUNCTION
	Fills in a [ClockData](autodocs-3.5/include-utility-date-h.md) structure with the date and time calculated
	from a ULONG containing the number of seconds from 01-Jan-1978
	to the date.

   INPUTS
	seconds - the number of seconds from 01-Jan-1978.
	result - a pointer to a [ClockData](autodocs-3.5/include-utility-date-h.md) structure that will be altered
		 by this function

   SEE ALSO
	[CheckDate()](autodocs-3.5/utility-library-checkdate-2.md), [Date2Amiga()](autodocs-3.5/utility-library-date2amiga-2.md)

---

## See Also

- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
