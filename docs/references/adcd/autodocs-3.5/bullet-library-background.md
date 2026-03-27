---
title: bullet.library/--background--
manual: autodocs-3.5
chapter: autodocs-3.5
section: bullet-library-background
functions: [OpenLibrary]
libraries: [exec.library]
---

# bullet.library/--background--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   AMIGA FONTS
	The existence of a disk font is indicated by the existence of
	its associated font contents file, whose name has the suffix
	".font".  It is this name that is used in the actual font
	open call of the application.  Amiga fonts are collected in
	the directory path(s) associated with the FONTS: assign.  It
	is this assign that is searched if no explicit path name is
	provided in the font open call: use of an explicit path is
	generally discouraged.  The actual bitmaps of traditional
	Amiga fonts are stored in a directory with the name of the
	font contents file stripped of its ".font" suffix.  This
	directory is usually in the same directory as the font
	contents file.  This traditional arrangement is supported by
	the FixFonts system application.

	For example:
	    o   FONTS: is assigned to Sys:Fonts/
	    o   Sys:Fonts/garnet.font exists and describes that the
		font "garnet.font" exists
	    o   Sys:Fonts/garnet/ contains the bitmap images for
		sizes 9 and 16

	Other variations of file placement may exist, but they
	require custom tools to maintain -- tools available not from
	Commodore, but from other sources such as Fish disks.

	Font contents files are flagged with magic numbers that not
	only verify that they are a font contents files but also what
	variation of file structure they contain.

   OUTLINE TYPEFACES
	The existence of an outline typeface is indicated by a magic
	number in the font contents file.  They are further described
	in the associated outline typeface tag file, whose name is
	the that of the font contents file with the suffix ".otag"
	substituted for ".font".  This tag file contains a tag list
	that is to be processed and passed to the outline engine
	(i.e.  bullet.library) in order to select the associated
	typeface.  It also contains information applications may use
	to guide their use of the typeface.

   OTAG SPECIFICATION EXAMPLE
	Here are the steps necessary to go from an arbitrary font
	name into an environment where glyphs from that font
	can be accessed:
	1.  [Read](autodocs-3.5/dos-library-read-2.md) the header from the font contents (.font) file and
	    verify that the magic cookie fch_ID is OFCH_ID.
	    If it is not, then this is an Amiga bitmap font,
	    not an outline font.
	2.  [Read](autodocs-3.5/dos-library-read-2.md) the associated outline tag (.otag) file into memory:
	    a.  Validate that the OT_FileIdent exists and matches the
		file size.
	    b.  [Allocate](autodocs-3.5/exec-library-allocate-2.md) a memory buffer and read the file into it.
	    c.  Resolve addresses: for each tag with the OT_Indirect
		bit set, add the memory buffer origin to the
		associated data.
	3.  Find the OT_Engine tag and ensure that you have the
	    proper engine open:
	    a.  If you already have an engine handle for this engine
		name, you skip these steps.
	    b.  append the suffix ".library" to the engine name.
		(e.g. "bullet" becomes "bullet.library").
	    c.  use exec's [OpenLibrary()](autodocs-3.5/exec-library-openlibrary-2.md) to open the library.
	    d.  use the engine's [OpenEngine()](autodocs-3.5/bullet-library-openengine.md) to acquire an engine
		handle.
	4.  Pass the full path name of the .otag file to the engine
	    with the OT_OTagPath tag using SetInfo().
	5.  Pass the memory copy of the .otag file to the engine with
	    the OT_OTagList tag using SetInfo().  This step may be
	    combined with step 4, passing first the path then the
	    list in one call.
	The library is now ready to accept glyph metric information
	(e.g. size and glyph code) and produce glyph bitmaps.

   DISKFONT USE OF OTAG ENTRIES
	The diskfont library uses other entries from the outline tag
	(.otag) file.  The following are used both during inquiry of
	what typefaces exist (AvailFonts) and during creation of an
	Amiga [TextFont](autodocs-3.5/include-graphics-text-h.md) (OpenDiskFont):
	o   OT_IsFixed is used to determine whether these outlines
	    describe a PROPORTIONAL flagged font.
	o   OT_StemWeight is used to determine whether these outlines
	    describe a BOLD style font.
	o   OT_SlantStyle is used to determine whether these outlines
	    describe an ITALIC style font.
	o   OT_HorizStyle is used to determine whether these outlines
	    describe an EXTENDED style font.
	The following are used only during OpenDiskFont:
	o   OT_YSizeFactor is used to convert the Amiga pixel height
	    specification, which describes the distance from the
	    lowest decender to the highest ascender, into a point
	    size specification, which is related (via YSizeFactor)
	    to a nominal character height.
	o   OT_SpaceWidth is used as the width of the space character.
	The following is used only during AvailFonts:
	o   OT_AvailSizes is used to generate a list of sizes
	    available for the font.

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
