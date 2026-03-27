---
title: 10 Printer Device / Querying the Printer Device
manual: devices
chapter: devices
section: 10-printer-device-querying-the-printer-device
functions: []
libraries: []
---

# 10 Printer Device / Querying the Printer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The status of the printer port and registers can be determined by querying
the printer device.  The information returned will vary depending on the
type of printer - parallel or serial - selected by the user.  If parallel,
the data returned will reflect the current state of the parallel port; if
serial, the data returned will reflect the current state of the serial
port.

You query the printer device by passing an [IOStdReq](autodocs-2.0/includes-exec-io-h.md) to the device with
[PRD_QUERY](autodocs-2.0/printer-device-prd-query.md) set in io_Command and a pointer to a structure to hold the

status set in io_Data.


   struct PStat
   {
```c
       UBYTE LSB;       /* least significant byte of status */
       UBYTE MSB;       /* most significant byte of status */
```
   };

   union printerIO *PrintIO;

   struct PStat status;

   PrintIO->ios.io_Data = &status;      /* point to status structure */
   PrintIO->ios.io_Command = PRD_QUERY;
   DoIO((struct IORequest *)request);

The status is returned in the two UBYTES set in the io_Data field.  The
printer type, either serial or parallel, is returned in the io_Actual
field.

   io_Data         Bit     Active          Function (Serial Device)
   -------         ---     ------          ------------------------

```c
     LSB           0       low             reserved
                   1       low             reserved
                   2       low             reserved
                   3       low             Data Set Ready
                   4       low             Clear To Send
                   5       low             Carrier Detect
                   6       low             Ready To Send
                   7       low             Data Terminal Ready
     MSB           8       high            read buffer overflow
                   9       high            break sent (most recent output)
                   10      high            break received (as latest input)
                   11      high            transmit x-OFFed
                   12      high            receive x-OFFed
                   13-15   high            reserved
```
   io_Data         Bit     Active          Function (Parallel Device)
   -------         ---     ------          --------------------------

```c
     LSB           0       high            printer busy (offline)
                   1       high            paper out
                   2       high            printer selected
                   3        -              read=0; write=1
                   4-7                     reserved
     MSB           8-15                    reserved
```
   io_Actual                               1-parallel, 2-serial

