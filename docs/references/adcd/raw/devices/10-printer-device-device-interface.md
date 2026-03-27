# 10 Printer Device / Device Interface


The printer device operates like the other Amiga devices.  To use it, you
must first open the printer device, then send I/O requests to it, and then
close it when finished.  See the [Introduction to Amiga Devices](../Devices_Manual_guide/node0006.html) chapter
for general information on device usage.

There are three distinct kinds of data structures required by the printer
I/O routines. Some of the printer device I/O commands, such as [CMD_START](../Includes_and_Autodocs_2._guide/node0516.html)
and [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0518.html) require only an IOStdReq data structure. Others, such as
[PRD_DUMPRPORT](../Includes_and_Autodocs_2._guide/node0519.html) and [PRD_PRTCOMMAND](../Includes_and_Autodocs_2._guide/node051A.html), require an extended data structure
called IODRPReq (for "Dump a RastPort Request") or IOPrtCmdReq (for
"Printer Command Request").

For convenience, it is strongly recommended that you define a single data
structure called printerIO, that can be used to represent any of the three
pre-defined printer communications request blocks.


```c
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
```
See the include file exec/[io.h](../Includes_and_Autodocs_2._guide/node0094.html) for more information on IOStdReq and the
include file devices/[printer.h](../Includes_and_Autodocs_2._guide/node0052.html) for more information on IODRPReq and
IOPrtCmdReq.

 [Opening The Printer Device](../Devices_Manual_guide/node0045.html) 
 [Writing Text To The Printer Device](../Devices_Manual_guide/node0046.html) 
 [Important Points About Print Requests](../Devices_Manual_guide/node0047.html) 
 [Closing The Printer Device](../Devices_Manual_guide/node0048.html) 

