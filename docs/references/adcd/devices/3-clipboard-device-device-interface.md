---
title: 3 Clipboard Device / Device Interface
manual: devices
chapter: devices
section: 3-clipboard-device-device-interface
functions: []
libraries: []
---

# 3 Clipboard Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The clipboard device operates like the other Amiga devices.  To use it,
you must first open the clipboard device, then send I/O requests to it,
and then close it when finished. See "[Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)"
chapter for general information on device usage.

  struct IOClipReq
  {
```c
      struct  Message io_Message;
      struct  Device  *io_Device;     /* device node pointer  */
      struct  Unit    *io_Unit;       /* unit (driver private)*/
      UWORD   io_Command;             /* device command */
      UBYTE   io_Flags;               /* including QUICK and SATISFY */
      BYTE    io_Error;               /* error or warning num */
      ULONG   io_Actual;              /* number of bytes transferred */
      ULONG   io_Length;              /* number of bytes requested */
      STRPTR  io_Data;                /* either clip stream or post port */
      ULONG   io_Offset;              /* offset in clip stream */
      LONG    io_ClipID;              /* ordinal clip identifier */
```
  };

See the include file devices/[clipboard.h](autodocs-2.0/includes-devices-clipboard-h.md) for the complete
structure definition.

The clipboard device I/O request, IOClipReq, looks like a standard
IORequest structure except for the addition of the io_ClipID field, which
is used by the device to identify clips. It must be set to zero by the
application for a post or an initial write or read, but preserved for
subsequent writes or reads, as the clipboard device uses this field
internally for bookkeeping purposes.

 [Opening The Clipboard Device](devices/3-device-interface-opening-the-clipboard-device.md)        [Updating The Clipboard Device](devices/3-device-interface-updating-the-clipboard-device.md) 
 [Clipboard Data](devices/3-device-interface-clipboard-data.md) 		     [Clipboard Messages](devices/3-device-interface-clipboard-messages.md) 
 [Multiple Clips](devices/3-device-interface-multiple-clips.md) 		     [Reading From The Clipboard Device](devices/3-device-interface-reading-from-the-clipboard-device.md) 
 [Writing To The Clipboard Device](devices/3-device-interface-writing-to-the-clipboard-device.md)     [Closing The Clipboard Device](devices/3-device-interface-closing-the-clipboard-device.md) 

