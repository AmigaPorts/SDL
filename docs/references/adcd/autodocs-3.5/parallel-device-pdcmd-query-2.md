---
title: parallel.device/PDCMD_QUERY
manual: autodocs-3.5
chapter: autodocs-3.5
section: parallel-device-pdcmd-query-2
functions: []
libraries: []
---

# parallel.device/PDCMD_QUERY

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Query -- query parallel port/line status

   FUNCTION
	This command return the status of the parallel port lines and
	registers.

   IO REQUEST
	io_Message      must have mn_ReplyPort initialized
	io_Device       set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit         set by [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command      PDCMD_QUERY (09)

   RESULTS
	io_Status        BIT  ACTIVE  FUNCTION

	                 0     high   printer busy toggle (offline)
	                 1     high   paper out
	                 2     high   printer selected on the A1000
	                              printer selected & serial "Ring
	                              Indicator" on the A500/A2000
	                              Use care when making cables.
	                 3      -     read=0,write=1
	               4-7            reserved

   BUGS
	In a earlier version of this AutoDoc, BUSY and PSEL were reversed.
	The function has always been correct.

