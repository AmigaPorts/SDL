---
title: 10 Printer Device / Device Interface
manual: devices
chapter: devices
section: 10-printer-device-device-interface
functions: []
libraries: []
---

# 10 Printer Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The printer device operates like the other Amiga devices.  To use it, you
must first open the printer device, then send I/O requests to it, and then
close it when finished.  See the [Introduction to Amiga Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md) chapter
for general information on device usage.

There are three distinct kinds of data structures required by the printer
I/O routines. Some of the printer device I/O commands, such as [CMD_START](autodocs-2.0/printer-device-cmd-start.md)
and [CMD_WRITE](autodocs-2.0/printer-device-cmd-write.md) require only an IOStdReq data structure. Others, such as
[PRD_DUMPRPORT](autodocs-2.0/printer-device-prd-dumprport.md) and [PRD_PRTCOMMAND](autodocs-2.0/printer-device-prd-prtcommand.md), require an extended data structure
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
See the include file exec/[io.h](autodocs-2.0/includes-exec-io-h.md) for more information on IOStdReq and the
include file devices/[printer.h](autodocs-2.0/includes-devices-printer-h.md) for more information on IODRPReq and
IOPrtCmdReq.

 [Opening The Printer Device](devices/10-device-interface-opening-the-printer-device.md) 
 [Writing Text To The Printer Device](devices/10-device-interface-writing-text-to-the-printer-device.md) 
 [Important Points About Print Requests](devices/10-device-interface-important-points-about-print-requests.md) 
 [Closing The Printer Device](devices/10-device-interface-closing-the-printer-device.md) 

