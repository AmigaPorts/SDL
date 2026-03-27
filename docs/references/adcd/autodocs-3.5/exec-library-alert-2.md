---
title: exec.library/Alert
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-alert-2
functions: []
libraries: []
---

# exec.library/Alert

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Alert -- alert the user of an error

   SYNOPSIS
	Alert(alertNum)
	      D7

	void Alert(ULONG);

   FUNCTION
	Alerts the user of a serious system problem.  This function will
	bring the system to a grinding halt, and do whatever is necessary
	to present the user with a message stating what happened.
	Interrupts are disabled, and an attempt to post the alert is made.
	If that fails, the system is reset.  When the system comes up
	again, Exec notices the cause of the failure and tries again to
	post the alert.

	If the Alert is a recoverable type, this call MAY return.

	This call may be made at any time, including interrupts.
	(Well, only in interrupts if it is non-recoverable)

	New, for V39:
	The alert now times out based on the value in LastAlert[3]
	This value is transfered accross warm-reboots and thus will let
	you set it once.  The value is the number of frames that need to
	be displayed before the alert is auto-answered.  A value of
	0 will thus make the alert never be displayed.  Note that
	it is recommended that applications *NOT* change the value in
	LastAlert[] since the main reason for this is to make
	unattended operation of the Amiga (in production enviroments)
	possible.

   POST-MORTEM DIAGNOSIS
	There are several options for determining the cause of a crash.
	Descriptions of each alert number can be found in the "alerts.h"
	include file.

	A remote terminal can be attached to the Amiga's first built-in
	serial port.  Set the communication parameters to 9600 baud, 8 bits,
	no parity.  Before resetting the machine, the Alert function will
	blink the power LED 10 times.  While the power indicator is flashing,
	pressing DELETE on the remote terminal will invoke the ROM debugger.

   INPUT
	alertNum   - a number indicating the particular alert.  -1 is
	             not a valid input.

   NOTE
	Much more needs to be said about this function and its implications.

   SEE ALSO
	[exec/alerts.h](autodocs-3.5/include-exec-alerts-h.md)

