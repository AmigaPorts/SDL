# dos.library/StrToDate



   NAME
	StrToDate -- Converts a string to a [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) (V36)

   SYNOPSIS
	success = StrToDate( datetime )
	D0                      D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) StrToDate( struct [DateTime](../Includes_and_Autodocs_3._guide/node05F9.html#line24) * )

   FUNCTION
	Converts a human readable ASCII string into an AmigaDOS
	[DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51).

   INPUTS
	[DateTime](../Includes_and_Autodocs_3._guide/node05F9.html#line24) - a pointer to an initialized [DateTime](../Includes_and_Autodocs_3._guide/node05F9.html#line24) structure.

	The [DateTime](../Includes_and_Autodocs_3._guide/node05F9.html#line24) structure should	be initialized as follows:

	dat_Stamp  - ignored on input.

	dat_Format - a format	byte which specifies the format	of the
		dat_StrDat.  This can	be any of the following	(note:
		If value used	is something other than	those below,
		the default of FORMAT_DOS is used):

		FORMAT_DOS:	  AmigaDOS format (dd-mmm-yy).

		FORMAT_INT:	  International	format (yy-mmm-dd).

		FORMAT_USA:	  American format (mm-dd-yy).

		FORMAT_CDN:	  Canadian format (dd-mm-yy).

		FORMAT_DEF:	  default format for locale.

	dat_Flags - a flags byte.  The only flag which affects this
		  function is:

		DTF_SUBST:	ignored by this function
		DTF_FUTURE:	  If set, indicates that strings such
				  as (stored in	dat_StrDate) "Monday"
				  refer	to "next" monday. Otherwise,
				  if clear, strings like "Monday"
				  refer	to "last" monday.

	dat_StrDay - ignored bythis function.

	dat_StrDate -	pointer	to valid string	representing the date.
		  This can be a	"DTF_SUBST" style string such as
		  "Today" "Tomorrow" "Monday", or it may be a string
		  as specified by the dat_Format byte.	This will be
		  converted to the ds_Days portion of the [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51).
		  If this pointer is NULL, DateStamp->ds_Days will not
		  be affected.

	dat_StrTime -	Pointer	to a buffer which contains the time in
		  the ASCII format hh:mm:ss.  This will	be converted
		  to the ds_Minutes and	ds_Ticks portions of the
		  [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51).  If this pointer is NULL, ds_Minutes and
		  ds_Ticks will	be unchanged.

   RESULT
	success	- a zero return indicates that a conversion could
		not be performed. A non-zero return indicates that the
		DateTime.dat_Stamp variable contains the converted
		values.

   SEE ALSO
	[DateStamp()](../Includes_and_Autodocs_3._guide/node014F.html), [DateToStr()](../Includes_and_Autodocs_3._guide/node0150.html), [<dos/datetime.h>](../Includes_and_Autodocs_3._guide/node05F9.html)

