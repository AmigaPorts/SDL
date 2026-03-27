---
title: 10 / Printer Device Access / Writing To Prt:
manual: devices
chapter: devices
section: 10-printer-device-access-writing-to-prt
functions: [Write]
libraries: [dos.library]
---

# 10 / Printer Device Access / Writing To Prt:

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once you've opened it, you can print by calling the AmigaDOS [Write()](autodocs-2.0/dos-library-write.md)
standard I/O routine.


```c
    actual_length = Write(file, dataLocation, length);

    where

    file is a file handle.
```
dataLocation
   is a pointer to the first character in the output stream you wish to
   write.  This stream can contain the standard escape sequences as
   shown in the command table below. The printer command aRAW (see the
   [Printer Device Command Functions](devices/10-sending-printer-commands-to-a-printer-command-definitions.md) table below) can be used in the
   stream if character translation is not desired.

length
   is the length of the output stream.

actual_length
   is the actual length of the write. For the printer device, if there
   are no errors, this will be the same as the length of write
   requested. The only exception is if you specify a value of -1 for
   length. In this case, -1 for length means that a null (0) terminated
   stream is being written to the printer device. The device returns the
   count of characters written prior to encountering the null.  If it
   returns a value of -1 in actual_length, there has been an error.

   -1 = STOP!
   ----------
   If a -1 is returned by [Write()](autodocs-2.0/dos-library-write.md), do not do any additional printing.

---

## See Also

- [Write — dos.library](../autodocs/dos.library.md#write)
