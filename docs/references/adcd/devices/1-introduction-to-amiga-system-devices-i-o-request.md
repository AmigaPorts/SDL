---
title: 1 Introduction to Amiga System Devices / I/O Request Completion
manual: devices
chapter: devices
section: 1-introduction-to-amiga-system-devices-i-o-request
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# 1 Introduction to Amiga System Devices / I/O Request Completion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A device will set the io_Error field of the I/O request to indicate the
success or failure of an operation.  The indication will be either zero
for success or a non-zero error code for failure.  There are two types of
error codes:  Exec I/O and device specific. Exec I/O errors are defined in
the include file exec/[errors.h](autodocs-2.0/includes-exec-errors-h.md); device specific errors are defined in the
include file for each device.  You should always check that the operation
you requested was successful.

The exact method for checking io_Error can depend on whether you use
[DoIO()](autodocs-2.0/exec-library-doio.md) or [SendIO()](autodocs-2.0/exec-library-sendio.md).   In both cases, io_Error will be set when the I/O
request is returned, but in the case of [DoIO()](autodocs-2.0/exec-library-doio.md), the [DoIO()](autodocs-2.0/exec-library-doio.md) function itself
returns the same value as io_Error.

This gives you the option of checking the function return value:

  SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
  SerialIO->IOSer.io_Data  = ReadBuffer;
  SerialIO->IOSer.io_Command  = CMD_READ;
  if (DoIO((struct IORequest *)SerialIO);

```c
      printf("Read failed.  Error: %ld\n",SerialIO->IOSer.io_Error);
```
Or you can check io_Error directly:

  SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
  SerialIO->IOSer.io_Data  = ReadBuffer;
  SerialIO->IOSer.io_Command  = CMD_READ;
  DoIO((struct IORequest *)SerialIO);

  if (SerialIO->IOSer.io_Error)

```c
      printf("Read failed.  Error: %ld\n",SerialIO->IOSer.io_Error);
```
Keep in mind that checking io_Error is the only way that I/O requests sent
by [SendIO()](autodocs-2.0/exec-library-sendio.md) can be checked.

Testing for a failed I/O request is a minimum step, what you do beyond
that depends on your application.  In some instances, you may decide to
resend the I/O request, and in others, you may decide to stop your
application.   One thing you'll almost always want to do is to inform the
user that an error has occurred.

   Exiting The Correct Way.
   ------------------------
   If you decide that you must prematurely end your application, you
   should deallocate, release, give back and let go of everything you
   took to run the application.  In other words, you should exit
   gracefully.

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
