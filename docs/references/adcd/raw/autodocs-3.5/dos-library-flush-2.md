# dos.library/Flush



   NAME
	Flush -- Flushes buffers for a buffered filehandle (V36)

   SYNOPSIS
	success = Flush(fh)
	D0		D1

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Flush(BPTR)

   FUNCTION
	Flushes any pending buffered writes to the filehandle.  All buffered
	writes will also be flushed on [Close()](../Includes_and_Autodocs_3._guide/node0149.html).  If the filehandle was being
	used for input, it drops the buffer, and tries to [Seek()](../Includes_and_Autodocs_3._guide/node01AD.html) back to the
	last read position  (so subsequent reads or writes will occur at the
	expected position in the file).

   INPUTS
	fh	- Filehandle to flush.

   RESULT
	success - Success or failure.

   BUGS
	Before V37 release, Flush() returned a random value.  As of V37,
	it always returns success (this will be fixed in some future
	release).

	The V36 and V37 releases didn't properly flush filehandles which
	have never had a buffered IO done on them.  This commonly occurs
	on redirection of input of a command, or when opening a file for
	input and then calling [CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html) with NP_Arguments, or when
	using a new filehandle with [SelectInput()](../Includes_and_Autodocs_3._guide/node01AE.html) and then calling
	[RunCommand()](../Includes_and_Autodocs_3._guide/node01AA.html).  This is fixed in V39.  A workaround would be to
	do [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html), then [UnGetC()](../Includes_and_Autodocs_3._guide/node01C6.html), then Flush().

   SEE ALSO
	FputC(), [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html), [UnGetC()](../Includes_and_Autodocs_3._guide/node01C6.html), [Seek()](../Includes_and_Autodocs_3._guide/node01AD.html), [Close()](../Includes_and_Autodocs_3._guide/node0149.html), [CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html),
	[SelectInput()](../Includes_and_Autodocs_3._guide/node01AE.html), [RunCommand()](../Includes_and_Autodocs_3._guide/node01AA.html)

