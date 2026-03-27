---
title: printer.device/CMD_FLUSH
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-cmd-flush-2
functions: []
libraries: []
---

# printer.device/CMD_FLUSH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_FLUSH -- abort all I/O requests (immediate)

   FUNCTION
	CMD_FLUSH aborts all stopped I/O at the unit.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_FLUSH
	io_Flags	IOB_QUICK set if quick I/O is possible

