---
title: narrator.device/CloseDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: narrator-device-closedevice
functions: []
libraries: []
---

# narrator.device/CloseDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseDevice - terminates access to the narrator device
SYNOPSIS

```c
    CloseDevice(IORequest)
                   A1
```
FUNCTION

```c
    Close invalidates the IO_UNIT and IO_DEVICE fields in the
    [IORequest](autodocs-2.0/includes-exec-io-h.md) block, preventing subsequent IO until another
    [OpenDevice](autodocs-2.0/narrator-device-opendevice.md).  CloseDevice also reduces the open count.  If
    the count goes to 0 and the expunge bit is set, the device
    is expunged.  If the open count goes to zero and the delayed
    expunge bit is not set, CloseDevice sets the expunge bit.
```
INPUTS

```c
    A valid [IORequest](autodocs-2.0/includes-exec-io-h.md) block with its io_Message structure, and
    io_Device and io_Unit fields properly initialized.  These
    fields are initialized by [OpenDevice](autodocs-2.0/narrator-device-opendevice.md).
```
RESULTS

```c
    CloseDevice invalidates the unit and device pointers in the
    [IORequest](autodocs-2.0/includes-exec-io-h.md) block.
```
SEE ALSO

