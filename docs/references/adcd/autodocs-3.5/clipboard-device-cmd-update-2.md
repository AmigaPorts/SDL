---
title: clipboard.device/CMD_UPDATE
manual: autodocs-3.5
chapter: autodocs-3.5
section: clipboard-device-cmd-update-2
functions: []
libraries: []
---

# clipboard.device/CMD_UPDATE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CMD_UPDATE -- Terminate the writing of a clip to the clipboard.

   FUNCTION
	Indicate to the clipboard that the previous write commands are
	complete and can be used for any pending pastes (reads).  This
	command cannot be issued while any of the write commands are
	pending.

   IO REQUEST
	io_Message	mn_ReplyPort set up
	io_Device	preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CMD_UPDATE
	io_ClipID	the ClipID of the write

   RESULTS
	io_Error	non-zero if an error occurred

