# dos.library/CompareDates



   NAME
	CompareDates -- Compares two datestamps (V36)

   SYNOPSIS
	result = CompareDates(date1,date2)
	D0                     D1     D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) CompareDates(struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) *,struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) *)

   FUNCTION
	Compares two times for relative magnitide.  <0 is returned if date1 is
	later than date2, 0 if they are equal, or >0 if date2 is later than
	date1.  NOTE: this is NOT the same ordering as strcmp!

   INPUTS
	date1, date2 - DateStamps to compare

   RESULT
	result -  <0, 0, or >0 based on comparison of two date stamps

   SEE ALSO
	[DateStamp()](../Includes_and_Autodocs_3._guide/node014F.html), [DateToStr()](../Includes_and_Autodocs_3._guide/node0150.html), [StrToDate()](../Includes_and_Autodocs_3._guide/node01C3.html)

