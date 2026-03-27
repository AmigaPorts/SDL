---
title: 6 Input Device / Device Interface
manual: devices
chapter: devices
section: 6-input-device-device-interface
functions: []
libraries: []
---

# 6 Input Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The input device operates like the other Amiga devices.  To use it, you
must first open the input device, then send I/O requests to it, and then
close it when finished.  See the [Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)
chapter for general information on device usage.

A number of structures are used by the input device to do its processing.
Some are used to pass commands and data to the device, some are used to
describe input events like mouse movements and key depressions, and one
structure is used to describe the environment for input event handlers.

The I/O request used by the input device for most commands is IOStdReq.

   struct IOStdReq
   {
```c
       struct Message io_Message; /* message reply port */
       struct Device  *io_Device; /* device node pointer */
       struct Unit    *io_Unit;   /* unit */
       UWORD  io_Command;         /* input device command */
       UBYTE  io_Flags;           /* input device flags */
       BYTE   io_Error;           /* error code */
       ULONG  io_Length;          /* number of bytes to transfer */
       APTR   io_Data;            /* pointer to data area */
```
   };

See the include file exec/[io.h](autodocs-2.0/includes-exec-io-h.md) for the complete structure definition.

Two of the input device commands - [IND_SETTHRESH](devices/6-input-device-setting-the-key-repeat-threshold.md) and [IND_SETPERIOD](devices/6-input-device-setting-the-key-repeat-interval.md) -
require a time specification and must use a timerequest structure instead
of an IOStdReq.

   struct timerequest
   {
```c
       struct IORequest tr_node;
       struct timeval tr_time;
```
   };

As you can see, the timerequest structure includes an IORequest structure.
The io_Command field of theIORequest indicates the command to the input
device and the timeval structure sets the time values.  See the include
file devices/[timer.h](autodocs-2.0/includes-devices-timer-h.md) for the complete structure definition.


   In Case You Feel Like Reinventing the Wheel...
   ----------------------------------------------
   You could define a "super-IORequest" structure for the input device
   which would combine the IOStdReq fields with the timeval structure of
   the timerequest structure.

 [Opening The Input Device](devices/6-device-interface-opening-the-input-device.md) 
 [Input Device Event Types](devices/6-device-interface-input-device-event-types.md) 
 [Closing The Input Device](devices/6-device-interface-closing-the-input-device.md) 

