# dos.library/SetVBuf



   NAME
	SetVBuf -- set buffering modes and size (V39)

   SYNOPSIS
	error = SetVBuf(fh, buff, type, size)
	D0		D1   D2    D3    D4

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SetVBuf(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), LONG)

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
	by [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html).

   INPUTS
	fh   - Filehandle
	buff - buffer pointer for buffered I/O or NULL.  MUST be LONG-aligned!
	type - buffering mode (see [<dos/stdio.h>](../Includes_and_Autodocs_3._guide/node065A.html))
	size - size of buffer for buffered I/O (sizes less than 208 bytes
	       will be rounded up to 208), or -1.

   RESULT
	error - 0 if successful.  NOTE: opposite of most dos functions!
		NOTE: fails if someone has replaced the buffer without
		using SetVBuf() - [RunCommand()](../Includes_and_Autodocs_3._guide/node01AA.html) does this.  [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) to
		check error before freeing user-supplied buffers!

   BUGS
	Not implemented until after V39.  From V36 up to V39, always
	returned 0.

   SEE ALSO
	FputC(), [FGetC()](../Includes_and_Autodocs_3._guide/node0162.html), [UnGetC()](../Includes_and_Autodocs_3._guide/node01C6.html), [Flush()](../Includes_and_Autodocs_3._guide/node016A.html), [FRead()](../Includes_and_Autodocs_3._guide/node016E.html), [FWrite()](../Includes_and_Autodocs_3._guide/node0173.html), [FGets()](../Includes_and_Autodocs_3._guide/node0163.html),
	[FPuts()](../Includes_and_Autodocs_3._guide/node016D.html), [AllocDosObject()](../Includes_and_Autodocs_3._guide/node013E.html)

