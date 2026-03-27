---
title: dos.library/CreateNewProc
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-createnewproc-2
functions: [CreateNewProc, DupLock, LoadSeg, ReadArgs, RunCommand]
libraries: [dos.library]
---

# dos.library/CreateNewProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateNewProc -- Create a new process (V36)

   SYNOPSIS
	process = CreateNewProc(tags)
	D0                       D1

	struct [Process](autodocs-3.5/include-dos-dosextens-h.md) *CreateNewProc(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	process = CreateNewProcTagList(tags)
	D0                       	D1

	struct [Process](autodocs-3.5/include-dos-dosextens-h.md) *CreateNewProcTagList(struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	process = CreateNewProcTags(Tag1, ...)

	struct [Process](autodocs-3.5/include-dos-dosextens-h.md) *CreateNewProcTags(ULONG, ...)

   FUNCTION
	This creates a new process according to the tags passed in.  See
	[dos/dostags.h](autodocs-3.5/include-dos-dostags-h.md) for the tags.

	You must specify one of NP_Seglist or NP_Entry.  NP_Seglist takes a
	seglist (as returned by LoadSeg()).  NP_Entry takes a function
	pointer for the routine to call.

	There are many options, as you can see by examining [dos/dostags.h](autodocs-3.5/include-dos-dostags-h.md).
	The defaults are for a non-CLI process, with copies of your
	[CurrentDir](autodocs-3.5/dos-library-currentdir-2.md), HomeDir (used for PROGDIR:), priority, consoletask,
	windowptr, and variables.  The input and output filehandles default
	to opens of NIL:, stack to 4000, and others as shown in dostags.h.
	This is a fairly reasonable default setting for creating threads,
	though you may wish to modify it (for example, to give a descriptive
	name to the process.)

	CreateNewProc() is callable from a task, though any actions that
	require doing Dos I/O (DupLock() of currentdir, for example) will not
	occur.

	NOTE: if you call CreateNewProc() with both NP_Arguments, you must
	not specify an NP_Input of NULL.  When NP_Arguments is specified, it
	needs to modify the input filehandle to make [ReadArgs()](autodocs-3.5/dos-library-readargs-2.md) work properly.

   INPUTS
	tags - a pointer to a [TagItem](autodocs-3.5/include-utility-tagitem-h.md) array.

   RESULT
	process - The created process, or NULL.  Note that if it returns
		  NULL, you must free any items that were passed in via
		  tags, such as if you passed in a new current directory
		  with NP_CurrentDir.

   BUGS
	In V36, NP_Arguments was broken in a number of ways, and probably
	should be avoided (instead you should start a small piece of your
	own code, which calls [RunCommand()](autodocs-3.5/dos-library-runcommand-2.md) to run the actual code you wish
	to run).  In V37, NP_Arguments works, though see the note above.

   SEE ALSO
	[LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), [CreateProc()](autodocs-3.5/dos-library-createproc-2.md), [ReadArgs()](autodocs-3.5/dos-library-readargs-2.md), [RunCommand()](autodocs-3.5/dos-library-runcommand-2.md), [<dos/dostags.h>](autodocs-3.5/include-dos-dostags-h.md)

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [DupLock — dos.library](../autodocs/dos.library.md#duplock)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
