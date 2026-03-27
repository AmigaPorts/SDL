# dos.library/RunCommand



   NAME
	RunCommand -- Runs a program using the current process (V36)

   SYNOPSIS
	rc = RunCommand(seglist, stacksize, argptr, argsize)
	D0                D1         D2       D3      D4

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) RunCommand(BPTR, ULONG, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ULONG)

   FUNCTION
	Runs a command on your process/cli.  Seglist may be any language,
	including BCPL programs.  Stacksize is in bytes.  argptr is a null-
	terminated string, argsize is its length.  Returns the returncode the
	program exited with in d0. Returns -1 if the stack couldn't be
	allocated.

	NOTE: the argument string MUST be terminated with a newline to work
	properly with [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html) and other argument parsers.

	RunCommand also takes care of setting up the current input filehandle
	in such a way that [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html) can be used in the program, and restores
	the state of the buffering before returning.  It also sets the value
	returned by [GetArgStr()](../Includes_and_Autodocs_3._guide/node0174.html), and restores it before returning.  NOTE:
	the setting of the argument string in the filehandle was added in V37.

	It's usually appropriate to set the command name (via
	[SetProgramName()](../Includes_and_Autodocs_3._guide/node01BC.html)) before calling RunCommand().  RunCommand() sets
	the value returned by [GetArgStr()](../Includes_and_Autodocs_3._guide/node0174.html) while the command is running.

   INPUTS
	seglist   - Seglist of command to run.
	stacksize - Number of bytes to allocate for stack space
	argptr    - Pointer to argument command string.
	argsize   - Number of bytes in argument command.

   RESULT
	rc        - Return code from executed command. -1 indicates failure

   SEE ALSO
	[CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html), [SystemTagList()](../Includes_and_Autodocs_3._guide/node01C5.html), [Execute()](../Includes_and_Autodocs_3._guide/node015E.html), [GetArgStr()](../Includes_and_Autodocs_3._guide/node0174.html),
	[SetProgramName()](../Includes_and_Autodocs_3._guide/node01BC.html), [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html)

