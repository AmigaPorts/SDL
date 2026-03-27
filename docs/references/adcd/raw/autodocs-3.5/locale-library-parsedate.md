# locale.library/ParseDate



   NAME
	ParseDate -- interpret a string according to the date formatting
		     template and convert it into a [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51). (V38)

   SYNOPSIS
	state = ParseDate(locale,date,fmtTemplate,getCharFunc);
	D0	          A0     A1   A2          A3

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ParseDate(struct [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) *,struct [DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) *,[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *);

   FUNCTION
	This function converts a stream of characters into an AmigaDOS
	[DateStamp](../Includes_and_Autodocs_3._guide/node05F8.html#line51) structure. The characters are obtained from the
	getCharFunc callback hook and the formatting template is used
	to direct the parse.

   INPUTS
	locale - the locale to use for the formatting
	date - place to put the converted date, this may be NULL in which
	       case this routine can be used to simply validate a date
	fmtTemplate - the date template describing the expected format of the
		      data. See [FormatDate()](../Includes_and_Autodocs_3._guide/node0456.html) documentation for a description of
		      date templates. The following formatting controls from
		      [FormatDate()](../Includes_and_Autodocs_3._guide/node0456.html) can be used in ParseDate():
	                %a %A %b %B %d %e %h %H %I %m %M %p %S %y %Y
	getCharFunc - a callback hook invoked whenever a character is required.
		      The hook should return the next character to process,
		      with a NULL character to indicate the end of the string.
		      The hook is called with:

		 	A0 - address of [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) structure
	                A1 - locale pointer
			A2 - NULL

	              The hook returns the character to process in D0. Note
		      that a complete 32-bit result is expected in D0, not
		      just 8 bits.

   RESULT
	state - TRUE if the parsing went OK, or FALSE if the input did not
		match the template

   SEE ALSO
	[FormatDate()](../Includes_and_Autodocs_3._guide/node0456.html), [<dos/dos.h>](../Includes_and_Autodocs_3._guide/node05F8.html)

