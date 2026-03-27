# dos.library/ErrorReport



   NAME
	ErrorReport -- Displays a Retry/Cancel requester for an error (V36)

   SYNOPSIS
	status = ErrorReport(code, type, arg1, device)
	D0                    D1    D2    D3     D4

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) ErrorReport(LONG, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39), ULONG, struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *)

   FUNCTION
	Based on the request type, this routine formats the appropriate
	requester to be displayed.  If the code is not understood, it returns
	DOS_TRUE immediately.  Returns DOS_TRUE if the user selects CANCEL or
	if the attempt to put up the requester fails, or if the process
	pr_WindowPtr is -1.  Returns FALSE if the user selects Retry.  The
	routine will retry on DISKINSERTED for appropriate error codes.
	These return values are the opposite of what [AutoRequest](../Includes_and_Autodocs_3._guide/node0396.html) returns.

	Note: this routine sets [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html) to code before returning.

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
	type   - [Request](../Includes_and_Autodocs_3._guide/node03E5.html) type:
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
	[Fault()](../Includes_and_Autodocs_3._guide/node0161.html), [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html)

