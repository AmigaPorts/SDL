---
title: narrator.device/AbortIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: narrator-device-abortio-2
functions: []
libraries: []
---

# narrator.device/AbortIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AbortIO - Abort an IO request


   SYNOPSIS
	AbortIO(IORequest)
		   A1


   FUNCTION
	Exec library call to abort a specified READ or WRITE request.
	The [IORequest](autodocs-3.5/include-exec-io-h.md) may be in the queue or currently active.  If
	currently active, the request is immediately stopped and then
	removed.


   INPUTS
	Pointer to the [IORequest](autodocs-3.5/include-exec-io-h.md) block to be aborted.


   RESULTS
	io_Error field in the [IORequest](autodocs-3.5/include-exec-io-h.md) block set to #IOERR_ABORTED.


   SEE ALSO

