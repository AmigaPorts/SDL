---
title: keyboard.device/KBD_REMRESETHANDLER
manual: autodocs-3.5
chapter: autodocs-3.5
section: keyboard-device-kbd-remresethandler-2
functions: []
libraries: []
---

# keyboard.device/KBD_REMRESETHANDLER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	KBD_REMRESETHANDLER -- [Remove](autodocs-3.5/exec-library-remove-2.md) a keyboard reset handler.

   FUNCTION
	[Remove](autodocs-3.5/exec-library-remove-2.md) a function previously added to the list of reset
	handler functions with [KBD_ADDRESETHANDLER](autodocs-3.5/keyboard-device-kbd-addresethandler-2.md).

   IO REQUEST
	io_Message	mn_ReplyPort set
	io_Device	preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	KBD_REMRESETHANDLER
	io_Data		a pointer to the handler interrupt structure.

