---
title: printer.device/PRD_WRITEPREFS
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-writeprefs
functions: []
libraries: []
---

# printer.device/PRD_WRITEPREFS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_WRITEPREFS - write the current driver prefs from a buffer (V44)

   FUNCTION
	This is a non standard write command that writes the driver
	preferences.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Command	PRD_WRITEPREFS
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	the length of the buffer
	io_Data		a buffer
	io_Actual	the number of bytes copied to the driver prefs.

	The printer driver checks the buffer before copying it to its
	preferences. So you don't have to worry about changing the printer
	driver between [PRD_READPREFS](autodocs-3.5/printer-device-prd-readprefs.md) and PRD_WRITEPREFS.

