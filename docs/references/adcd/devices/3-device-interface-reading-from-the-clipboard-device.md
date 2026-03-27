---
title: 3 / Device Interface / Reading From The Clipboard Device
manual: devices
chapter: devices
section: 3-device-interface-reading-from-the-clipboard-device
functions: []
libraries: []
---

# 3 / Device Interface / Reading From The Clipboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You read from the clipboard device by passing an [IOClipReq](devices/3-clipboard-device-device-interface.md) to the device
with CMD_READ set in io_Command, the number of bytes to be read set in
io_Length and the address of the read buffer set in io_Data.


```c
    ClipIO->io_Command = CMD_READ;
    ClipIO->io_Data = (char *) read_data;
    ClipIO->io_Length = 20L;
```
io_Offset must be set to zero for the first read of a paste sequence.  An
io_Actual that is less than the io_Length indicates that all the data has
been read.  After all the data has been read, a subsequent read must be
performed (one whose io_Actual returns zero) to indicate to the clipboard
device that all the data has been read. This allows random access of the
clip while reading. Providing only valid reads are performed, your program
can seek/read anywhere within the clip by setting the io_Offset field of
the I/O request appropriately.

   Tell The Clipboard You Are Finished Reading.
   --------------------------------------------
   Your application must perform an extra read (one whose io_Actual
   returns zero) to indicate to the clipboard device that all data has
   been read, if io_Actual is not already zero.

The data you read from the clipboard will be in IFF format.  Conversion
from IFF may be necessary depending on your application.

   Iffparse That Data!
   -------------------
   Keep in mind that the functions in the iffparse.library can be used
   to read data from the clipboard. See the "[IFFParse Library](libraries/33-iffparse-library.md)"
   chapter of the Amiga ROM Kernel Reference Manual: Libraries for more
   information.

