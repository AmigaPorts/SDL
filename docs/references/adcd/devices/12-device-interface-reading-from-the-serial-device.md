---
title: 12 / Device Interface / Reading From The Serial Device
manual: devices
chapter: devices
section: 12-device-interface-reading-from-the-serial-device
functions: []
libraries: []
---

# 12 / Device Interface / Reading From The Serial Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You read from the serial device by passing an [IOExtSer](devices/12-serial-device-device-interface.md) to the device with
[CMD_READ](autodocs-2.0/serial-device-cmd-read.md) set in io_Command, the number of bytes to be read set in
io_Length and the address of the read buffer set in io_Data.

   #define READ_BUFFER_SIZE 256
   char SerialReadBuffer[READ_BUFFER_SIZE]; /* Reserve SIZE bytes */

   SerialIO->IOSer.io_Length   = READ_BUFFER_SIZE;
   SerialIO->IOSer.io_Data     = (APTR)&SerialReadBuffer[0];
   SerialIO->IOSer.io_Command  = CMD_READ;
   DoIO((struct IORequest *)SerialIO);

If you use this example, your task will be put to sleep waiting until the
serial device reads 256 bytes (or terminates early).  Early termination
can be caused by error conditions such as a break.  The number of
characters actually received will be recorded in the io_Actual field of the
[IOExtSer](devices/12-serial-device-device-interface.md) structure you passed to the serial device.

