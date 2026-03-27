---
title: printer.device/CallErrHook
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-callerrhook
functions: []
libraries: []
---

# printer.device/CallErrHook

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CallErrHook -- internal call of error hook

   SYNOPSIS
	result = (*PrinterData->pd_CallErrHook)(hook, iorequest, msg);
	D0

	[LONG](autodocs-3.5/include-exec-types-h.md) CallErrHook(struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *, struct [IORequest](autodocs-3.5/include-exec-io-h.md) *, struct [PrtErrMsg](autodocs-3.5/include-devices-printer-h.md) *);

   FUNCTION
	An application can set an error hook that is called in case of
	errors to display an formated and localized error message to the
	user. The driver can set an error hook to format and localize
	custom error messages and to call the application's error hook. This
	is done by calling PD->pd_CallErrHook() from the printer.device.
	CallErrHook will do additional formating like setting a title of
	the error message if no is set by the driver and then calls the
	application's error hook.

   RESULT
	The return value of the hook is returned from CallErrHook.

