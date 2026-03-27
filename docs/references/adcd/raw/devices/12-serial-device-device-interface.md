# 12 Serial Device / Device Interface


The serial device operates like the other Amiga devices.  To use it, you
must first open the serial device, then send I/O requests to it, and then
close it when finished.  See the "[Introduction to Amiga System Devices](../Devices_Manual_guide/node0006.html)"
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
See the include file devices/[serial.h](../Includes_and_Autodocs_2._guide/node004B.html) for the complete structure
definition.

 [Opening The Serial Device](../Devices_Manual_guide/node009D.html) 		 [Writing To The Serial Device](../Devices_Manual_guide/node009F.html) 
 [Reading From The Serial Device](../Devices_Manual_guide/node009E.html) 	 [Closing The Serial Device](../Devices_Manual_guide/node00A0.html) 

