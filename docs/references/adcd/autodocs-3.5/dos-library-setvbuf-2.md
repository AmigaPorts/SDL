---
title: dos.library/SetVBuf
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setvbuf-2
functions: [AllocDosObject, FGetC, FGets, FPuts, FRead, FWrite, RunCommand, UnGetC]
libraries: [dos.library]
---

# dos.library/SetVBuf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetVBuf -- set buffering modes and size (V39)

   SYNOPSIS
	error = SetVBuf(fh, buff, type, size)
	D0		D1   D2    D3    D4

	[LONG](autodocs-3.5/include-exec-types-h.md) SetVBuf(BPTR, [STRPTR](autodocs-3.5/include-exec-types-h.md), [LONG](autodocs-3.5/include-exec-types-h.md), LONG)

   FUNCTION
	Changes the buffering modes and buffer size for a filehandle.
	With buff == NULL, the current buffer will be deallocated and a
	new one of (approximately) size will be allocated.  If buffer is
	non-NULL, it will be used for buffering and must be at least
	max(size,208) bytes long, and MUST be longword aligned.  If size
	is -1, then only the buffering mode will be changed.

	Note that a user-supplied buffer will not be freed if it is later
	replaced by another SetVBuf() call, nor will it be freed if the
	filehandle is closed.

	Has no effect on the buffersize of filehandles that were not created
	by [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md).

   INPUTS
	fh   - Filehandle
	buff - buffer pointer for buffered I/O or NULL.  MUST be LONG-aligned!
	type - buffering mode (see [<dos/stdio.h>](autodocs-3.5/include-dos-stdio-h.md))
	size - size of buffer for buffered I/O (sizes less than 208 bytes
	       will be rounded up to 208), or -1.

   RESULT
	error - 0 if successful.  NOTE: opposite of most dos functions!
		NOTE: fails if someone has replaced the buffer without
		using SetVBuf() - [RunCommand()](autodocs-3.5/dos-library-runcommand-2.md) does this.  [Remember](autodocs-3.5/include-intuition-intuition-h.md) to
		check error before freeing user-supplied buffers!

   BUGS
	Not implemented until after V39.  From V36 up to V39, always
	returned 0.

   SEE ALSO
	FputC(), [FGetC()](autodocs-3.5/dos-library-fgetc-2.md), [UnGetC()](autodocs-3.5/dos-library-ungetc-2.md), [Flush()](autodocs-3.5/dos-library-flush-2.md), [FRead()](autodocs-3.5/dos-library-fread-2.md), [FWrite()](autodocs-3.5/dos-library-fwrite-2.md), [FGets()](autodocs-3.5/dos-library-fgets-2.md),
	[FPuts()](autodocs-3.5/dos-library-fputs-2.md), [AllocDosObject()](autodocs-3.5/dos-library-allocdosobject-2.md)

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FGets — dos.library](../autodocs/dos.library.md#fgets)
- [FPuts — dos.library](../autodocs/dos.library.md#fputs)
- [FRead — dos.library](../autodocs/dos.library.md#fread)
- [FWrite — dos.library](../autodocs/dos.library.md#fwrite)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [UnGetC — dos.library](../autodocs/dos.library.md#ungetc)
