---
title: keyboard.device/KBD_RESETHANDLERDONE
manual: autodocs-3.5
chapter: autodocs-3.5
section: keyboard-device-kbd-resethandlerdone-2
functions: []
libraries: []
---

# keyboard.device/KBD_RESETHANDLERDONE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	KBD_RESETHANDLERDONE -- Indicate that reset handling is done.

   FUNCTION
	Indicate that reset cleanup associated with the handler has
	completed.  This command should be issued by all keyboard
	reset handlers so that the reset may proceed.

   IO REQUEST
	io_Message	mn_ReplyPort set
	io_Device	preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	KBD_RESETHANDLERDONE
	io_Data		a pointer to the handler interrupt structure.

   NOTES
	The keyboard processor itself performs the hardware reset, and
	will time out and perform the reset even if some reset handlers
	have not indicated yet that the reset may proceed.  This
	timeout is several seconds.

