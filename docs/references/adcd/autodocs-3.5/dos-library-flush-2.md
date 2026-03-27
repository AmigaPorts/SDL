---
title: dos.library/Flush
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-flush-2
functions: [Close, CreateNewProc, FGetC, RunCommand, SelectInput, UnGetC]
libraries: [dos.library]
---

# dos.library/Flush

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Flush -- Flushes buffers for a buffered filehandle (V36)

   SYNOPSIS
	success = Flush(fh)
	D0		D1

	[LONG](autodocs-3.5/include-exec-types-h.md) Flush(BPTR)

   FUNCTION
	Flushes any pending buffered writes to the filehandle.  All buffered
	writes will also be flushed on [Close()](autodocs-3.5/dos-library-close-2.md).  If the filehandle was being
	used for input, it drops the buffer, and tries to [Seek()](autodocs-3.5/dos-library-seek-2.md) back to the
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
	input and then calling [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md) with NP_Arguments, or when
	using a new filehandle with [SelectInput()](autodocs-3.5/dos-library-selectinput-2.md) and then calling
	[RunCommand()](autodocs-3.5/dos-library-runcommand-2.md).  This is fixed in V39.  A workaround would be to
	do [FGetC()](autodocs-3.5/dos-library-fgetc-2.md), then [UnGetC()](autodocs-3.5/dos-library-ungetc-2.md), then Flush().

   SEE ALSO
	FputC(), [FGetC()](autodocs-3.5/dos-library-fgetc-2.md), [UnGetC()](autodocs-3.5/dos-library-ungetc-2.md), [Seek()](autodocs-3.5/dos-library-seek-2.md), [Close()](autodocs-3.5/dos-library-close-2.md), [CreateNewProc()](autodocs-3.5/dos-library-createnewproc-2.md),
	[SelectInput()](autodocs-3.5/dos-library-selectinput-2.md), [RunCommand()](autodocs-3.5/dos-library-runcommand-2.md)

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [CreateNewProc — dos.library](../autodocs/dos.library.md#createnewproc)
- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [SelectInput — dos.library](../autodocs/dos.library.md#selectinput)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
