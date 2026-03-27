# printer.device/PRD_DUMPRPORTTAGS



   NAME
	PRD_DUMPRPORTTAGS -- dump the specified [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to a printer (V44)

   FUNCTION
	Print a rendition of the supplied [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), using the supplied
	[ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142), position and scaling information, as specified in
	the printer preferences.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible.
	io_Command	[PRD_DUMPRPORT](../Includes_and_Autodocs_3._guide/node050C.html).
	io_Flags	IOB_QUICK set if quick I/O is possible.
	io_RastPort	ptr to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).
	io_ColorMap	ptr to a [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).
	io_Modes	the 'modes' flag from a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure,
			(the upper word is reserved and should be zero).

			If you are running under version 36, or greater
			of graphics.library, it is recommended that
			you fill in "io_Modes" with the ULONG (32-bit)
			value returned from calling:

			ULONG ModeID = GetVPModeID(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

			Doing so provides for upwards compatability with
			the new display modes available under V36
			(example: aspect ratio calculations for new
			display modes).

	io_SrcX		x offset into the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to start printing from.
	io_SrcY		y offset into the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to start printing from.
	io_SrcWidth	width of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to print (from io_SrcX).
	io_SrcHeight	height of the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to print (from io_SrcY).
	io_DestCols	width of the printout in printer pixels.
	io_DestRows	height of the printout in printer pixels.
	io_Special	flag bits
	io_TagList	a list of tags to specify more parameters for the
			dump.

   TAGS
	DRPA_SourceHook	a pointer to struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) which is called to read
			the source data. io_RastPort and io_ColorMap are
			ignored and should be NULL.

			The hook is called with object == NULL and message
			is a pointer to struct [DRPSourceMsg](../Includes_and_Autodocs_3._guide/node0605.html#line314). It must read
			an array of source data.

			Each pixel of the array is an ULONG of form
			0x00RRGGBB.

			Some printer drivers have set PPCB_NOSTRIPE which
			means they cannot print in stripes. Using
			DRPA_SourceHook is the best way for printing for such
			printers because you can still prepare the printer
			source data in stripes then.

			The Source [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) is always called in the context of
			the printer driver DOS process.

	DRPA_AspectX	the X aspect ratio.
	DRPA_AspectY	the Y aspect ratio. This values overwrites the
			aspect ratio from [GfxBase](../Includes_and_Autodocs_3._guide/node0612.html#line25) or io_Modes and is used
			for scaling.

