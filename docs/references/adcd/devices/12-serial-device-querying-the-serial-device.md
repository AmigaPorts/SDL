---
title: 12 Serial Device / Querying the Serial Device
manual: devices
chapter: devices
section: 12-serial-device-querying-the-serial-device
functions: []
libraries: []
---

# 12 Serial Device / Querying the Serial Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You query the serial device by passing an [IOExtSer](devices/12-serial-device-device-interface.md) to the device with
[SDCMD_QUERY](autodocs-2.0/serial-device-sdcmd-query.md) set in io_Command.  The serial device will respond with the
status of the serial port lines and registers, and the number of unread
characters in the read buffer.

   UWORD Serial_Status;
   ULONG Unread_Chars;

   SerialIO->IOSer.io_Command  = SDCMD_QUERY; /* indicate query */
   SendIO((struct IORequest *)SerialIO);

   Serial_Status = SerialIO->io_Status; /* store returned status */
   Unread_Chars = SerialIO->IOSer.io_Actual; /* store unread count */

The 16 status bits of the serial device are returned in io_Status; the
number of unread characters is returned in io_Actual.


```c
                       SERIAL DEVICE STATUS BITS

         Bit     Active     Symbol      Function
         ---     ------     ------      --------
          0        -                    Reserved
          1        -                    Reserved
          2      high       (RI)        Parallel Select on the A1000.  On
                                        the A500 and A2000, Select is also
                                        connected to the serial port's
                                        Ring Indicator.  (Be cautious when
                                        making cables.)

          3      low        (DSR)       Data set ready
          4      low        (CTS)       Clear to send
          5      low        (CD)        Carrier detect
          6      low        (RTS)       Ready to send
          7      low        (DTR)       Data terminal ready
          8      high                   Read overrun
          9      high                   Break sent
          10     high                   Break received
          11     high                   Transmit x-OFFed
          12     high                   Receive x-OFFed
          13-15    -                    (reserved)
```
