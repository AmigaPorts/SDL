---
title: 9 Parallel Device / Device Interface
manual: devices
chapter: devices
section: 9-parallel-device-device-interface
functions: []
libraries: []
---

# 9 Parallel Device / Device Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The parallel device operates like the other Amiga devices.  To use it, you
must first open the parallel device, then send I/O requests to it, and
then close it when finished.  See "[Introduction to Amiga System Devices](devices/1-introduction-to-amiga-system-devices-using-a-device.md)"
chapter for general information on device usage.

The I/O request used by the parallel device is called IOExtPar.


```c
    struct   IOExtPar
        {
        struct  IOStdReq IOPar;
        ULONG   io_PExtFlags;   /* additional parallel flags */
        UBYTE   io_Status;      /* status of parallel port and registers */
        UBYTE   io_ParFlags;    /* parallel device flags */
        struct  IOPArray io_PTermArray; /* termination character array */
        };
```
See the include file devices/[parallel.h](autodocs-2.0/includes-devices-parallel-h.md) for the complete structure
definition.

 [Opening The Parallel Device](devices/9-device-interface-opening-the-parallel-device.md) 		 [Writing To The Parallel Device](devices/9-device-interface-writing-to-the-parallel-device.md) 
 [Reading From The Parallel Device](devices/9-device-interface-reading-from-the-parallel-device.md) 	 [Closing The Parallel Device](devices/9-device-interface-closing-the-parallel-device.md) 

