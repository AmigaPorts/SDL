/* Source: ADCD 2.1
 * Section: 10-printer-device-dumping-a-rastport-to-a-printer
 * Library: devices
 * ADCD reference: devices/10-printer-device-dumping-a-rastport-to-a-printer.md
 */

    union printerIO *PrintIO
    struct RastPort *rastPort;
    struct ColorMap *colorMap;
    ULONG modeid;
    UWORD sx, sy, sw, sh;
    LONG dc, dr;
    UWORD s;

    PrintIO->iodrp.io_RastPort = rastPort; /* pointer to RastPort */
    PrintIO->iodrp.io_ColorMap = colorMap; /* pointer to color map */
    PrintIO->iodrp.io_Modes = modeid;      /* ModeID of ViewPort */
    PrintIO->iodrp.io_SrcX = sx;           /* RastPort X offset */
    PrintIO->iodrp.io_SrcY = sy;           /* RastPort Y offset */
    PrintIO->iodrp.io_SrcWidth = sw;       /* print width from X offset */
    PrintIO->iodrp.io_SrcHeight = sh;      /* print height from Y offset */
    PrintIO->iodrp.io_DestCols = dc;       /* pixel width */
    PrintIO->iodrp.io_DestRows = dr;       /* pixel height */
    PrintIO->iodrp.io_Special = s;         /* flags */
    PrintIO->iodrp.io_Command = PRD_DUMPRPORT;
    SendIO((struct IORequest *)request);
