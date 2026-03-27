---
title: Includes/exec/errors.h
manual: autodocs-2.0
chapter: autodocs-2.0
section: includes-exec-errors-h
functions: [AbortIO]
libraries: [timer.device]
---

# Includes/exec/errors.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#ifndef	EXEC_ERRORS_H
#define	EXEC_ERRORS_H
/*
**	$Filename: exec/errors.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.6 $
**	$Date: 90/05/27 $
**
**	Standard Device IO Errors (returned in io_Error)
**
**	(C) Copyright 1985-1999 Amiga, Inc.
**	    All Rights Reserved
*/

#define IOERR_OPENFAIL	 (-1) /* device/unit failed to open */
#define IOERR_ABORTED	 (-2) /* request terminated early [after AbortIO()] */
#define IOERR_NOCMD	 (-3) /* command not supported by device */
#define IOERR_BADLENGTH	 (-4) /* not a valid length (usually IO_LENGTH) */
#define IOERR_BADADDRESS (-5) /* invalid address (misaligned or bad range) */
#define IOERR_UNITBUSY	 (-6) /* device opens ok, but requested unit is busy */
#define IOERR_SELFTEST	 (-7) /* hardware failed self-test */

#endif	/* EXEC_ERRORS_H */

---

## See Also

- [AbortIO — timer.device](../autodocs/timer.device.md#abortio)
