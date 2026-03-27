# utility.library/Amiga2Date



   NAME
	Amiga2Date -- fill in a [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure based on a system
		      time stamp (V36)

   SYNOPSIS
	Amiga2Date(seconds,result);
	           D0      A0

	VOID Amiga2Date(ULONG,struct [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) *);

   FUNCTION
	Fills in a [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure with the date and time calculated
	from a ULONG containing the number of seconds from 01-Jan-1978
	to the date.

   INPUTS
	seconds - the number of seconds from 01-Jan-1978.
	result - a pointer to a [ClockData](../Includes_and_Autodocs_3._guide/node05EB.html#line23) structure that will be altered
		 by this function

   SEE ALSO
	[CheckDate()](../Includes_and_Autodocs_3._guide/node059A.html), [Date2Amiga()](../Includes_and_Autodocs_3._guide/node059C.html)

