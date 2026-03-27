# dos.library/SetIoErr



   NAME
	SetIoErr -- Sets the value returned by [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) (V36)

   SYNOPSIS
	oldcode = SetIoErr(code)
	D0		    D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SetIoErr(LONG);

   FUNCTION
	This routine sets up the secondary result (pr_Result2) return code
	(returned by the [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) function).

   INPUTS
	code - Code to be returned by a call to [IoErr](../Includes_and_Autodocs_3._guide/node0182.html).

   RESULT
	oldcode - The previous error code.

   SEE ALSO
	[IoErr()](../Includes_and_Autodocs_3._guide/node0182.html), [Fault()](../Includes_and_Autodocs_3._guide/node0161.html), [PrintFault()](../Includes_and_Autodocs_3._guide/node019E.html)

