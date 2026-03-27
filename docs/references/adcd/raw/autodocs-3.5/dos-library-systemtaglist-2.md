# dos.library/SystemTagList



   NAME
	SystemTagList -- Have a shell execute a command line (V36)

   SYNOPSIS
	error = SystemTagList(command, tags)
	D0		        D1      D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SystemTagList(STRPTR, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

	error = System(command, tags)
	D0		 D1      D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) System(STRPTR, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *)

	error = SystemTags(command, Tag1, ...)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SystemTags(STRPTR, ULONG, ...)

   FUNCTION
	Similar to [Execute()](../Includes_and_Autodocs_3._guide/node015E.html), but does not read commands from the input
	filehandle.  Spawns a Shell process to execute the command, and
	returns the returncode the command produced, or -1 if the command
	could not be run for any reason.  The input and output filehandles
	will not be closed by System, you must close them (if needed) after
	System returns, if you specified them via SYS_Input or SYS_Output.

	By default the new process will use your current [Input()](../Includes_and_Autodocs_3._guide/node017F.html) and [Output()](../Includes_and_Autodocs_3._guide/node0198.html)
	filehandles.  Normal Shell command-line parsing will be done
	including redirection on 'command'.  The current directory and path
	will be inherited from your process.  Your path will be used to find
	the command (if no path is specified).

	Note that you may NOT pass the same filehandle for both SYS_Input
	and SYS_Output.  If you want input and output to both be to the same
	CON: window, pass a SYS_Input of a filehandle on the CON: window,
	and pass a SYS_Output of NULL.  The shell will automatically set
	the default [Output()](../Includes_and_Autodocs_3._guide/node0198.html) stream to the window you passed via SYS_Input,
	by opening "*" on that handler.

	If used with the SYS_Asynch flag, it WILL close both it's input and
	output filehandles after running the command (even if these were
	your [Input()](../Includes_and_Autodocs_3._guide/node017F.html) and Output()!)

	Normally uses the boot (ROM) shell, but other shells can be specified
	via SYS_UserShell and SYS_CustomShell.  Normally, you should send
	things written by the user to the UserShell.  The UserShell defaults
	to the same shell as the boot shell.

	The tags are passed through to [CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html) (tags that conflict
	with SystemTagList() will be filtered out).  This allows setting
	things like priority, etc for the new process.  The tags that are
	currently filtered out are:

		NP_Seglist
		NP_FreeSeglist
		NP_Entry
		NP_Input
		NP_Output
		NP_CloseInput
		NP_CloseOutput
		NP_HomeDir
		NP_Cli

   INPUTS
	command - Program and arguments
	tags    - see [<dos/dostags.h>](../Includes_and_Autodocs_3._guide/node0658.html).  Note that both SystemTagList()-
		  specific tags and tags from [CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html) may be passed.

   RESULT
	error	- 0 for success, result from command, or -1.  Note that on
		  error, the caller is responsible for any filehandles or other
		  things passed in via tags.  -1 will only be returned if
		  dos could not create the new shell.  If the command is not
		  found the shell will return an error value, normally
		  RETURN_ERROR.

   SEE ALSO
	[Execute()](../Includes_and_Autodocs_3._guide/node015E.html), [CreateNewProc()](../Includes_and_Autodocs_3._guide/node014C.html), [<dos/dostags.h>](../Includes_and_Autodocs_3._guide/node0658.html), [Input()](../Includes_and_Autodocs_3._guide/node017F.html), [Output()](../Includes_and_Autodocs_3._guide/node0198.html)

