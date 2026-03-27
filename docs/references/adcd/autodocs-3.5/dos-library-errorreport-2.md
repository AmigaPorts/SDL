---
title: dos.library/ErrorReport
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-errorreport-2
functions: [Fault, IoErr]
libraries: [dos.library]
---

# dos.library/ErrorReport

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ErrorReport -- Displays a Retry/Cancel requester for an error (V36)

   SYNOPSIS
	status = ErrorReport(code, type, arg1, device)
	D0                    D1    D2    D3     D4

	[BOOL](autodocs-3.5/include-exec-types-h.md) ErrorReport(LONG, [LONG](autodocs-3.5/include-exec-types-h.md), ULONG, struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)

   FUNCTION
	Based on the request type, this routine formats the appropriate
	requester to be displayed.  If the code is not understood, it returns
	DOS_TRUE immediately.  Returns DOS_TRUE if the user selects CANCEL or
	if the attempt to put up the requester fails, or if the process
	pr_WindowPtr is -1.  Returns FALSE if the user selects Retry.  The
	routine will retry on DISKINSERTED for appropriate error codes.
	These return values are the opposite of what [AutoRequest](autodocs-3.5/intuition-library-autorequest-2.md) returns.

	Note: this routine sets [IoErr()](autodocs-3.5/dos-library-ioerr-2.md) to code before returning.

   INPUTS
	code   - Error code to put a requester up for.
	   Current valid error codes are:
		ERROR_DISK_NOT_VALIDATED
		ERROR_DISK_WRITE_PROTECTED
		ERROR_DISK_FULL
		ERROR_DEVICE_NOT_MOUNTED
		ERROR_NOT_A_DOS_DISK
		ERROR_NO_DISK
		ABORT_DISK_ERROR	/* read/write error */
		ABORT_BUSY		/* you MUST replace... */
	type   - [Request](autodocs-3.5/intuition-library-request-2.md) type:
```c
                       REPORT_LOCK   - arg1 is a lock (BPTR).
                       REPORT_FH     - arg1 is a filehandle (BPTR).
```
			REPORT_VOLUME - arg1 is a volumenode (C pointer).
			REPORT_INSERT - arg1 is the string for the volumename
					(will be split on a ':').
					With ERROR_DEVICE_NOT_MOUNTED puts
					up the "Please insert..." requester.
	arg1   - variable parameter (see type)
	device - (Optional) Address of handler task for which report is to be

```c
                made.  Only required for REPORT_LOCK, and only if arg1==NULL.
```
   RESULT
	status - Cancel/Retry indicator (0 means Retry)

   SEE ALSO
	[Fault()](autodocs-3.5/dos-library-fault-2.md), [IoErr()](autodocs-3.5/dos-library-ioerr-2.md)

---

## See Also

- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
