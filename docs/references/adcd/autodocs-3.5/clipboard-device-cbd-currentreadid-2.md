---
title: clipboard.device/CBD_CURRENTREADID
manual: autodocs-3.5
chapter: autodocs-3.5
section: clipboard-device-cbd-currentreadid-2
functions: []
libraries: []
---

# clipboard.device/CBD_CURRENTREADID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CBD_CURRENTREADID - Determine the current read identifier.

   FUNCTION
	CBD_CURRENTREADID fills the io_ClipID with a clip identifier that
	can be compared with that of a post command: if greater than
	the post identifier then the post data held privately by an
	application is not valid for its own pasting.

   IO REQUEST
	io_Message	mn_ReplyPort set up
	io_Device	preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	CBD_CURRENTREADID

   RESULTS
	io_ClipID	the ClipID of the current write is set

