---
title: 12 / Device Interface / Opening The Serial Device
manual: devices
chapter: devices
section: 12-device-interface-opening-the-serial-device
functions: [OpenDevice]
libraries: [exec.library]
---

# 12 / Device Interface / Opening The Serial Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Three primary steps are required to open the serial device:

   *  Create a message port using [CreatePort()](autodocs-2.0/amiga-lib-createport.md). Reply messages from the

      device must be directed to a message port.
   *  Create an extended I/O request structure of type IOExtSer using

```c
      [CreateExtIO()](autodocs-2.0/amiga-lib-createextio.md). CreateExtIO() will initialize the I/O request to point
      to your reply port.
```
   *  Open the serial device.  Call [OpenDevice()](autodocs-2.0/serial-device-opendevice.md), passing the I/O request.

   struct MsgPort  *SerialMP;          /* Define storage for one pointer */
   struct IOExtSer *SerialIO;         /* Define storage for one pointer */

   if (SerialMP=CreatePort(0,0) )

```c
       if (SerialIO=(struct IOExtSer *)
              CreateExtIO(SerialMP,sizeof(struct IOExtSer)) )
           SerialIO->io_SerFlags=SERF_SHARED;  /* Turn on SHARED mode */
           if (OpenDevice(SERIALNAME,0L,(struct IORequest *)SerialIO,0) )
               printf("%s did not open\n",SERIALNAME);
```
During the open, the serial device pays attention to a subset of the flags
in the io_SerFlags field.  The flag bits, [SERF_SHARED](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md) and [SERF_7WIRE](devices/12-setting-serial-parameters-serial-flags-bits-for-io.md), must
be set before open.  For consistency, the other flag bits should also be
properly set.  Full descriptions of all flags will be given later.

The serial device automatically fills in default settings for all
parameters - stop bits, parity, baud rate, etc.  For the default unit, the
settings will come from Preferences.  You may need to change certain
parameters, such as the baud rate, to match your requirements. Once the
serial device is opened, all characters received will be buffered, even if
there is no current request for them.

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
