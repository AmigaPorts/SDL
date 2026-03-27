---
title: printer.device/PRD_DUMPRPORT
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-dumprport-2
functions: []
libraries: []
---

# printer.device/PRD_DUMPRPORT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_DUMPRPORT -- dump the specified [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to a graphics printer

   FUNCTION
	Print a rendition of the supplied [RastPort](autodocs-3.5/include-graphics-rastport-h.md), using the supplied
	[ColorMap](autodocs-3.5/include-graphics-view-h.md), position and scaling information, as specified in
	the printer preferences.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible.
	io_Command	PRD_DUMPRPORT.
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
			(some of which pertain to DestCols and DestRows).
			-if SPECIAL_MIL is set, then the associated
			 parameter is specified in thousandths of
			 an inch on the printer.  ie. if DestCols = 8000,
			 DestRows = 10500 and SPECIAL_MILROWS and
			 SPECIAL_MILCOLS is set then the printout would be
			 8.000 x 10.500 inches.
			-if SPECIAL_FULL is set, then the specific dimension
			 is set to the maximum possible as determined
			 by the printer limits or the configuration
			 limits; whichever is less.
			-if SPECIAL_FRAC is set, the parameter is
			 taken to be a longword binary fraction
			 of the maximum for that dimension.
			-if all bits for a dimension are clear,
			 (ie. SPECIAL MIL/FULL/FRAC and ASPECT are NOT set)
			 then the parameter is specified in printer pixels.
			-if SPECIAL_CENTER is set then the image will be
			 put between the left and right edge of the paper.
			-if SPECIAL_ASPECT is set, one of the dimensions
			 may be reduced/expanded to preserve the aspect
			 ratio of the print.
			-SPECIAL_DENSITY(1-7) this allows for a maximum of 7
			 different print densities.  DENSITY1 is the lowest
			 density and the default.
			-SPECIAL_NOFORMFEED - this allows for the mixing of
			 text and graphics or multiple graphic dumps on page
			 oriented printers (usually laser jet printers).
			 When this flag is set the page will not be ejected
			 after a graphic dump.  If you perform another
			 graphic dump without this flag set OR close the
			 printer after printing text after a graphic dump,
			 the page will be ejected.
			-if SPECIAL_TRUSTME is set then the printer specific
			 driver is instructed to not issue a reset command
			 before and after the dump.  If this flag is NOT
			 checked by the printer specific driver then setting
			 this flag has no effect.  Since we now recommend
			 that printer driver writers no longer issue a reset
			 command it is probably a safe idea to always set
			 this flag when calling for a dump.
			-if SPECIAL_NOPRINT is set then the following is done:
			 Compute print size, set 'io_DestCols' and
			 'io_DestRows' in the calling program's 'IODRPReq'
			 structure and exit, DON'T PRINT.  This allows the
			 calling program to see what the final print size
			 would be in printer pixels.  Note that it modifies
			 the 'io_DestCols' and 'io_DestRows' fields of your
			 'IODRPReq' structure.  It also sets the print
			 density and updates the 'MaxXDots', 'MaxYDots',
			 'XDotsInch', and 'YDotsInch' fields of the
			 'PrinterExtendedData' structure.

	There following rules for the interpretation of io_DestRows and
	io_DestCols that may produce unexpected results when they are
	not greater than zero and io_Special is zero.  They have been
	retained for compatability.  The user will not trigger these
	other rules with well formed usage of io_Special.

	When io_Special is equal to 0, the following rules
	(from the V1.1 printer.device, and retained for compatibility
	reasons) take effect.  [Remember](autodocs-3.5/include-intuition-intuition-h.md), these special rules are
	for io_DestRows and io_DestCols and only take effect
	if io_Special is 0).

	a) DestCols>0 & DestRows>0 - use as absolute values.
	   ie. DestCols=320 & DestRows=200 means that the picture
	   will appear on the printer as 320x200 dots.
	b) DestCols=0 & DestRows>0 - use the printers maximum number
	   of columns and print DestRows lines. ie. if DestCols=0
	   and DestRows=200 than the picture will appear on the
	   printer as wide as it can be and 200 dots high.
	c) DestCols=0 & DestRows=0 - same as above except the driver
	   determines the proper number of lines to print based on
	   the aspect ratio of the printer. ie. This results in the
	   largest picture possible that is not distorted or inverted.
	   Note: As of this writing, this is the call made by such
	   program as DeluxePaint, GraphicCraft, and AegisImages.
	d) DestCols>0 &DestRows=0 - use the specified width and the
	   driver determines the proper number of lines to print based
	   on the aspect ratio of the printer. ie. if you desire a
	   picture that is 500 pixels wide and aspect ratio correct,
	   use DestCols=500 and DestRows=0.
	e) DestCols<0 or DestRows>0 - the final picture is either a
	   reduction or expansion based on the fraction
	   |DestCols| / DestRows in the proper aspect ratio.
	   Some examples:
	   1) if DestCols=-2 & DestRows=1 then the printed picture will
	      be 2x the AMIGA picture and in the proper aspect ratio.
	      (2x is derived from |-2| / 1 which gives 2.0)
	   2) if DestCols=-1 & DestRows=2 then the printed picture will
	      will be 1/2x the AMIGA picture in the proper aspect ratio.
	      (1/2x is derived from |-1| / 2 which gives 0.5)

   NOTES
	The printer selected in preferences must have graphics
	capability to use this command.  The error 'PDERR_NOTGRAPHICS'
 	is returned if the printer can not print graphics.

	Color printers may not be able to print black and white or
	greyscale pictures -- specifically, the Okimate 20 cannot print
	these with a color ribbon: you must use a black ribbon instead.
	If the printer has an input buffer option, use it.
	If the printer can be uni or bi directional, select
	uni-directional; this produces a much cleaner picture.
	Most printer drivers will attempt to set unidirectional
	printing if it is possible under software control.

	Please note that the width and height of the printable area on
	the printer is in terms of pixels and bounded by the following:
	 a) WIDTH = (RIGHT_MARGIN - LEFT_MARGIN + 1) / CHARACTERS_PER_INCH
	 b) HEIGHT = LENGTH / LINES_PER_INCH
	Margins are set by preferences.

	For BGR printer support, the YMC values in the printer
	specific render.c functions equate to BGR respectively, ie.
	yellow is blue, magenta is green, and cyan is red.

	For version 2.1 of the Operating System (the Localization
	release), some of the printer drivers have been modified to
	support European A size paper (e.g., "A4").  See preferences.h
	for a list of defined sizes.  For most printers, this means
	the maximum X dots will be calculated based on millimeters
	minus 1/2 inch (approx 13 mm) - this is consistent with existing
	driver calculations (e.g., 8.0 inches wide for US_LETTER, and
	US_LEGAL sizes).

	Some printers, like the HP_LaserJet, and HP_DeskJet also
	calculate maximum Y dots.

	For all modified printer drivers, selecting paper sizes larger
	than the printer can handle may result in unexpected, or
	clipped results.  This allows for the possibility of using
	these drivers with future printers which may physically
	[and internally] support these larger sizes of paper.

	It is assumed that the user will make reasonable choices when
	selecting paper size (e.g., not select WIDE TRACTOR for a
	NARROW TRACTOR printer).

 Data Structures
 ---------------

	The printer specific and non-specific data structures can be read
	ONCE you have opened the printer device.  Here is a code fragment
	to illustrate how to do just that.

	#include [<exec/types.h>](autodocs-3.5/include-exec-types-h.md)
	#include [<devices/printer.h>](autodocs-3.5/include-devices-printer-h.md)
	#include [<devices/prtbase.h>](autodocs-3.5/include-devices-prtbase-h.md)
	#include [<devices/prtgfx.h>](autodocs-3.5/include-devices-prtgfx-h.md)

	struct [IODRPReq](autodocs-3.5/include-devices-printer-h.md) PReq;
	struct [PrinterData](autodocs-3.5/include-devices-prtbase-h.md) *PD;
	struct [PrinterExtendedData](autodocs-3.5/include-devices-prtbase-h.md) *PED;

   open the printer device / if it opened...
   if (OpenDevice("printer.device", 0, &PReq, 0) == NULL) {
```c
       get pointer to printer data
       PD = (struct [PrinterData](autodocs-3.5/include-devices-prtbase-h.md) *)PReq.io_Device;
       get pointer to printer extended data
       PED = &PD->pd_SegmentData->ps_PED;
       let's see what's there
       printf("PrinterName = '%s', Version=%u, Revision=%un",
           PED->ped_PrinterName, PD->pd_SegmentData->ps_Version,
           PD->pd_SegmentData->ps_Revision,);
       printf("PrinterClass=%u, ColorClass=%un",
           PED->ped_PrinterClass, PED->ped_ColorClass);
       printf("MaxColumns=%u, NumCharSets=%u, NumRows=%un",
           PED->ped_MaxColumns, PED->ped_NumCharSets, PED->ped_NumRows);
       printf("MaxXDots=%lu, MaxYDots=%lu, XDotsInch=%u, YDotsInch=%un",
           PED->ped_MaxXDots, PED->ped_MaxYDots,
           PED->ped_XDotsInch, PED->ped_YDotsInch);
       CloseDevice(&PReq);
```
   }

 [Preferences](autodocs-3.5/include-intuition-preferences-h.md)
 -----------

    If you want the user to be able to access the printer preferences items
 without having to run preferences (like DPAINT II's printer requester),
 here is what you do.  You can look at the printer's copy of preferences
 by referring to 'PD->pd_Preferences' (the printer device MUST already be
 opened at this point).  After you have this you could put up a requester
 and allow the user to change whatever parameters they wanted.
 BEAR IN MIND THAT YOU ARE RESPONSIBLE FOR RANGE CHECKING THESE SELECTIONS!
 Listed below are the printer preferences items and their valid values.

 PrintPitch         - PICA, ELITE, FINE.
 PrintQuality       - DRAFT, LETTER.
 PrintSpacing       - SIX_LPI, EIGHT_LPI.
 PrintLeftMargin    - 1 to PrintRightMargin.
 PrintRightMargin   - PrintLeftMargin to 999.
 PaperLength        - 1 to 999.
 PrintImage         - IMAGE_POSITIVE, IMAGE_NEGATIVE.
 PrintAspect        - ASPECT_HORIZ, ASPECT_VERT.
 PrintShade         - SHADE_BW, SHADE_GREYSCALE, SHADE_COLOR.
 PrintThreshold     - 1 to 15.
 PrintFlags         - CORRECT_RED, CORRECT_GREEN, CORRECT_BLUE, CENTER_IMAGE,
                      IGNORE_DIMENSIONS, BOUNDED_DIMENSIONS,
                      ABSOLUTE_DIMENSIONS, PIXEL_DIMENSIONS,
                      MULTIPLY_DIMENSIONS, INTEGER_SCALING,
                      ORDERED_DITHERING, HALFTONE_DITHERING.
                      FLOYD_DITHERING, ANTI_ALIAS, GREY_SCALE2
 PrintMaxWidth      - 0 to 65535.
 PrintMaxHeight     - 0 to 65535.
 PrintDensity       - 1 to 7.
 PrintXOffset       - 0 to 255.

 Asynchronous I/O
 ----------------


     The recommended way to do asynchronous i/o is...
 a) To send requests for i/o.


```c
     struct [IORequest](autodocs-3.5/include-exec-io-h.md) *ioreq;
     struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *port;
     [UBYTE](autodocs-3.5/include-exec-types-h.md) signal;

     port = ioreq->io_Message.mn_ReplyPort;
     signal = port->mp_SigBit;

     SendIO(ioreq);  send request
     Wait(signal);  wait for completion (go to sleep)
     while ((Msg = GetMsg(port)) != NULL) {  get ALL messages
     }
```
 b) To abort a previous request for i/o.



```c
     struct [IORequest](autodocs-3.5/include-exec-io-h.md) *ioreq;

     AbortIO(ioreq);  abort request
     WaitIO(ioreq);  wait for reply

     at this point you can re-use 'ioreq'.

     Note that in the above examples 'ioreq' could be any one of...
     a) struct [IOStdReq](autodocs-3.5/include-exec-io-h.md)    a standard i/o request
     b) struct [IODRPReq](autodocs-3.5/include-devices-printer-h.md)    a dumprport i/o request
     c) struct [IOPrtCmdReq](autodocs-3.5/include-devices-printer-h.md) a printer command i/o request

     It is recommend that you do asynchronous i/o in your programs
     and give the user a way of aborting all requests.
```
 		V1.3 Printer Driver Notes
 		-------------------------

 	In general densities which use more than one pass should only be
 used for B&W shade dumps.  They can be used for Grey-Scale or Color Shade
 dumps BUT the output may tend to look muddy or dark.  Also multiple pass
 Color dumps tend to dirty or smear the ribbon (ie. yellow will get
 contaminated with the other colors on the ribbon; you have been warned).


 Alphacom_AlphaPro_101
 ---------------------
 1. Daisywheel printer (text only).

 Brother_HR-15XL
 ---------------
 1. Daisywheel printer (text only).

 CalComp_ColorMaster
 -------------------
 1. Thermal transfer b&w/color printer (text and graphics).
 2. Use Black ribbon for non-color dumps; Color ribbon for color dumps.
 3. Linefeeds # of vertical dots printed.
 4. Densities supported are 203x200(1) dpi.
 5. This is a dual printer driver.  Select a PaperSize of 'Narrow Tractor'

```c
    for use with the ColorMaster; 'Wide Tractor' for use with the
    ColorView-5912 (which uses 11 x 17 inch paper).
```
 CalComp_ColorMaster2
 -------------------
 1. Thermal transfer b&w/color printer (text and graphics).
 2. Use Black ribbon for non-color dumps; Color ribbon for color dumps.
 3. Linefeeds # of vertical dots printed.
 4. Densities supported are 203x200(1) dpi.
 5. This is a dual printer driver.  Select a PaperSize of 'Narrow Tractor'
```c
    for use with the ColorMaster; 'Wide Tractor' for use with the
    ColorView-5912 (which uses 11 x 17 inch paper).
```
 6. This driver is the same as the Calcomp_ColorMaster driver EXCEPT it is

```c
    approximately 2 times faster (during color dumps) and requires LOTS of
    memory (up to 1,272,003 bytes for a full 8 x 10 inch (1600 x 2000 dot)
    color dump).  Typically full-size (color) dumps are 1600 x 1149 dots and
    require 730,767 bytes.  Memory requirements for the ColorView-5912
    are up to 2,572,803 bytes for a full 10 x 16 inch (2048 x 3200 dot)
    color dump.  Typically full-size (color) dumps are 2048 x 2155 dots and
    require 1,732,623 bytes.  The memory requirements are 1/3 when doing a
    non-color printout (on both the ColorMaster and ColorView).
```
 Canon_PJ-1080A
 --------------
 1. Ink jet b&w/color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Densities supported are 83x84(1) dpi.

 CBM_MPS1000
 -----------
 1. Dot matrix b&w printer (text and graphics).
 2. Linefeeds # of vertical dots printed (-1/3 dot if PaperType = Single). *2
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	120	 72	 8640
 	2	120	144	17280	two pass
 	3	240	 72	17280			*1
 	4	120	216	25920	three pass
 	5	240	144	34560	two pass	*1
 	6	240	216	51840	three pass	*1
 	7	same as 6
 4. Print width for US_LETTER size paper is 8.0 inches.
 5. As of version 35.48, this driver calculates maximum X dots for

    European A size paper as defined in preferences.h.  Some of
    these sizes are too large for this printer.
 Diablo_630
 ----------
 1. Daisywheel printer (text only).

 Diablo_Advantage_D25
 --------------------
 1. Daisywheel printer (text only).

 Diablo_C-150
 ------------
 1. Ink jet b&w/color printer (text and graphics).
 2. Always linefeeds 4 dots (limitation of printer).
 3. A PaperSize of 'Wide Tractor' selects a maximum print width of
```c
    8.5 inches (for wide roll paper).
```
 5. Densities supported are 120x120(1) dpi.

 EpsonQ (24-pin Epson compatible)
 ------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Drives all EpsonQ (LQ1500, LQ2500, etc.) compatible printers.
 3. Linefeeds # of vertical dots printed.
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	 90	180	16200
 	2	120	180	21600
 	3	180	180	32400
 	4	360	180	64800	*1
 	5,6,7	same as 4
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of
```c
    13.6 inches (for wide carriage printers).
```
 6. A PaperType of 'Single' uses only 16 of the 24 pins, whereas a PaperType
    of 'Fanfold' uses all 24 pins.  The 'Single' option is useful for those
    printers which have a weak power supply and cannot drive all 24 pins
    continuously.  If during a single pass of the print head you notice that
    the top two thirds of the graphics are darker than the bottom one third
    then you will probably need to drop down to 16 pins.
 7. As of version 35.71, this driver calculates maximum X dots for

```c
    European A size paper as defined in preferences.h.  The calculation
    is based on millimeters minus 1/2 inch (approx 13mm).  Maximum
    paper width is 13.6 inches, so some European A sizes are too large
    for this printer.
```
 EpsonX[CBM_MPS-1250] (8/9-pin Epson compatible)
 --------------------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Drives all EpsonX (EX/FX/JX/LX/MX/RX, etc.) compatible printers.
 3. Linefeeds # of vertical dots printed (-1/3 dot if PaperType = Single). *2
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	120	 72	 8640
 	2	120	144	17280	two pass
 	3	240	 72	17280			*1
 	4	120	216	25920	three pass
 	5	240	144	34560	two pass	*1
 	6	240	216	51840	three pass	*1
 	7	same as 6

 5. A PaperSize of 'Wide Tractor' selects a maximum print width of
```c
    13.6 inches (for wide carriage printers).
```
 6. Use this driver if you own a CBM_MPS-1250 (as it is EpsonX compatible).
 7. As of version 35.42, this driver calculates maximum X dots for

```c
    European A size paper as defined in preferences.h.  The calculation
    is based on millimeters minus 1/2 inch (approx 13mm).  Maximum
    paper width is 13.6 inches, so some European A sizes are too large
    for this printer.
```
 EpsonXOld (8/9-pin Epson compatible)
 ---------
 1. Dot matrix b&w printer (text and graphics).
 2. Drives all very old EpsonX (EX/FX/JX/LX/MX/RX, etc.) compatible printers.
 3. Linefeeds # of vertical dots printed.
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	 60	72	 4320
 	2	120	72	 8640	(double speed)			*1
 	3	120	72	 8640
 	4	240	72	17280					*1
 	5	120	72	 8640	(for use on old Star printers)
 	6	240	72	17280	(for use on old Star printers)	*1
 	7	240	72	17280	(same as density 4)		*1
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of
```c
    13.6 inches (for wide carriage printers).
```
 6. Use this driver if the EpsonX driver does not work properly in graphics

    or text mode on your EpsonX compatible printer.
 generic
 -------
 1. [Text](autodocs-3.5/graphics-library-text-2.md) only printer.

 Howtek_Pixelmaster
 ------------------
 1. Plastic ink jet b&w/color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	 80	 80	 6400
 	2	120	120	14400
 	3	160	160	25600
 	4	240	240	57600
 	5,6,7	same as 4
 4. Maximum print area is 8.0 x 10.0 inches.

 HP_DeskJet
 ----------
 1. Ink jet non-color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	 75	 75	 5625
 	2	100	100	10000
 	3	150	150	22500
 	4	300	300	90000
 	5,6,7	same as 4
 4. Maximum print area is 8.0 x 10.0 inches US_LEGAL, and 8.0 x
    13.0 inches US_LETTER.
 5. As of version 35.29, the driver will calculate maximum area
```c
    size for European A size paper as defined in preferences.h.
    The driver calculates the maximum X, and Y dots based on
    millimeters, minus 1/2 inch from the width, and minus 1"
    from the height (approx 13mm, and 26mm respectively).
    Therefore the margin area is consistent with US paper sizes.
```
 6. Some European A sizes are too large for this printer.

 HP_LaserJet (LaserJet+/LaserJetII compatible)
 -----------
 1. Laser engine non-color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	 75	 75	 5625
 	2	100	100	10000
 	3	150	150	22500
 	4	300	300	90000
 	5,6,7	same as 4
 4. Maximum print area is 8.0 x 10.0 inches US_LEGAL, and 8.0 x
    13.0 inches US_LETTER.
 5. As of version 35.59, the driver will calculate maximum area
```c
    size for European A size paper as defined in preferences.h.
    The driver calculates the maximum X, and Y dots based on
    millimeters, minus 1/2 inch from the width, and minus 1"
    from the height (approx 13 mm, and 26 mm respectively).
    Therefore the margin area is consistent with US paper sizes.
```
 6. Some European A sizes are too large for this printer.

 HP_PaintJet
 -----------
 1. Ink jet b&w/color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Densities supported are 180x180(1) dpi.

 HP_ThinkJet
 ----------
 1. Ink jet non-color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	 96	96	 9216
 	2	192	96	18432
 	3,4,5,6,7	same as 4
 4. This printer prints 640 dots X in 96 DPI mode, and 120 dots

    X in 192 DPI mode.  Other sizes are not supported by the
    printer.
 Imagewriter II (Imagewriter compatible)
 --------------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	 80	 72	 5760
 	2	120	 72	 8640
 	3	144	 72	10368
 	4	160	 72	11520
 	5	120	144	17280	two pass
 	6	144	144	20736	two pass
 	7	160	144	23040	two pass

 Nec_Pinwriter (24-wire Pinwriter compatible (P5/P6/P7/P9/P2200))
 -------------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Drives all NEC 24-wire Pinwriter compatible printers.
 3. Linefeeds # of vertical dots printed.
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	 90	180	 16200
 	2	120	180	 21600
 	3	180	180	 32400
 	4	120	360	 43200	two pass
 	5	180	360	 64800	two pass
 	6	360	180	 64800
 	7	360	360	129600	two pass
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of
```c
    13.6 inches (for wide carriage printers).
```
 6. As of version 35.17, this driver calculates maximum X dots for

```c
    European A size paper as defined in preferences.h.  The calculation
    is based on millimeters minus 1/2 inch (approx 13mm).  Maximum
    paper width is 13.6 inches, so some European A sizes are too large
    for this printer.
```
 Okidata_92
 ----------
 1. Dot matrix non-color printer (text and graphics).
 2. Always linefeeds 7/72 inch (limitation of printer in graphics mode).
 3. Densities supported are 72x72 dpi.

 Okidata_293I
 ------------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Drives 292 or 293 using the IBM interface module.
 3. Linefeeds # of vertical dots printed (-1/2 dot if PaperType = Single) *3
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	120	144	17280
 	2	240	144	34560
 	3	120	288	34560	two pass
 	4	240	288	69120	two pass
 	5,6,7	same as 4
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of

```c
    13.6 inches (for wide carriage printers).
```
 Okimate-20
 ----------
 1. Thermal transfer b&w/color printer (text and graphics).
 2. Use Black ribbon for non-color dumps; Color ribbon for color dumps.
 3. Linefeeds an even # of dots printed. (ie. if 3 printed, 4 advanced).
 4. Densities supported are 120x144(1) dpi.

 Quadram_QuadJet
 ---------------
 1. Ink jet b&w/color printer (text and graphics).
 2. Linefeeds # of vertical dots printed.
 3. Densities supported are 83x84(1) dpi.

 Qume_LetterPro_20
 -----------------
 1. Daisywheel printer (text only).

 Seiko_5300
 ----------
 1. Thermal transfer b&w/color printer (graphics only).
 2. Use Black ribbon for non-color dumps; Color ribbon for color dumps.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	152	152	23104	drives CH-5301 printer
 	2	203	203	41209	drives CH-5312 printer
 	3	240	240	57600	drives CH-5303 printer
 	4, 5,6,7	same as 3
 	You must select the proper density to drive the specific printer
 	that you have.
 4. This driver is not on the V1.3 Workbench or Extras disk.  It is

    available on BIX and directly from Seiko.
 Seiko_5300a
 -----------
 1. Thermal transfer b&w/color printer (graphics only).
 2. Use Black ribbon for non-color dumps; Color ribbon for color dumps.
 3. Density	XDPI	YDPI	XYDPI	Comments
 	1	152	152	23104	drives CH-5301 printer
 	2	203	203	41209	drives CH-5312 printer
 	3	240	240	57600	drives CH-5303 printer
 	4, 5,6,7	same as 3
 	You must select the proper density to drive the specific printer
 	that you have.
 4. This driver is the same as the Seiko_5300 driver EXCEPT it is
```c
    approximately 2 times faster (during color dumps) and requires LOTS of
    memory (up to 1,564,569 bytes for a full 8 x 10 inch (1927 x 2173 dot)
    color dump).  Typically full-size (color) dumps are 1927 x 1248 dots
    and require 898,569 bytes.  The memory requirements are 1/3 when doing
    a non-color printout.
```
 5. This driver is not on the V1.3 Workbench or Extras disk.  It is

    available on BIX and directly from Seiko.
 Tektronix_4693D
 ---------------
 1. Thermal transfer b&w/color printer (graphics only).
 2. Densities supported are 300x300(1) dpi
 3. Due to the way the printer images a picture none of the printer
```c
    preferences options affect the printout with the following exceptions:
    a)Aspect - Horizontal, Vertical
    b)Shade - B&W, Grey_Scale, Color
    ...as a result of this only full size pictures can be printed.
```
 4. Keypad menu option 3b COLOR ADJUSTMENT may be set from the keypad.
    For normal prints this option should be set to "do not adjust".
 5. Keypad menu option 3d VIDEO COLOR CORRECTION may be set from the keypad.
    For normal prints this option should be set to "do not adjust".
 6. Keypad menu option 5 BACKGROUND COLOR EXCHANGE may be set from the
    keypad.  For normal prints this option should be set to "print colors
    as received".
 7. Once a picture has been printed additional copies may be printed
    without resending by using the printers keypad.
 8. This driver is not on the V1.3 Workbench or Extras disk.  It is

    available on BIX and directly from Tektronix.
 Tektronix_4696
 --------------
 1. Ink jet b&w/color printer (text and graphics).
 2. Always linefeeds 4 dots (limitation of printer).
 3. Densities supported are 121x120(1), 242x120(black)(2) and
```c
    242x120(color)(3).
    Selecting a density of 2 or higher really doesn't give you true 242 dpi
    resolution since the printer only has 121 x dots per inch.
    Instead this mode tells the printer to go into it's double pass mode.
    Here, it outputs a line of dots at 121 dpi; and outputs the line again
    (shifted to the right by 1/242 of an inch).  This produces much more
    vibrate colors and gives the illusion of more resolution.  One drawback
    is that large areas of solid colors (red, green, and blue specifically)
    tend to over-saturate the paper with ink.  Density1 outputs all colors
    in one pass.  Density 2 does a double pass on black.  Density 3 does a
    double pass on all colors.  Density 1 to 3 correspond to the printer's
    graphics printing modes 1 to 3 (respectively).
```
 4. This driver is not on the V1.3 Workbench or Extras disk.  It is
    available on BIX and directly from Tektronix.
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of

```c
    9.0 inches (for wide roll paper).
```
 Toshiba_P351C (24-pin Toshiba compatible)
 -------------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Drives all Toshiba_P351C compatible printers.
 3. Linefeeds # of vertical dots printed.
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	180	180	32400
 	2	360	180	64800
 	3,4,5,6,7	same as 2
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of

```c
    13.5 inches (for wide carriage printers).
```
 Toshiba_P351SX (24-pin Toshiba compatible)
 --------------
 1. Dot matrix b&w/color printer (text and graphics).
 2. Drives all Toshiba_P351SX (321SL, 321SLC, 341SL) compatible printers.
 3. Linefeeds # of vertical dots printed.
 4. Density	XDPI	YDPI	XYDPI	Comments
 	1	180	180	 32400
 	2	360	180	 64800
 	3	180	360	 64800	two pass
 	4	360	360	129600	two pass
 	5,6,7	same as 4
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of

```c
    13.5 inches (for wide carriage printers).
```
 Xerox_4020
 ----------
 1. Ink jet b&w/color printer (text and graphics).
 2. Always linefeeds 4 dots (limitation of printer).
 3. This driver is IDENTICAL to the Diablo_C-150 driver EXCEPT it outputs
```c
    all black dots TWICE.  This is a special feature of this printer and
    produces much more solid, darker black shades.  Please note that some
    printing time overhead results from this feature; if you don't want it
    use the Diablo_C-150 driver.
```
 4. Densities supported are 121x120(1) and 242x240(2) dpi.
```c
    Selecting a density of 2 or higher really doesn't give you true 240 dpi
    resolution since the Xerox_4020 only has 121 x dots per inch.
    Instead this mode tells the printer to go into it's pseudo 240 dpi mode.
    Here, it outputs a line of dots at 121 dpi; moves the paper up 1/240 of
    an inch and outputs the line again (shifted to the right by 1/240 of an
    inch).  This produces much more vibrate colors and gives the illusion
    of more resolution.  One drawback is that large areas of solid colors
    (red, green, and blue specifically) tend to over-saturate the paper with
    ink.
```
 5. A PaperSize of 'Wide Tractor' selects a maximum print width of


```c
    9.0 inches (for wide roll paper).
```
 Notes
 -----

 *0 - on most printers friction fed paper tends to produce better looking

```c
      (ie. less horizontal banding) graphic dumps than tractor fed paper.
```
 *1 - in this mode the printer cannot print two consecutive dots in a row.

      It is recommended that you only use this density for B&W Shade dumps.
 *2 - only when 72 YDPI is selected.  This option is useful if you notice

      tiny white horizontal strips in your printout.
 *3 - only when 144 YDPI is selected.  This option is useful if you notice

      tiny white horizontal strips in your printout.
