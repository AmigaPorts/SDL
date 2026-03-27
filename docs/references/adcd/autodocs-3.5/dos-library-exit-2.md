---
title: dos.library/Exit
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-exit-2
functions: [CreateNewProc]
libraries: [dos.library]
---

# dos.library/Exit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Exit -- Exit from a program

    SYNOPSIS
	Exit( returnCode )
	      D1

	void Exit(LONG)

    FUNCTION
	Exit() is currently for use with programs written as if they
	were BCPL programs.  This function is not normally useful for
	other purposes.

	In general, therefore, please DO NOT CALL THIS FUNCTION!

	In order to exit, C programs should use the C language exit()
	function (note the lower case letter "e").  Assembly programs should
	place a return code in D0, and execute an RTS instruction with
	their original stack ptr.

    IMPLEMENTATION
	The action of Exit() depends on whether the program which called it
	is running as a command under a CLI or not. If the program is
	running under the CLI the command finishes and control reverts to
	the CLI. In this case, returnCode is interpreted as the return code
	from the program.

	If the program is running as a distinct process, Exit() deletes the
	process and release the space associated with the stack, segment
	list and process structure.

    INPUTS
	returnCode - integer

    SEE ALSO
	[CreateProc()](autodocs-3.5/dos-library-createproc-2.md), [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md)

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
