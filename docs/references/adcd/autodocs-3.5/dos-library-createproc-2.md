---
title: dos.library/CreateProc
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-createproc-2
functions: [CreateNewProc, LoadSeg, UnLoadSeg]
libraries: [dos.library]
---

# dos.library/CreateProc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CreateProc -- Create a new process

    SYNOPSIS
	process = CreateProc( name, pri, seglist, stackSize )
	D0		      D1    D2	 D3	  D4

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *CreateProc(STRPTR, [LONG](autodocs-3.5/include-exec-types-h.md), [BPTR](autodocs-3.5/include-dos-dos-h.md), LONG)

    FUNCTION
	CreateProc() creates a new AmigaDOS process of name 'name'.  AmigaDOS
	processes are a superset of exec tasks.

	A seglist, as returned by [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), is passed as 'seglist'.
	This represents a section of code which is to be run as a new
	process. The code is entered at the first hunk in the segment list,
	which should contain suitable initialization code or a jump to
	such.  A process control structure is allocated from memory and
	initialized.  If you wish to fake a seglist (that will never
	have DOS [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md) called on it), use this code:

		    DS.L    0	;Align to longword
		    DC.L    16	;Segment "length" (faked)
		    DC.L    0	;Pointer to next segment
		    ...start of code...

	The size of the root stack upon activation is passed as
	'stackSize'.  'pri' specifies the required priority of the new
	process.  The result will be the process msgport address of the new
	process, or zero if the routine failed.  The argument 'name'
	specifies the new process name.  A zero return code indicates
	error.

	The seglist passed to CreateProc() is not freed when it exits; it
	is up to the parent process to free it, or for the code to unload
	itself.

	Under V36 and later, you probably should use [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md) instead.

    INPUTS
	name      - pointer to a null-terminated string
	pri       - signed long (range -128 to +127)
	seglist   - BCPL pointer to a seglist
	stackSize - integer (must be a multiple of 4 bytes)

    RESULTS
	process   - pointer to new process msgport

    SEE ALSO
	[CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md), [LoadSeg()](autodocs-3.5/dos-library-loadseg-2.md), [UnLoadSeg()](autodocs-3.5/dos-library-unloadseg-2.md)

---

## See Also

- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [UnLoadSeg — dos.library](../autodocs/dos.library.md#unloadseg)
