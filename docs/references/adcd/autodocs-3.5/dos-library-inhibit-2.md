---
title: dos.library/Inhibit
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-inhibit-2
functions: []
libraries: []
---

# dos.library/Inhibit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Inhibit -- Inhibits access to a filesystem (V36)

   SYNOPSIS
	success = Inhibit(filesystem, flag)
	D0                    D1       D2

	[BOOL](autodocs-3.5/include-exec-types-h.md) Inhibit(STRPTR,LONG)

   FUNCTION
	Sends an ACTION_INHIBIT packet to the indicated handler.  This stops
	all activity by the handler until uninhibited.  When uninhibited,
	anything may have happened to the disk in the drive, or there may no
	longer be one.

   INPUTS
	filesystem - Name of device to inhibit (with ':')
	flag	   - New status.  DOSTRUE = inhibited, FALSE = uninhibited

   RESULT
	success    - Success/failure indicator

   SEE ALSO

