---
title: Errors
manual: amiga-mail
chapter: amiga-mail
section: errors
functions: []
libraries: []
---

# Errors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The SANA-II extended IORequest structure (struct IOSana2Req) includes both
the ios2_Error and ios2_WireError fields. Driver users must always check
IOSana2Reqs on return for an error in ios2_Error. ios2_Error will be zero
if no error occurred, otherwise it will contain a value from
<exec/errors.h> or <devices/sana2.h>. If there was an error, there may be
more specific information in ios2_WireError. Drivers are required to fill
in the WireError if there is an applicable error code.

Error codes are #defined in the "defined errors" sections of the file
<devices/sana2.h>:


   IOSana2Req S2io_Error field (S2ERR_xxx):

   S2ERR_NO_RESOURCES     - Insufficient resources available.
   S2ERR_BAD_ARGUMENT     - Noticeably bad argument.
   S2ERR_BAD_STATE        - Command inappropriate for current state.
   S2ERR_BAD_ADDRESS      - Noticeably bad address.
   S2ERR_MTU_EXCEEDED     - Write data too large.
   S2ERR_NOT_SUPPORTED    - Command is not supported by this driver. This
```c
                            is similar to IOERR_NOCMD as defined in
                            <exec/errors.h> but S2ERR_NOT_SUPPORTED
                            indicates that the requested command is a
                            valid SANA-II command and that the driver
                            does not support it because the hardware is
                            incapable of supporting it (e.g.,
                            S2_MULTICAST). Note that IOERR_NOCMD is still
                            valid for reasons other than a lack of
                            hardware support (i.e., commands which are
                            no-ops in a SANA-II driver).
```
   S2ERR_SOFTWARE         - Software error of some kind.
   S2ERR_OUTOFSERVICE     - When a hardware device is taken off-line, any


                            pending requests are returned with this error.
See also the standard errors in <exec/errors.h>.


   IOSana2Req S2io_WireError field (S2WERR_xxx):

   S2WERR_NOT_CONFIGURED  - Command requires unit to be configured.
   S2WERR_UNIT_ONLINE     - Command requires that the unit be off-line.
   S2WERR_UNIT_OFFLINE    - Command requires that the unit be on-line.
   S2WERR_ALREADY_TRACKED - Protocol is already being tracked.
   S2WERR_NOT_TRACKED     - Protocol is not being tracked.
   S2WERR_BUFF_ERROR      - Buffer management function returned an error.
   S2WERR_SRC_ADDRESS     - Problem with the source address field.
   S2WERR_DST_ADDRESS     - Problem with destination address field.
   S2WERR_BAD_BROADCAST   - Problem with an attempt to broadcast.
   S2WERR_BAD_MULTICAST   - Problem with an attempt to multicast.
   S2WERR_MULTICAST_FULL  - Multicast address list full.
   S2WERR_BAD_EVENT       - Event specified is unknown.
   S2WERR_BAD_STATDATA    - The S2IO_StatData pointer or the data it
                            points to failed a sanity check.
   S2WERR_IS_CONFIGURED   - Attempt to reconfigure the unit.
   S2WERR_NULL_POINTER    - A NULL pointer was detected in one of the

                            arguments. S2ERR_BAD_ARGUMENT should always
                            be the S2ERR.
