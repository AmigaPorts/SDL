---
title: console.device/CDInputHandler
manual: autodocs-2.0
chapter: autodocs-2.0
section: console-device-cdinputhandler
functions: []
libraries: []
---

# console.device/CDInputHandler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CDInputHandler -- handle an input event for the console device
SYNOPSIS

```c
    events = CDInputHandler(events, consoleDevice)
                   a0      a1
```
FUNCTION

    Accept input events from the producer, which is usually the
    rom input.task.
INPUTS

    events - a pointer to a list of input events.
    consoleDevice - a pointer to the library base address of the
        console device.  This has the same value as ConsoleDevice
        described below.
RESULTS

    events - a pointer to a list of input events not used by this
        handler.
NOTES

```c
    This function is available for historical reasons.  It is
    preferred that input events be fed to the system via the
    WriteEvent command of the input.device.

    This function is different from standard device commands in
    that it is a function in the console device library vectors.
    In order to obtain a valid library base pointer for the
    console device (a.k.a. ConsoleDevice) call
    OpenDevice("console.device", -1, [IOStdReq](autodocs-2.0/includes-exec-io-h.md), 0),
    and then grab the io_Device pointer field out of the [IOStdReq](autodocs-2.0/includes-exec-io-h.md)
    and use as ConsoleDevice.
```
BUGS

SEE ALSO

    input.device
