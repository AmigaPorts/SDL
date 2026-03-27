---
title: input.device/IND_SETMTRIG
manual: autodocs-3.5
chapter: autodocs-3.5
section: input-device-ind-setmtrig-2
functions: []
libraries: []
---

# input.device/IND_SETMTRIG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IND_SETMTRIG -- Set the conditions for a mouse port report

   FUNCTION
	This command sets what conditions must be met by a mouse
	before a pending [Read](autodocs-3.5/dos-library-read-2.md) request will be satisfied.  The trigger
	specification is that used by the gameport device.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Unit		preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	IND_SETMTRIG
	io_Flags	IOB_QUICK set if quick I/O is possible
	io_Length	sizeof(gameportTrigger)
	io_Data		a structure of type GameportTrigger, which
			has the following elements
	    gpt_Keys -
		    GPTB_DOWNKEYS set if button down transitions
		    trigger a report, and GPTB_UPKEYS set if button up
		    transitions trigger a report
	    gpt_Timeout	-
		    a time which, if exceeded, triggers a report;
		    measured in vertical blank units (60/sec)
	    gpt_XDelta	-
		    a distance in x which, if exceeded, triggers a
		    report
	    gpt_YDelta	-
		    a distance in x which, if exceeded, triggers a
		    report

