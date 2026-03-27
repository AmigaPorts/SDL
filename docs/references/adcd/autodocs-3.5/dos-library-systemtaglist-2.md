---
title: dos.library/SystemTagList
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-systemtaglist-2
functions: [CreateNewProc, Input, Output, SystemTagList]
libraries: [dos.library]
---

# dos.library/SystemTagList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SystemTagList -- Have a shell execute a command line (V36)

   SYNOPSIS
	error = SystemTagList(command, tags)
	D0		        D1      D2

	[LONG](autodocs-3.5/include-exec-types-h.md) SystemTagList(STRPTR, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	error = System(command, tags)
	D0		 D1      D2

	[LONG](autodocs-3.5/include-exec-types-h.md) System(STRPTR, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	error = SystemTags(command, Tag1, ...)

	[LONG](autodocs-3.5/include-exec-types-h.md) SystemTags(STRPTR, ULONG, ...)

   FUNCTION
	Similar to [Execute()](autodocs-3.5/dos-library-execute-2.md), but does not read commands from the input
	filehandle.  Spawns a Shell process to execute the command, and
	returns the returncode the command produced, or -1 if the command
	could not be run for any reason.  The input and output filehandles
	will not be closed by System, you must close them (if needed) after
	System returns, if you specified them via SYS_Input or SYS_Output.

	By default the new process will use your current [Input()](autodocs-3.5/dos-library-input-2.md) and [Output()](autodocs-3.5/dos-library-output-2.md)
	filehandles.  Normal Shell command-line parsing will be done
	including redirection on 'command'.  The current directory and path
	will be inherited from your process.  Your path will be used to find
	the command (if no path is specified).

	Note that you may NOT pass the same filehandle for both SYS_Input
	and SYS_Output.  If you want input and output to both be to the same
	CON: window, pass a SYS_Input of a filehandle on the CON: window,
	and pass a SYS_Output of NULL.  The shell will automatically set
	the default [Output()](autodocs-3.5/dos-library-output-2.md) stream to the window you passed via SYS_Input,
	by opening "*" on that handler.

	If used with the SYS_Asynch flag, it WILL close both it's input and
	output filehandles after running the command (even if these were
	your [Input()](autodocs-3.5/dos-library-input-2.md) and Output()!)

	Normally uses the boot (ROM) shell, but other shells can be specified
	via SYS_UserShell and SYS_CustomShell.  Normally, you should send
	things written by the user to the UserShell.  The UserShell defaults
	to the same shell as the boot shell.

	The tags are passed through to [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md) (tags that conflict
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
	tags    - see [<dos/dostags.h>](autodocs-3.5/include-dos-dostags-h.md).  Note that both SystemTagList()-
		  specific tags and tags from [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md) may be passed.

   RESULT
	error	- 0 for success, result from command, or -1.  Note that on
		  error, the caller is responsible for any filehandles or other
		  things passed in via tags.  -1 will only be returned if
		  dos could not create the new shell.  If the command is not
		  found the shell will return an error value, normally
		  RETURN_ERROR.

   SEE ALSO
	[Execute()](autodocs-3.5/dos-library-execute-2.md), [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md), [<dos/dostags.h>](autodocs-3.5/include-dos-dostags-h.md), [Input()](autodocs-3.5/dos-library-input-2.md), [Output()](autodocs-3.5/dos-library-output-2.md)

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [SystemTagList — dos.library](../autodocs/dos.library.md#systemtaglist)
