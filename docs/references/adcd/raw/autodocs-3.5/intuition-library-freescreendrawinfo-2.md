# intuition.library/FreeScreenDrawInfo



   NAME	
 	FreeScreenDrawInfo -- Finish using a [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) structure. (V36)

   SYNOPSIS
	FreeScreenDrawInfo( [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132), DrInfo )
			    A0      A1

	VOID FreeScreenDrawInfo( struct [Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) *, struct [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) * );

   FUNCTION
	Declares that you are finished with the [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) structure
	returned by [GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html).

   INPUTS
 	[Screen](../Includes_and_Autodocs_3._guide/node0602.html#line132) - pointer to screen passed to [GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html).
	DrInfo - pointer to [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) returned by [GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html).
	    A NULL [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) pointer is a valid parameter, signifying
	    "do nothing".

   RESULT
 	None

   NOTES
	This function, and [GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html), don't really do much, but
	they provide an upward compatibility path.  That means that
	if you misuse them today, they probably won't cause a problem,
	although they may someday later.  So, please be very careful
	only to use the [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) structure between calls to
	[GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html) and FreeScreenDrawInfo(), and be sure
	that you don't forget FreeScreenDrawInfo().

   BUGS

   SEE ALSO
	[GetScreenDrawInfo()](../Includes_and_Autodocs_3._guide/node03BA.html)

