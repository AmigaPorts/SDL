# utility.library/Date2Amiga



   NAME
	Date2Amiga -- calculate seconds from 01-Jan-1978. (V36)

   SYNOPSIS
	seconds = Date2Amiga(date);
	D0                   A0

	ULONG Date2Amiga(struct [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) *);

   FUNCTION
	Calculates the number of seconds from 01-Jan-1978 to the date
	specified in the [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure.

   INPUTS
	date - pointer to a [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure containing the date of
	       interest.

   RESULTS
	seconds	- the number of seconds from 01-Jan-1978 to the date specified.

   WARNING
	This function does no sanity checking of the data in the [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23)
	structure.

   SEE ALSO
	[Amiga2Date()](../Includes_and_Autodocs_3._guide/node0596.html), [CheckDate()](../Includes_and_Autodocs_3._guide/node059A.html)

