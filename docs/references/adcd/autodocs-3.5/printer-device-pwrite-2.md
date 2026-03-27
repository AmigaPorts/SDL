---
title: printer.device/PWrite
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-pwrite-2
functions: []
libraries: []
---

# printer.device/PWrite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PWrite -- internal write to printer port

   SYNOPSIS
	error = (*PrinterData->pd_PWrite)(buffer, length);
	D0

	[LONG](autodocs-3.5/include-exec-types-h.md) PWrite(UBYTE *, ULONG);

   FUNCTION
	PWrite writes 'length' bytes directly to the printer.  This
	function is generally called by printer drivers to send
	their buffer(s) to the printer.

	This function is accessed by referencing off the [PrinterData](autodocs-3.5/include-devices-prtbase-h.md) (PD)
	structure.  Below is a code fragment to show how to do get access
	to a pointer to the [PrinterData](autodocs-3.5/include-devices-prtbase-h.md) (PD) structure.

	#include [<exec/types.h>](autodocs-3.5/include-exec-types-h.md)
	#include [<devices/printer.h>](autodocs-3.5/include-devices-printer-h.md)
	#include [<devices/prtbase.h>](autodocs-3.5/include-devices-prtbase-h.md)

	struct [IODRPReq](autodocs-3.5/include-devices-printer-h.md) PReq;
	struct [PrinterData](autodocs-3.5/include-devices-prtbase-h.md) *PD;
	struct [PrinterExtendedData](autodocs-3.5/include-devices-prtbase-h.md) *PED;

	/* open the printer device (any version); if it opened... */
	if (OpenDevice("printer.device", 0, &PReq, 0) == NULL) {

	    /* get pointer to printer data structure */
	    PD = (struct [PrinterData](autodocs-3.5/include-devices-prtbase-h.md) *)PReq.io_Device;

	    /* write something directly to the printer */
	    (*PD->pd_PWrite)("Hello worldn", 12);

	    CloseDevice(&PReq); /* close the printer device */
	}

