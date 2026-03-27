---
title: 12 / / Use Of BeginIO() With The Serial Device
manual: devices
chapter: devices
section: 12-use-of-beginio-with-the-serial-device
functions: [DoIO, SendIO, WaitIO]
libraries: [exec.library]
---

# 12 / / Use Of BeginIO() With The Serial Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Instead of transmitting the read command with either [DoIO()](autodocs-2.0/exec-library-doio.md) or [SendIO()](autodocs-2.0/exec-library-sendio.md),
you might elect to use the low level [BeginIO()](autodocs-2.0/serial-device-beginio.md) interface to a device.

[BeginIO()](autodocs-2.0/serial-device-beginio.md) works much like [SendIO()](autodocs-2.0/exec-library-sendio.md), i.e., asynchronously, except it gives
you control over the quick I/O bit (IOB_QUICK) in the io_Flags field.
Quick I/O saves the overhead of a reply message, and perhaps the overhead
of a task switch. If a quick I/O request is actually completed quickly,
the entire command will execute in the context of the caller. See the
"[Exec: Device Input/Output](libraries/19-exec-device-i-o.md)" chapter of the Amiga ROM Kernel Reference
Manual: Libraries for more detailed information on quick I/O.

The device will determine if a quick I/O request will be handled quickly.
Most non-I/O commands will execute quickly; read and write commands may or
may not finish quickly.

   SerialIO.IOSer.io_Flags |= IOF_QUICK;  /* Set QuickIO Flag */

   BeginIO((struct IORequest *)SerialIO);
   if (SerialIO->IOSer.io_Flags & IOF_QUICK )
```c
       /* If flag is still set, I/O was synchronous and is now finished.
        * The IORequest was NOT appended a reply port.  There is no
        * need to remove or WaitIO() for the message.
        */
       printf("QuickIO\n");
```
   else
```c
        /* The device cleared the QuickIO bit.  QuickIO could not happen
         * for some reason; the device processed the command normally.
         * In this case BeginIO() acted exactly like SendIO().
         */
        printf("Regular I/O\n");
```
   WaitIO(SerialIO);

The way you read from the device depends on your need for processing
speed. Generally the [BeginIO()](autodocs-2.0/serial-device-beginio.md) route provides the lowest system overhead
when quick I/O is possible.  However, if quick I/O does not work, the same
reply message overhead still exists.

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
- [WaitIO — exec.library](../autodocs/exec.library.md#waitio)
