---
title: printer.device/PQuery
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-pquery
functions: []
libraries: []
---

# printer.device/PQuery

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PQuery - read number of chars in input buffer

   SYNOPSIS
	error = (*PrinterData->pd_PQuery)(*length);
	D0

	[LONG](autodocs-3.5/include-exec-types-h.md) PRead(LONG *);

   FUNCTION
   	PQuery reads the number of data in the input buffer which can be
   	read from the printer port. The variable length points to is set
   	to the number of readable chars.

