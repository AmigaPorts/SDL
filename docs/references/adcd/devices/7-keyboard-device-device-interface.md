---
title: 7 Keyboard Device / Device Interface
manual: devices
chapter: devices
section: 7-keyboard-device-device-interface
functions: []
libraries: []
---

# 7 Keyboard Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The keyboard device operates like the other Amiga devices.  To use it, you
must first open the keyboard device, then send I/O requests to it, and
then close it when finished.  See the "[Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)"
chapter for general information on device usage.

The I/O request used by the keyboard device is called IOStdReq.


```c
    struct IOStdReq
    {
        struct  Message io_Message;
        struct  Device  *io_Device; /* device node pointer  */
        struct  Unit    *io_Unit;   /* unit (driver private)*/
        UWORD   io_Command;         /* device command */
        UBYTE   io_Flags;
        BYTE    io_Error;        /* error or warning num */
        ULONG   io_Actual;       /* actual number of bytes transferred */
        ULONG   io_Length;       /* requested number bytes transferred*/
        APTR    io_Data;         /* points to data area */
        ULONG   io_Offset;       /* offset for block structured devices */
    };
```
See the include file exec/[io.h](autodocs-2.0/includes-exec-io-h.md) for the complete structure definition.

 [Opening The Keyboard Device](devices/7-device-interface-opening-the-keyboard-device.md) 
 [Closing The Keyboard Device](devices/7-device-interface-closing-the-keyboard-device.md) 

