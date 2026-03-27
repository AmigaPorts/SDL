---
title: printer.device/PRD_RAWWRITE
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-rawwrite-2
functions: []
libraries: []
---

# printer.device/PRD_RAWWRITE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_RAWWRITE -- transparent write command

   FUNCTION
	This is a non standard write command that performs no
	processing on the data passed to it.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Command	PRD_RAWWRITE
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	the number of bytes in io_Data
	io_Data		the raw bytes to write to the printer

