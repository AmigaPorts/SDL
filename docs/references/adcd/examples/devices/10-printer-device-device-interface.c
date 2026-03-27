/* Source: ADCD 2.1
 * Section: 10-printer-device-device-interface
 * Library: devices
 * ADCD reference: devices/10-printer-device-device-interface.md
 */

    union printerIO
    {
        struct IOStdReq    ios;
        struct IODRPReq    iodrp;
        struct IOPrtCmdReq iopc;
    };

    struct IODRPReq
    {
        struct  Message io_Message;
        struct  Device  *io_Device;     /* device node pointer  */
        struct  Unit    *io_Unit;       /* unit (driver private)*/
        UWORD   io_Command;             /* device command */
        UBYTE   io_Flags;
        BYTE    io_Error;               /* error or warning num */
        struct  RastPort *io_RastPort;  /* raster port */
        struct  ColorMap *io_ColorMap;  /* color map */
        ULONG   io_Modes;               /* graphics viewport modes */
        UWORD   io_SrcX;                /* source x origin */
        UWORD   io_SrcY;                /* source y origin */
        UWORD   io_SrcWidth;            /* source x width */
        UWORD   io_SrcHeight;           /* source x height */
        LONG    io_DestCols;            /* destination x width */
        LONG    io_DestRows;            /* destination y height */
        UWORD   io_Special;             /* option flags */
    };

    struct IOPrtCmdReq
    {
        struct  Message io_Message;
        struct  Device  *io_Device;     /* device node pointer  */
        struct  Unit    *io_Unit;       /* unit (driver private)*/
        UWORD   io_Command;             /* device command */
        UBYTE   io_Flags;
        BYTE    io_Error;               /* error or warning num */
        UWORD   io_PrtCommand;          /* printer command */
        UBYTE   io_Parm0;               /* first command parameter */
        UBYTE   io_Parm1;               /* second command parameter */
        UBYTE   io_Parm2;               /* third command parameter */
        UBYTE   io_Parm3;               /* fourth command parameter */
    };
