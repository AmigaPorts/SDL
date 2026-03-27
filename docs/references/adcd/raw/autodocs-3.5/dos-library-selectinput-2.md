# dos.library/SelectInput



   NAME
	SelectInput -- Select a filehandle as the default input channel (V36)

   SYNOPSIS
	old_fh = SelectInput(fh)
	D0                   D1

	[BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) SelectInput(BPTR)

   FUNCTION
	Set the current input as the default input for the process.
	This changes the value returned by [Input()](../Includes_and_Autodocs_3._guide/node017F.html).  old_fh should
	be closed or saved as needed.

   INPUTS
	fh     - Newly default input handle

   RESULT
	old_fh - Previous default input filehandle

   SEE ALSO
	[Input()](../Includes_and_Autodocs_3._guide/node017F.html), [SelectOutput()](../Includes_and_Autodocs_3._guide/node01AF.html), [Output()](../Includes_and_Autodocs_3._guide/node0198.html)

