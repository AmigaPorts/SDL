---
title: graphics.library/BltClear
manual: autodocs-3.5
chapter: autodocs-3.5
section: graphics-library-bltclear-2
functions: []
libraries: []
---

# graphics.library/BltClear

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME   

	BltClear - Clear a block of memory words to zero.

   SYNOPSIS
	BltClear( memBlock, bytecount, flags )
		    a1         d0       d1

	void BltClear( void *, ULONG, ULONG );

   FUNCTION
	For memory that is local and blitter accessible, the most
	efficient way to clear a range of memory locations is

       to use the system's most efficient data mover, the blitter.
       This command accepts the starting location and count and clears
       that block to zeros.
   INPUTS
	memBloc	- pointer to local memory to be cleared
		  memBlock is assumed to be even.
	flags	- set bit 0 to force function to wait until
		  the blit is done.
		  set bit 1 to use row/bytesperrow.

	bytecount - if (flags & 2) == 0 then
				even number of bytes to clear.
			else
				low 16 bits is taken as number of bytes
				per row and upper 16 bits taken as
				number of rows.

	This function is somewhat hardware dependent. In the rows/bytesperrow
	mode (with the pre-ECS blitter) rows must be <- 1024. In bytecount mode
	multiple runs of the blitter may be used to clear all the memory.

	Set bit 2 to use the upper 16 bits of the Flags as the data to fill
	memory with instead of 0 (V36).

   RESULT
	The block of memory is initialized.

   BUGS

   SEE ALSO

