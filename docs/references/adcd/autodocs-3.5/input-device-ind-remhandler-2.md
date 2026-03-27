---
title: input.device/IND_REMHANDLER
manual: autodocs-3.5
chapter: autodocs-3.5
section: input-device-ind-remhandler-2
functions: []
libraries: []
---

# input.device/IND_REMHANDLER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IND_REMHANDLER -- [Remove](autodocs-3.5/exec-library-remove-2.md) an input handler from the device

   FUNCTION
	[Remove](autodocs-3.5/exec-library-remove-2.md) a function previously added to the list of handler
	functions.

   IO REQUEST
	io_Message	mn_ReplyPort set
	io_Device	preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	IND_REMHANDLER
	io_Data		a pointer to the interrupt structure.

   NOTES
	This command is not immediate

