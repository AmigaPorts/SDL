---
title: printer.device/CMD_RESET
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-cmd-reset-2
functions: []
libraries: []
---

# printer.device/CMD_RESET

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_RESET -- reset the printer

   FUNCTION
	CMD_RESET resets the printer device without destroying handles
	to the open device.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_RESET
	io_Flags	IOB_QUICK set if quick I/O is possible

