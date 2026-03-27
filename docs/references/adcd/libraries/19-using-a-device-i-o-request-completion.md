---
title: 19 / Using A Device / I/O Request Completion
manual: libraries
chapter: libraries
section: 19-using-a-device-i-o-request-completion
functions: [DoIO, SendIO]
libraries: [exec.library]
---

# 19 / Using A Device / I/O Request Completion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A device will set the [io_Error](autodocs-2.0/includes-exec-io-h.md) field of the I/O request to indicate the
success or failure of an operation.  The indication will be either zero
for success or a non-zero error code for failure. There are two types of
error codes:  Exec I/O and device specific. Exec I/O errors are defined in
the include file <exec/[errors.h](autodocs-2.0/includes-exec-errors-h.md)>; device specific errors are defined in
the include file for each device.  You should always check that the
operation you requested was successful.

The exact method for checking [io_Error](autodocs-2.0/includes-exec-io-h.md) can depend on whether you use
[DoIO()](libraries/19-exec-device-i-o-using-a-device.md) or [SendIO()](libraries/19-exec-device-i-o-using-a-device.md).  In both cases, io_Error will be set when the I/O
request is returned, but in the case of DoIO(), the DoIO() function itself
returns the same value as io_Error.  This gives you the option of checking
the function return value:


```c
    SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
    SerialIO->IOSer.io_Data     = ReadBuffer;
    SerialIO->IOSer.io_Command  = CMD_READ;
    if (DoIO((struct IORequest *)SerialIO)
        printf("Read failed.  Error: %ld\n",SerialIO->IOSer.io_Error);
```
Or you can check io_Error directly:


```c
    SerialIO->IOSer.io_Length   = sizeof(ReadBuffer);
    SerialIO->IOSer.io_Data     = ReadBuffer;
    SerialIO->IOSer.io_Command  = CMD_READ;
    DoIO((struct IORequest *)SerialIO);
    if (SerialIO->IOSer.io_Error)
        printf("Read failed.  Error: %ld\n",SerialIO->IOSer.io_Error);
```
Keep in mind that checking [io_Error](autodocs-2.0/includes-exec-io-h.md) is the only way that I/O requests sent
by [SendIO()](libraries/19-exec-device-i-o-using-a-device.md) can be checked.  Testing for a failed I/O request is a minimum
step, what you do beyond that depends on your application.  In some
instances, you may decide to resend the I/O request and in others, you may
decide to stop your application. One thing you'll almost always want to do
is to inform the user that an error has occurred.


    Exiting The Correct Way.
    ------------------------
    If you decide that you must prematurely end your application, you
    should deallocate, release, give back and let go of everything you
    took to run the application.  In other words, you should exit
    gracefully.
 [Closing the Device](libraries/19-i-o-request-completion-closing-the-device.md)    [Ending Device Access](libraries/19-i-o-request-completion-ending-device-access.md) 

---

## See Also

- [DoIO — exec.library](../autodocs/exec.library.md#doio)
- [SendIO — exec.library](../autodocs/exec.library.md#sendio)
