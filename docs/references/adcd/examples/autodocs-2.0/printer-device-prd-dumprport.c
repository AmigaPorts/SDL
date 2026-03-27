/* Source: ADCD 2.1
 * Section: printer-device-prd-dumprport
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/printer-device-prd-dumprport.md
 */

    io_Message      mn_ReplyPort set if quick I/O is not possible.
    io_Command      PRD_DUMPRPORT.
    io_Flags        IOB_QUICK set if quick I/O is possible.
    io_RastPort     ptr to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
    io_ColorMap     ptr to a [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113).
    io_Modes        the 'modes' flag from a [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure,
                    (the upper word is reserved and should be zero).

                    If you are running under version 36, or greater
                    of graphics.library, it is recommended that
                    you fill in "io_Modes" with the ULONG (32-bit)
                    value returned from calling:

                    ULONG ModeID = GetVPModeID(struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *);

                    Doing so provides for upwards compatability with
                    the new display modes available under V36
                    (example: aspect ratio calculations for new
                    display modes).

    io_SrcX         x offset into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to start printing from.
    io_SrcY         y offset into the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to start printing from.
    io_SrcWidth     width of the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to print (from io_SrcX).
    io_SrcHeight    height of the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) to print (from io_SrcY).
    io_DestCols     width of the printout in printer pixels.
    io_DestRows     height of the printout in printer pixels.
    io_Special      flag bits
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

    The following rules for the interpretation of io_DestRows and
    io_DestCols that may produce unexpected results when they are
    not greater than zero and io_Special is zero.  They have been
    retained for compatability.  The user will not trigger these
    other rules with well formed usage of io_Special.

    When io_Special is equal to 0, the following rules
    (from the V1.1 printer.device, and retained for compatibility
    reasons) take effect.  Remember, these special rules are
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
