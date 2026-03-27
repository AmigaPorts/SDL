/* Source: ADCD 2.1
 * Section: includes-devices-printer-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-printer-h.md
 */

    struct  Message io_Message;
    struct  Device  *io_Device;     /* device node pointer  */
    struct  Unit    *io_Unit;	    /* unit (driver private)*/
    UWORD   io_Command;	    /* device command */
    UBYTE   io_Flags;
    BYTE    io_Error;		    /* error or warning num */
    struct  RastPort *io_RastPort;  /* raster port */
    struct  ColorMap *io_ColorMap;  /* color map */
    ULONG   io_Modes;		    /* graphics viewport modes */
    UWORD   io_SrcX;		    /* source x origin */
    UWORD   io_SrcY;		    /* source y origin */
    UWORD   io_SrcWidth;	    /* source x width */
    UWORD   io_SrcHeight;	    /* source x height */
    LONG    io_DestCols;	    /* destination x width */
    LONG    io_DestRows;	    /* destination y height */
    UWORD   io_Special;	    /* option flags */
