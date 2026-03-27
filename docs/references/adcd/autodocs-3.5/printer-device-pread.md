---
title: printer.device/PRead
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-pread
functions: []
libraries: []
---

# printer.device/PRead

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRead - internal read from printer port

   SYNOPSIS
	error = (*PrinterData->pd_PRead)(buffer, length, tv);
	D0

	[LONG](autodocs-3.5/include-exec-types-h.md) PRead(UBYTE *, ULONG *, struct [timeval](autodocs-3.5/include-devices-timer-h.md) *);

   FUNCTION
	PRead reads a buffer of data from the printer port. The variable
	length points to is set to the actual number of read bytes.

	tv points to a struct [timeval](autodocs-3.5/include-devices-timer-h.md) or is NULL in which case the default
	time is PrinterExtendedData.ped_TimeoutSecs. If the time of tv
	ellapes before the [CMD_READ](autodocs-3.5/trackdisk-device-cmd-read-2.md) at the printer port is done two different
	things may happen: If at least one char is read PRead() returns. If
	no char is read but [PQuery](autodocs-3.5/printer-device-pquery.md) returns a value larger 0 the read is
	repeated with that length to read all outstanding data.

