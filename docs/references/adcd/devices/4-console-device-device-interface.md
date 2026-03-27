---
title: 4 Console Device / Device Interface
manual: devices
chapter: devices
section: 4-console-device-device-interface
functions: []
libraries: []
---

# 4 Console Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The console device operates like the other Amiga devices.  To use it, you
must first open the console device, then send I/O requests to it, and then
close it when finished.  See the "[Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)"
chapter for general information on device usage.

The I/O request used by the console device is called IOStdReq.

   struct IOStdReq
   {
```c
       struct  Message io_Message;
       struct  Device  *io_Device;/* device node pointer  */
       struct  Unit    *io_Unit;  /* unit (driver private)*/
       UWORD   io_Command;        /* device command */
       UBYTE   io_Flags;
       BYTE    io_Error;          /* error or warning num */
       ULONG   io_Actual;         /* actual number of bytes transferred */
       ULONG   io_Length;         /* requested number bytes transferred*/
       APTR    io_Data;           /* points to data area */
       ULONG   io_Offset;         /* offset for block structured devices */
```
   };

See the include file exec/[io.h](autodocs-2.0/includes-exec-io-h.md) for the complete structure definition.

 [Console Device Units](devices/4-device-interface-console-device-units.md) 
 [Opening The Console Device](devices/4-device-interface-opening-the-console-device.md) 
 [Closing The Console Device](devices/4-device-interface-closing-the-console-device.md) 

