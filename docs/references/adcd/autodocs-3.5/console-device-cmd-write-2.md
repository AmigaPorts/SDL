---
title: console.device/CMD_WRITE
manual: autodocs-3.5
chapter: autodocs-3.5
section: console-device-cmd-write-2
functions: [DisplayBeep]
libraries: [intuition.library]
---

# console.device/CMD_WRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_WRITE -- [Write](autodocs-3.5/dos-library-write-2.md) ANSI text to the console display.

   FUNCTION
	[Write](autodocs-3.5/dos-library-write-2.md) a text record to the display.  Interpret the ANSI
	control characters in the data as described below.  Note
	that the RPort of the console window is in use while this
	write command is pending.

   IO REQUEST INPUT
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_WRITE
	io_Flags	IOF_QUICK if quick I/O possible, else zero
	io_Length	sizeof(*buffer), or -1 if io_Data is null
			terminated
	io_Data		a pointer to a buffer containing the ANSI text
			to write to the console device.

   IO REQUEST RESULTS
	io_Error	the error result (no errors are reported as of V36)
	io_Actual	the number of bytes written from io_Data
	io_Length	zero
	io_Data		original io_Data plus io_Actual

   ANSI CODES SUPPORTED

	Codes are specified in the standard fashion for ANSI documents,
	as the two 4 bit nibbles that comprise the character code,
	high nibble first, separated by a slash.  Thus 01/11 (ESC) is
	a character with the hex value 1B (or the decimal value 27).

	A character on the Amiga falls into one of the following four
	ranges:
	00/ 0-01/15	C0: ASCII control characters.  See below.
	02/ 0-07/15	G0: ASCII graphic characters.  These characters
			have an image that is displayed.  Note that the
			DEL character is displayed by the Console Device:
			it is not treated as control character here.
	08/ 0-09/15	C1: ANSI 3.41 control characters.  See below.
	10/ 0-15/15	G1: ECMA 94 Latin 1 graphic characters.

	Independent Control Functions (no introducer) --
	Code	Name	Definition
	-----	---	----------------------------------------------
	00/ 7	BEL	BELL: actually an Intuition [DisplayBeep()](autodocs-3.5/intuition-library-displaybeep-2.md)
	00/ 8	BS	BACKSPACE
	00/ 9	HT	HORIZONTAL TAB
	00/10	LF	LINE FEED
	00/11	VT	VERTICAL TAB
	00/12	FF	FORM FEED
	00/13	CR	CARRIAGE RETURN
	00/14	SO	SHIFT OUT: causes all subsequent G0 (ASCII)
			characters to be shifted to G1 (ECMA 94/1)
			characters.
	00/15	SI	SHIFT IN: cancels the effect of SHIFT OUT.
	01/11	ESC	ESCAPE

	Code or Esc Name Definition
	-----	--- ---- ---------------------------------------------
	08/ 4	D   IND	 INDEX: move the active position down one line.
	08/ 5	E   NEL	 NEXT LINE
	08/ 8	H   HTS  HORIZONTAL TABULATION SET
	08/13	M   RI	 REVERSE INDEX
	09/11	[   CSI	 CONTROL SEQUENCE INTRODUCER: see next list

	ISO Compatible Escape Sequences (introduced by Esc) --
	Esc   Name Definition
	----- ---- ---------------------------------------------------
	c     RIS  [RESET](autodocs-3.5/sad-reset.md) TO INITIAL STATE: reset the console display.

	Control Sequences, with the number of indicated parameters.
	i.e. <CSI><parameters><control sequence letter(s)>.  Note the
	last entries consist of a space and a letter.  CSI is either
	9B or Esc[.  A minus after the number of parameters (#p)
	indicates less is valid.  Parameters are separated by
	semicolons, e.g. Esc[14;80H sets the cursor position to row
	14, column 80.
	CSI #p	Name Definition
	--- --- ---- -------------------------------------------------
	@   1-	ICH  INSERT CHARACTER
	A   1-	CUU  CURSOR UP
	B   1-	CUD  CURSOR DOWN
	C   1-	CUF  CURSOR FORWARD
	D   1-	CUB  CURSOR BACKWARD
	E   1-	CNL  CURSOR NEXT LINE
	F   1-	CPL  CURSOR PRECEDING LINE
	H   2-	CUP  CURSOR POSITION
	I   1-	CHT  CURSOR HORIZONTAL TABULATION
	J   1-	ED   ERASE IN DISPLAY (only to end of display)
	K   1-	EL   ERASE IN LINE (only to end of line)
	L   1-	IL   INSERT LINE
	M   1-	DL   DELETE LINE
	P   1-	DCH  DELETE CHARACTER
	R   2	CPR  CURSOR POSITION REPORT (in [Read](autodocs-3.5/dos-library-read-2.md) stream only)
	S   1-	SU   SCROLL UP
	T   1-	SD   SCROLL DOWN
	W   n	CTC  CURSOR TABULATION CONTROL
	Z   1-	CBT  CURSOR BACKWARD TABULATION
	f   2-	HVP  HORIZONTAL AND VERTICAL POSITION
	g   1-	TBC  TABULATION CLEAR
	h   n	SM   SET MODE: see modes below.
	l   n	RM   [RESET](autodocs-3.5/sad-reset.md) MODE: see modes below.
	m   n	SGR  SELECT GRAPHIC RENDITION
	n   1-	DSR  DEVICE STATUS REPORT
	t   1-	aSLPP SET PAGE LENGTH (private Amiga sequence)
	u   1-	aSLL  SET LINE LENGTH (private Amiga sequence)
	x   1-	aSLO  SET LEFT OFFSET (private Amiga sequence)
	y   1-	aSTO  SET TOP OFFSET (private Amiga sequence)
	{   n	aSRE  SET RAW EVENTS (private Amiga sequence)
	|   8	aIER  INPUT EVENT REPORT (private Amiga [Read](autodocs-3.5/dos-library-read-2.md) sequence)
	}   n	aRRE  [RESET](autodocs-3.5/sad-reset.md) RAW EVENTS (private Amiga sequence)
	~   1	aSKR  SPECIAL KEY REPORT (private Amiga [Read](autodocs-3.5/dos-library-read-2.md) sequence)
	 p  1-	aSCR  SET CURSOR RENDITION (private Amiga sequence)
	 q  0	aWSR  WINDOW STATUS REQUEST (private Amiga sequence)
	 r  4	aWBR  WINDOW BOUNDS REPORT (private Amiga [Read](autodocs-3.5/dos-library-read-2.md) sequence)
	 s  0	aSDSS SET DEFAULT SGR SETTINGS (private Amiga sequence-V39)
	 v  1	aRAV  RIGHT AMIGA V PRESS (private Amiga [Read](autodocs-3.5/dos-library-read-2.md) sequence-V37)

	Modes, set with <CSI><mode-list>h, and cleared with
	<CSI><mode-list>l, where the mode-list is one or more of the
	following parameters, separated by semicolons --
	Mode	Name Definition
	------- ---- -------------------------------------------------
	20	LNM  LINEFEED NEWLINE MODE: if a linefeed is a newline
	>1	ASM  AUTO SCROLL MODE: if scroll at bottom of window
	?7	AWM  AUTO WRAP MODE: if wrap at right edge of window

    NOTES
	The console.device recognizes these SGR sequences.
	Note that some of these are new to V36.

	SGR (SELECT GRAPHICS RENDITION)
		Selects colors, and other display characteristics
		for text.

	Syntax:
		<ESC>[graphic-rendition...m

	Example:
		<ESC>[1;7m   (sets bold, and reversed text)

	Parameters:

		0	- Normal colors, and attributes
		1	- Set bold
		2	- Set faint (secondary color)
		3	- Set italic
		4	- Set underscore
		7	- Set reversed character/cell colors
		8	- Set concealed mode.
		22	- Set normal color, not bold	(V36)
		23	- Italic off			(V36)
		24	- Underscore off		(V36)
		27	- Reversed off			(V36)
		28	- Concealed off			(V36)

		30-37	- Set character color
		39	- Reset to default character color

		40-47	- Set character cell color
		49	- Reset to default character cell color

		>0-7	- Set background color		(V36)
			  Used to set the background color before
			  any text is written.  The numeric parameter
			  is prefixed by ">".  This also means that if
			  you issue an SGR command with more than one
			  parameter, you must issue the digit only
			  parameters first, followed by any prefixed
			  parameters.

	V39 console.device takes advantage of the ability to mask
	bitplanes for faster scrolling, clearing, and rendering.
	The actual number of bitplanes scrolled depends on which
	colors you set via the SGR sequences.  For those using
	the defaults of PEN color 1, and cell color 0, console.device
	only needs to scroll 1 bitplane.  The actual number
	of bitplanes scrolled is reset when ESCc is sent, and when
	the console window is entirely cleared (e.g., FF).  In
	general this should cause no compatability problems, unless
	you are mixing console rendering with graphic.library calls
	in the same portions of your window.  Console.device considers
	the number of bitplanes it must scroll, and the screen display
	depth so that interleaved bitplane scrolling can be taken
	advantage of in cases where performance is not significantly
	affected (interleaved scrolling, and masking are mutually
	exclusive).  The determination of how many planes to scroll
	is undefined, and may change in the future.

	V39 console.device supports a new private sequence (aSDSS)
	intended for use by users who prefer to change their default
	SGR settings.  When this private Amiga sequence is sent to the
	console, the current Pen color, Cell color, [Text](autodocs-3.5/graphics-library-text-2.md) style, and
	Reverse mode (on or off), are set as defaults.  When ESC[0m
	is issued, the settings are restored to the preferred settings.
	ESC[39m, and ESC[49m are likewise affected.  In general
	applications should not make use of this private sequence as it
	is intended for users who would normally include it as part of
	their shell startup script.  The normal defaults are reset
	when ESCc is issued.

    BUGS
	Does not correctly display cursor in SuperBitMap layers for
	versions prior to V36.

	Concealed mode should not be used prior to V39 console.device.
	Prior to V39 concealed mode masked all rastport output, the
	effect of which varied.  As of V39, text output is simply
	hidden by setting the pen colors.  Scrolling, clearing,
	cursor rendering, etc., are unaffected.  For maximum
	compatability it is recommended you simply set the colors
	yourself, and not used concealed mode.

	V36-V37 character mapped mode console.device windows could
	crash, or behave erratically if you scroll text DOWN more
	than a full window's worth of text.  This bug has been fixed
	in V39 console.  The only work-around is to avoid sending
	scroll down, or cursor up commands which exceed the window
	rows (this is not a problem for unit 0 console windows).

    SEE ALSO
	ROM Kernel Manual (Volume 1), [exec/io.h](autodocs-3.5/include-exec-io-h.md)

---

## See Also

- [DisplayBeep — intuition.library](../autodocs/intuition.library.md#displaybeep)
