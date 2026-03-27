---
title: diskfont.library/AvailFonts
manual: autodocs-3.5
chapter: autodocs-3.5
section: diskfont-library-availfonts-2
functions: []
libraries: []
---

# diskfont.library/AvailFonts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	[AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) -- Inquire available memory & disk fonts.

   SYNOPSIS
	error = AvailFonts(buffer, bufBytes, flags);
	                   A0      D0        D1

	[LONG](autodocs-3.5/include-exec-types-h.md) AvailFonts( struct [AvailFontsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) *buffer, [LONG](autodocs-3.5/include-exec-types-h.md) bufBytes
		ULONG flags );

   FUNCTION
	[AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) fills a user supplied buffer with the structure,
	described below, that contains information about all the
	fonts available in memory and/or on disk.  Those fonts
	available on disk need to be loaded into memory and opened
	via [OpenDiskFont](autodocs-3.5/diskfont-library-opendiskfont-2.md), those already in memory are accessed via
	[OpenFont](autodocs-3.5/graphics-library-openfont-2.md).  The [TextAttr](autodocs-3.5/include-graphics-text-h.md) structure required by the open calls
	is part of the information [AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) supplies.

	When [AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) fails, it returns the number of extra bytes
	it needed to complete the command.  Add this number to your
	current buffer size, allocate a new buffer, and try again.

   INPUTS
	buffer - memory to be filled with struct [AvailFontsHeader](autodocs-3.5/include-diskfont-diskfont-h.md)
		followed by an array of [AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) elements, which
		contains entries for the available fonts and their
		names.

	bufBytes - the number of bytes in the buffer
	flags - AFF_MEMORY is set to search memory for fonts to fill
		the structure, AFF_DISK is set to search the disk for
		fonts to fill the structure.  AFF_SCALED is set to
		not filter out memory fonts that are not designed.
		AFF_BITMAP is set to filter out fonts that are not
		stored in Amiga font format, i.e. to filter out
		outline fonts.  Any combination may be specified.
		AFF_TAGGED is set to fill the buffer with [TAvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md)
		elements instead of [AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) elements.

   RESULTS
	buffer - filled with struct [AvailFontsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) followed by the
		[T]AvailFonts elements, There will be duplicate entries
		for fonts found both in memory and on disk, differing
		only by type.  The existance of a disk font in the
		buffer indicates that it exists as an entry in a font
		contents file -- the underlying font file has not been
		checked for validity, thus an [OpenDiskFont](autodocs-3.5/diskfont-library-opendiskfont-2.md) of it may
		fail.
	error - if non-zero, this indicates the number of bytes needed
		for [AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) in addition to those supplied.  Thus
		structure elements were not returned because of
		insufficient bufBytes.

   EXAMPLE
	int afShortage, afSize;
	struct [AvailFontsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) *afh;

	...

	afSize = 400;
	do {
	    afh = (struct [AvailFontsHeader](autodocs-3.5/include-diskfont-diskfont-h.md) *) AllocMem(afSize, 0);
	    if (afh) {
	        afShortage = AvailFonts(afh, afSize, AFF_MEMORY|AFF_DISK);
	        if (afShortage) {
	            FreeMem(afh, afSize);
	            afSize += afShortage;
	        }
	    }
	    else {
	        fail("AllocMem of [AvailFonts](autodocs-3.5/include-diskfont-diskfont-h.md) buffer afh failedn");
	        break;
	    }
	}
	    while (afShortage);

	/*
	 * if (afh) non-zero here, then:
	 * 1. it points to a valid [AvailFontsHeader](autodocs-3.5/include-diskfont-diskfont-h.md)
	 * 2. it must have FreeMem(afh, afSize) called for it after use
	 */

