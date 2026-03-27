---
title: 9 / Device Interface / Reading From The Parallel Device
manual: devices
chapter: devices
section: 9-device-interface-reading-from-the-parallel-device
functions: []
libraries: []
---

# 9 / Device Interface / Reading From The Parallel Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You read from the parallel device by passing an [IOExtPar](devices/9-parallel-device-device-interface.md) to the device
with [CMD_READ](autodocs-2.0/parallel-device-cmd-read.md) set in io_Command, the number of bytes to be read set in
io_Length and the address of the read buffer set in io_Data.

   #define READ_BUFFER_SIZE 256
   /* Reserve SIZE bytes of storage */
   char ParallelReadBuffer[READ_BUFFER_SIZE];

   ParallelIO->IOPar.io_Length   = READ_BUFFER_SIZE;
   ParallelIO->IOPar.io_Data     = (APTR)&ParallelReadBuffer[0];
   ParallelIO->IOPar.io_Command  = CMD_READ;
   DoIO((struct IORequest *)ParallelIO);

If you use this example, your task will be put to sleep waiting until the
parallel device reads 256 bytes (or terminates early).  Early termination
can be caused by error conditions.

