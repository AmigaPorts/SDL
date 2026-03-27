---
title: printer.device/PRD_READPREFS
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-readprefs
functions: []
libraries: []
---

# printer.device/PRD_READPREFS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_READPREFS - read the current driver preferences in a buffer (V44)

   FUNCTION
	This is a non standard read command that reads the driver
	preferences.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Command	PRD_READPREFS
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	the size of the buffer in io_Data
	io_Data		a buffer
	io_Actual	the number of bytes copied to the buffer.

	If the read fails because the buffer is too small you should double
	the size of the buffer and try it again.

	Never interpret the contents of the buffer. You are allowed to save
	it to file (as one block of data) and of course to write it back to
	the driver (PRD_WRITEPREFS).

	If you close the printer device between [PRD_EDITPREFS](autodocs-3.5/printer-device-prd-editprefs.md) and the
	actual printing (CMD_WRITE or PRD_DUMPRPORTTAGS) you must read
	the prefs after [PRD_EDITPREFS](autodocs-3.5/printer-device-prd-editprefs.md) and write it back before printing
	or the driver may forget the user changes.

