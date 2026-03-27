---
title: II-31/SignalNotification.c
manual: amiga-mail
chapter: amiga-mail
section: ii-31-signalnotification-c
functions: [IoErr, Output, ReadArgs]
libraries: [dos.library]
---

# II-31/SignalNotification.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* SignalNotification.c.  Compiled with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 SignalNotification.c
slink from SignalNotification.o to SignalNotification lib lib:amiga.lib
quit

Copyright (c) 1991-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/


#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <dos/dosasl.h>
#include <dos/notify.h>
#include <dos/rdargs.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

/* Use pragmas if you've got them */

static UBYTE   *VersTag = "\0$VER: SignalNotification 37.1 (09.07.91)";
struct Library *DOSBase;
struct ExecBase *SysBase;

VOID            main(VOID);

VOID
main(VOID)
{

```c
    struct RDArgs  *readargs;
    LONG            rargs[2];
    struct NotifyRequest *notifyrequest;
    UBYTE          *filename;
    ULONG           signr, signal;

    /* To appease amiga.lib */
    SysBase = (*((struct Library **) 4));

    /* Fail silently if < 37 */
    if (DOSBase = OpenLibrary("dos.library", 37))
    {
        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("Filename/A", rargs, NULL))
        {
            filename = (UBYTE *) (rargs[0]);

            /* Allocate a NotifyRequest structure */
            if (notifyrequest = AllocMem(sizeof(struct NotifyRequest), MEMF_CLEAR))
            {
                /* And allocate a signalbit */
                if ((signr = AllocSignal(-1L)) != -1)
                {

                    /* Initialize notifcation request */
                    notifyrequest->nr_Name = filename;
                    notifyrequest->nr_Flags = NRF_SEND_SIGNAL | NRF_NOTIFY_INITIAL;
                    /* Signal this task */
                    notifyrequest->nr_stuff.nr_Signal.nr_Task =
                            (struct Task *) FindTask(NULL);
                    /* with this signal bit */
                    notifyrequest->nr_stuff.nr_Signal.nr_SignalNum = signr;

                    if ((StartNotify(notifyrequest)) == DOSTRUE)
                    {
                        /* Loop until Ctrl-C to exit */
                        for (;;)
                        {
                            signal = Wait(1L << signr | SIGBREAKF_CTRL_C);
                            if (signal & (1L << signr))
                                VFPrintf(Output(), "Notification signal!\n", NULL);
                            if (signal & SIGBREAKF_CTRL_C)
                            {
                                EndNotify(notifyrequest);
                                PrintFault(ERROR_BREAK, NULL);
                                break;
                            }
                        }
                    }
                    else
                        PrintFault(ERROR_NOT_IMPLEMENTED, NULL);    /* most logical */

                    FreeSignal(signr);
                }
                else
                    VFPrintf(Output(), "No signal available\n", NULL);
                FreeMem(notifyrequest, sizeof(struct NotifyRequest));
            }
            else
                PrintFault(ERROR_NO_FREE_STORE, NULL);

            FreeArgs(readargs);
        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary(DOSBase);
    }
```
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
