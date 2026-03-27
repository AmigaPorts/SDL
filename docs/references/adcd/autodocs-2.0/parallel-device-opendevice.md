---
title: parallel.device/OpenDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-opendevice
functions: [OpenDevice]
libraries: [exec.library]
---

# parallel.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Open -- a request to open the parallel port
SYNOPSIS

```c
    error = OpenDevice("parallel.device", unit, ioExtPar, flags)
    D0                  A0                D0    A1        D1
```
FUNCTION

```c
    This function allows the requestor software access to the parallel
    device.  Unless the shared-access bit (bit 5 of io_ParFlags) is
    set, exclusive use is granted and no other access is allowed
    until the owner closes the device.

    A FAST_MODE, can be specified (bit 3 of io_Parflags) to speed up
    transfers to high-speed printers. Rather than waiting for the printer
    to acknowledge a character using the *ACK interrupt, this mode will
    send out data as long as the BUSY signal is low. The printer must be
    able to raise the BUSY signal within 3 micro-seconds on A2630s,
    otherwise data will be lost. Should be used only in an exclusive-
    access OpenDevice().

    A SLOWMODE mode can be specified (bit 4 of io_ParFlags) when very
    slow printers are used. If the printer acknowledges data at less
    than 5000 bytes per second, then this mode will actually save CPU
    time, although it consumes much more with high-speed printers.

    The PTermArray of the ioExtPar is initialized only if the EOFMODE
    bit (bit 1 of io_ParFlags) is set. The PTermArray can be further
    modified using the [PDCMD_SETPARAMS](autodocs-2.0/parallel-device-pdcmd-setparams.md) command.
```
INPUTS

```c
    "parallel.device" - a pointer to literal string "parallel.device"
    unit - Must be zero for future compatibility
    ioExtPar - pointer to an IO Request block of structure IOExtPar to
               be initialized by the OpenDevice() function. The io_ParFlags
               field must be set as desired.
    flags - Must be zero for future compatibility
```
RESULTS

    d0 -- same as io_Error
    io_Error -- if the Open succeded, then io_Error will be null.
                If the Open failed, then io_Error will be non-zero.
SEE ALSO

```c
    [exec/CloseDevice](autodocs-2.0/serial-device-closedevice.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
