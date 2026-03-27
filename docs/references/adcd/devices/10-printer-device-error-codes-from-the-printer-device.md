---
title: 10 Printer Device / Error Codes from the Printer Device
manual: devices
chapter: devices
section: 10-printer-device-error-codes-from-the-printer-device
functions: [AbortIO]
libraries: [timer.device]
---

# 10 Printer Device / Error Codes from the Printer Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The printer device returns error codes whenever an operation is attempted.
There are two types of error codes that can be returned.  Printer device
error codes have positive values; Exec I/O error codes have negative
values. Therefore, an application should check for a non-zero return code
as evidence of an error, not simply a value greater than zero.

   PrintIO->ios.io_Length   = strlen(outbuffer);
   PrintIO->ios.io_Data     = (APTR)outbuffer;
   PrintIO->ios.io_Command  = PRD_RAWWRITE;
   if (DoIO((struct IORequest *)PrintIO))

```c
       printf("RAW Write failed.  Error: %d ",PrintIO->ios.io_Error);
```
The error is found in io_Error.


                  PRINTER DEVICE ERROR CODES
   Error                   Value Explanation
   -----                   ----- -----------
   PDERR_NOERR               0   Operation successful
   PDERR_CANCEL              1   User canceled request
   PDERR_NOTGRAPHICS         2   Printer cannot output graphics
   PDERR_INVERTHAM           3   OBSOLETE
   PDERR_BADDIMENSION        4   Print dimensions are illegal
   PDERR_DIMENSIONOVERFLOW   5   OBSOLETE
   PDERR_INTERNALMEMORY      6   No memory available for internal variables
   PDERR_BUFFERMEMORY        7   No memory available for print buffer


                      EXEC ERROR CODES
   Error                   Value Explanation
   ----                    ----- -----------
   IOERR_OPENFAIL           -1   Device failed to open
   IOERR_ABORTED            -2   Request terminated early (after AbortIO())
   IOERR_NOCMD              -3   Command not supported by device
   IOERR_BADLENGTH          -4   Not a valid length

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
