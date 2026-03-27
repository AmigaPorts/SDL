---
title: 12 Serial Device / Device Interface
manual: devices
chapter: devices
section: 12-serial-device-device-interface
functions: []
libraries: []
---

# 12 Serial Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The serial device operates like the other Amiga devices.  To use it, you
must first open the serial device, then send I/O requests to it, and then
close it when finished.  See the "[Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)"
chapter for general information on device usage.

The I/O request used by the serial device is called IOExtSer.


```c
    struct IOExtSer
       {
        struct   IOStdReq IOSer;
        ULONG    io_CtlChar;    /* control characters */
        ULONG    io_RBufLen;    /* length in bytes of serial read buffer */
        ULONG    io_ExtFlags;   /* additional serial flags */
        ULONG    io_Baud;       /* baud rate */
        ULONG    io_BrkTime;    /* duration of break in microseconds */
        struct   iOTArray  io_TermArray;  /* termination character array */
        UBYTE    io_ReadLen;    /* number of bits per read character */
        UBYTE    io_WriteLen;   /* number of bits per write character */
        UBYTE    io_StopBits;   /* number of stopbits for read */
        UBYTE    io_SerFlags;   /* serial device flags */
        UWORD    io_Status;     /* status of serial port and lines */
    };
```
See the include file devices/[serial.h](autodocs-2.0/includes-devices-serial-h.md) for the complete structure
definition.

 [Opening The Serial Device](devices/12-device-interface-opening-the-serial-device.md) 		 [Writing To The Serial Device](devices/12-device-interface-writing-to-the-serial-device.md) 
 [Reading From The Serial Device](devices/12-device-interface-reading-from-the-serial-device.md) 	 [Closing The Serial Device](devices/12-device-interface-closing-the-serial-device.md) 

