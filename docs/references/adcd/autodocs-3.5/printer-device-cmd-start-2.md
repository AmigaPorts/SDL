---
title: printer.device/CMD_START
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-cmd-start-2
functions: []
libraries: []
---

# printer.device/CMD_START

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_START -- restart after stop (immediate)

   FUNCTION
	CMD_START restarts the unit after a stop command.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_START
	io_Flags	IOB_QUICK set if quick I/O is possible

