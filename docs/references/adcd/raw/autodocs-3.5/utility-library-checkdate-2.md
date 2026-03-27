# utility.library/CheckDate



   NAME
	CheckDate -- checks a [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure for legal date. (V36)

   SYNOPSIS
	seconds = CheckDate(date);
	D0                  A0

	ULONG CheckDate(struct [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) *);

   FUNCTION
	Determines if the [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure contains legal date information
	and returns the number of seconds from 01-Jan-1978 to that date, or 0
	if the [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure contains illegal data.

   INPUTS
	date - a filled-in [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure

   RESULTS
	seconds	- 0 if date is invalid, otherwise the number of seconds from
		  01-Jan-1978 to the date

   BUGS
	The wday field of the [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure is not checked.

   SEE ALSO
	[Amiga2Date()](../Includes_and_Autodocs_3._guide/node0596.html), [Date2Amiga()](../Includes_and_Autodocs_3._guide/node059C.html)

