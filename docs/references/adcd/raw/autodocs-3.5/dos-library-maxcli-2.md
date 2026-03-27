# dos.library/MaxCli



   NAME
	MaxCli -- returns the highest CLI process number possibly in use (V36)

   SYNOPSIS
	number = MaxCli()
	D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) MaxCli(void)

   FUNCTION
	Returns the highest CLI number that may be in use.  CLI numbers are
	reused, and are usually as small as possible.  To find all CLIs, scan
	using [FindCliProc()](../Includes_and_Autodocs_3._guide/node0166.html) from 1 to MaxCLI().  The number returned by
	MaxCli() may change as processes are created and destroyed.

   RESULT
	number - The highest CLI number that _may_ be in use.

   SEE ALSO
	[FindCliProc()](../Includes_and_Autodocs_3._guide/node0166.html), [Cli()](../Includes_and_Autodocs_3._guide/node0146.html)

