---
title: printer.device/PRD_SETERRHOOK
manual: autodocs-3.5
chapter: autodocs-3.5
section: printer-device-prd-seterrhook
functions: []
libraries: []
---

# printer.device/PRD_SETERRHOOK

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	PRD_SETERRHOOK -- set a hook for error messages (V44)

   FUNCTION
	This command sets a hook that will be called if the printer.device
	returns with an error from any other I/O command. This allows
	printer drivers to use private error messages.

   IO REQUEST
	io_Message	mn_ReplyPort set if quick I/O is not possible
	io_Device	preset by the call to [OpenDevice](autodocs-3.5/serial-device-opendevice-2.md)
	io_Command	PRD_SETERRORHOOK
	io_Hook		a pointer to a hook that will be called

	Two standard hook values a defined:

	PDHOOK_NONE	no error hook is to be used
	PDHOOK_STD	EasyRequest() is used to display the error message

	The hook gets a pointer to the [IORequest](autodocs-3.5/include-exec-io-h.md) that caused the error as
	the object and a pointer to the following structure as message:

struct [PrtErrMsg](autodocs-3.5/include-devices-printer-h.md) {
	ULONG pe_Version;
	ULONG pe_ErrorLevel;
	struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *pe_Window; /* window for EasyRequest() */
	struct [EasyStruct](autodocs-3.5/include-intuition-intuition-h.md) *pe_ES;
	ULONG *pe_IDCMP;
	[APTR](autodocs-3.5/include-exec-types-h.md) pe_ArgList;
};
	pe_Version	the message version number PDHOOK_VERSION
	pe_ErrorLevel	one of RETURN_WARN, RETURN_ERROR, RETURN_FAIL
	pe_Window	a window pointer (for EasyRequest()) or NULL
	pe_ES		a pointer to the error message structure
	pe_IDCMP	a pointer to IDCMP Flags for EasyRequest()
	pe_ArgList	a pointer to an array of arguments

	The simplest case is to use that structure to call EasyRequest()
	or to [printf()](autodocs-3.5/amiga-lib-printf-2.md) a message to a console (use the error message from
	pe_ES and the pe_ArgList).

