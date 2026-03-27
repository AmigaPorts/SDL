---
title: printer.device/PRD_DUMPRPORTTAGS
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-dumprporttags
functions: []
libraries: []
---

# printer.device/PRD_DUMPRPORTTAGS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_DUMPRPORTTAGS -- dump the specified [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to a printer (V44)

   FUNCTION
	Print a rendition of the supplied [RastPort](autodocs-3.5/include-graphics-rastport-h.md), using the supplied
	[ColorMap](autodocs-3.5/include-graphics-view-h.md), position and scaling information, as specified in
	the printer preferences.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible.
	io_Command	[PRD_DUMPRPORT](autodocs-3.5/printer-device-prd-dumprport-2.md).
	io_Flags	IOB_QUICK set if quick I/O is possible.
	io_RastPort	ptr to a [RastPort](autodocs-3.5/include-graphics-rastport-h.md).
	io_ColorMap	ptr to a [ColorMap](autodocs-3.5/include-graphics-view-h.md).
	io_Modes	the 'modes' flag from a [ViewPort](autodocs-3.5/include-graphics-view-h.md) structure,
			(the upper word is reserved and should be zero).

			If you are running under version 36, or greater
			of graphics.library, it is recommended that
			you fill in "io_Modes" with the ULONG (32-bit)
			value returned from calling:

			ULONG ModeID = GetVPModeID(struct [ViewPort](autodocs-3.5/include-graphics-view-h.md) *);

			Doing so provides for upwards compatability with
			the new display modes available under V36
			(example: aspect ratio calculations for new
			display modes).

	io_SrcX		x offset into the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to start printing from.
	io_SrcY		y offset into the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to start printing from.
	io_SrcWidth	width of the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to print (from io_SrcX).
	io_SrcHeight	height of the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to print (from io_SrcY).
	io_DestCols	width of the printout in printer pixels.
	io_DestRows	height of the printout in printer pixels.
	io_Special	flag bits
	io_TagList	a list of tags to specify more parameters for the
			dump.

   TAGS
	DRPA_SourceHook	a pointer to struct [Hook](autodocs-3.5/include-utility-hooks-h.md) which is called to read
			the source data. io_RastPort and io_ColorMap are
			ignored and should be NULL.

			The hook is called with object == NULL and message
			is a pointer to struct [DRPSourceMsg](autodocs-3.5/include-devices-printer-h.md). It must read
			an array of source data.

			Each pixel of the array is an ULONG of form
			0x00RRGGBB.

			Some printer drivers have set PPCB_NOSTRIPE which
			means they cannot print in stripes. Using
			DRPA_SourceHook is the best way for printing for such
			printers because you can still prepare the printer
			source data in stripes then.

			The Source [Hook](autodocs-3.5/include-utility-hooks-h.md) is always called in the context of
			the printer driver DOS process.

	DRPA_AspectX	the X aspect ratio.
	DRPA_AspectY	the Y aspect ratio. This values overwrites the
			aspect ratio from [GfxBase](autodocs-3.5/include-graphics-gfxbase-h.md) or io_Modes and is used
			for scaling.

