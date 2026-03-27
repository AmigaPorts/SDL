---
title: dos.library/ErrorReport
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-errorreport
functions: [Fault, IoErr]
libraries: [dos.library]
---

# dos.library/ErrorReport

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ErrorReport -- Displays a Retry/Cancel requester for an error (V36)
```
SYNOPSIS

```c
    status = ErrorReport(code, type, arg1, device)
    D0                    D1    D2    D3     A0

    BOOL ErrorReport(LONG, LONG, ULONG, struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *)
```
FUNCTION

```c
    Based on the request type, this routine formats the appropriate
    requester to be displayed.  If the code is not understood, it returns
    DOS_TRUE immediately.  Returns DOS_TRUE if the user selects CANCEL or
    if the attempt to put up the requester fails, or if the process
    pr_WindowPtr is -1.  Returns FALSE if the user selects Retry.  The
    routine will retry on DISKINSERTED for appropriate error codes.
    These return values are the opposite of what [AutoRequest](autodocs-2.0/intuition-library-autorequest.md) returns.

    Note: this routine sets [IoErr()](autodocs-2.0/dos-library-ioerr.md) to code before returning.
```
INPUTS

```c
    code   - Error code to put a requester up for.
       Current valid error codes are:
            ERROR_DISK_NOT_VALIDATED
            ERROR_DISK_WRITE_PROTECTED
            ERROR_DISK_FULL
            ERROR_DEVICE_NOT_MOUNTED
            ERROR_NOT_A_DOS_DISK
            ERROR_NO_DISK
            ABORT_DISK_ERROR        /* read/write error */
            ABORT_BUSY              /* you MUST replace... */
    type   - Request type:
                   REPORT_LOCK   - arg1 is a lock (BPTR).
                   REPORT_FH     - arg1 is a filehandle (BPTR).
                    REPORT_VOLUME - arg1 is a volumenode (C pointer).
                    REPORT_INSERT - arg1 is the string for the volumename
                                    (will be split on a ':').
                                    With ERROR_DEVICE_NOT_MOUNTED puts
                                    up the "Please insert..." requester.
    arg1   - variable parameter (see type)
    device - (Optional) Address of handler task for which report is to be
            made.  Only required for REPORT_LOCK, and only if arg1==NULL.
```
RESULT

```c
    status - Cancel/Retry indicator (0 means Retry)
```
SEE ALSO

```c
    [Fault()](autodocs-2.0/dos-library-fault.md), [IoErr()](autodocs-2.0/dos-library-ioerr.md)
```

---

## See Also

- [Fault — dos.library](../autodocs/dos.library.md#fault)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
