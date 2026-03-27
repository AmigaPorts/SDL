---
title: parallel.device/PDCMD_SETPARAMS
manual: autodocs-2.0
chapter: autodocs-2.0
section: parallel-device-pdcmd-setparams
functions: []
libraries: []
---

# parallel.device/PDCMD_SETPARAMS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetParams -- change parameters for the parallel device
FUNCTION

```c
    This command allows the caller to change the EOFMODE parameter for
    the parallel port device. It will disallow changes if any reads or
    writes are active or queued.

    The PARB_EOFMODE bit of io_ParFlags controlls whether the
    io_PTermArray is to be used as an additional termination criteria
    for reads and writes.  It may be set directly without a call to
    SetParams, setting it here performs the additional service of
    copying the PTermArray into the device default array which is used
    as the initial array for subsequent device opens. The Shared bit
    can be changed here, and overrides the current device access mode
    set at [OpenDevice](autodocs-2.0/parallel-device-opendevice.md) time.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/parallel-device-opendevice.md)
    io_Command      PDCMD_SETPARAMS (0A)
                    NOTE that the following fields of your [IORequest](autodocs-2.0/includes-exec-io-h.md)
                    are filled by Open to reflect the parallel device's
                    current configuration.
    io_PExtFlags    must be set to zero, unless used
    io_ParFlags     see definition in parallel.i or parallel.h
                    NOTE that x00 yields exclusive access, PTermArray
                    inactive.
    io_PTermArray   ASCII descending-ordered 8-byte array of
                    termination characters. If less than 8 chars
                    used, fill out array w/lowest valid value.
                    Terminators are used only if EOFMODE bit of
                    io_Parflags is set. (e.g. x512F040303030303 )
                    This field is filled on [OpenDevice](autodocs-2.0/parallel-device-opendevice.md) only if the
                    EOFMODE bit is set.
```
RESULTS

    io_Error -- if the SetParams succeded, then io_Error will be null.
                if the SetParams failed, then io_Error will be non-zero.
