---
title: printer.device/PWrite
manual: autodocs-2.0
chapter: autodocs-2.0
section: printer-device-pwrite
functions: []
libraries: []
---

# printer.device/PWrite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    PWrite -- internal write to printer port
SYNOPSIS

```c
    error = (*PrinterData->pd_PWrite)(buffer, length);
    D0                                  A0      D0
```
FUNCTION

```c
    PWrite writes 'length' bytes directly to the printer.  This
    function is generally called by printer drivers to send
    their buffer(s) to the printer.

    This function is accessed by referencing off the [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md) (PD)
    structure.  Below is a code fragment to show how to do get access
    to a pointer to the [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md) (PD) structure.

    #include [<exec/types.h>](autodocs-2.0/includes-exec-types-h.md)
    #include [<devices/printer.h>](autodocs-2.0/includes-devices-printer-h.md)
    #include [<devices/prtbase.h>](autodocs-2.0/includes-devices-prtbase-h.md)

    struct [IODRPReq](autodocs-2.0/includes-devices-printer-h.md) PReq;
    struct [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md) *PD;
    struct [PrinterExtendedData](autodocs-2.0/includes-devices-prtbase-h.md) *PED;

    /* open the printer device (any version); if it opened... */
    if (OpenDevice("printer.device", 0, &PReq, 0) == NULL) {

        /* get pointer to printer data structure */
        PD = (struct [PrinterData](autodocs-2.0/includes-devices-prtbase-h.md) *)PReq.io_Device;

        /* write something directly to the printer */
        (*PD->pd_PWrite)("Hello worldn", 12);

        CloseDevice(&PReq); /* close the printer device */
    }
```
