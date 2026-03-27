# dos.library/SelectOutput



   NAME
	SelectOutput -- Select a filehandle as the default output channel (V36)

   SYNOPSIS
	old_fh = SelectOutput(fh)
	D0                    D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) SelectOutput(BPTR)

   FUNCTION
	Set the current output as the default output for the process.
	This changes the value returned by [Output()](../Includes_and_Autodocs_3._guide/node0198.html).  old_fh should
	be closed or saved as needed.

   INPUTS
	fh     - Newly desired output handle

   RESULT
	old_fh - Previous current output

   SEE ALSO
	[Output()](../Includes_and_Autodocs_3._guide/node0198.html), [SelectInput()](../Includes_and_Autodocs_3._guide/node01AE.html), [Input()](../Includes_and_Autodocs_3._guide/node017F.html)

