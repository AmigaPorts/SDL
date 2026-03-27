# dos.library/DateStamp



    NAME
	[DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) -- Obtain the date and time in internal format

    SYNOPSIS
	ds = DateStamp( ds );
	D0		D1

	struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) *DateStamp(struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) *)

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
	ds - pointer a struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51)

    RESULTS
	The array is filled as described and returned (for pre-V36
	compabability).

    SEE ALSO
	[DateToStr()](../Includes_and_Autodocs_3._guide/node0150.html), [StrToDate()](../Includes_and_Autodocs_3._guide/node01C3.html), [SetFileDate()](../Includes_and_Autodocs_3._guide/node01B5.html), [CompareDates()](../Includes_and_Autodocs_3._guide/node014A.html)

