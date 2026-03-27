---
title: II-49/ListDir.c
manual: amiga-mail
chapter: amiga-mail
section: ii-49-listdir-c
functions: [IoErr, Output]
libraries: [dos.library]
---

# II-49/ListDir.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ListDir.c - Amiga Mail simple ExAll() example.
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 ListDir.c
slink from ListDir.o to ListDir lib lib:amiga.lib ;if you don't have pragmas
quit
 *
 * Pure code if pragmas are used.
 * Tuesday, 16-Jul-91 16:21:14, Ewout
 *
 * Compiled with SAS/C 6.56
 */
/*
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

#include <exec/memory.h>
#include <dos/dosextens.h>
#include <dos/rdargs.h>
#include <dos/exall.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

/* undef PRAGMAS if you don't have them */
#define PRAGMAS
#undef PRAGMAS
#ifdef PRAGMAS
#include <pragmas/exec_pragmas.h>
#include <pragmas/dos_pragmas.h>
#else
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;

#endif

/* Buffersize to receive filenames in */
#define BUFFERSIZE 512

VOID            main(VOID);

VOID
main(VOID)
{
#ifdef PRAGMAS

```c
    struct DosLibrary *DOSBase;
```
#endif

```c
    struct RDArgs  *readargs;
    LONG            rargs[2];
    struct ExAllControl *excontrol;
    struct ExAllData *ead, *buffer;
    UBYTE          *source;
    BPTR            sourcelock;
    BOOL            exmore;
    LONG            error;
```
#ifndef PRAGMAS
```c
    /* set up SysBase */
    SysBase = (*((struct Library **) 4));
```
#endif

```c
    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {

        if (readargs = ReadArgs("DIRECTORY/A", rargs, NULL))
        {

            source = (UBYTE *) rargs[0];

            if (buffer = AllocMem(BUFFERSIZE, MEMF_CLEAR))
            {

                if (sourcelock = Lock(source, SHARED_LOCK))
                {
                    if (excontrol = AllocDosObject(DOS_EXALLCONTROL, NULL))
                    {
                        excontrol->eac_LastKey = 0;

                        do
                        {

                            exmore = ExAll(sourcelock,
                                           buffer,
                                           BUFFERSIZE,
                                           ED_NAME,
                                           excontrol);
                            error = IoErr();
                            if ((exmore == NULL &&
                                (error != ERROR_NO_MORE_ENTRIES)))
                                break;

                            if (excontrol->eac_Entries == 0)
                                continue;

                            ead = buffer;
                            do
                            {

                                /* Check for CTRL-C */
                                if (SetSignal(0L, SIGBREAKF_CTRL_C) &
                                        SIGBREAKF_CTRL_C)
                                {
                                    error = ERROR_BREAK;
                                    exmore = FALSE;
                                    break;
                                }

                                rargs[0] = (LONG) ead->ed_Name;
                                VFPrintf(Output(), "%s\n", rargs);

                                ead = ead->ed_Next;
                            } while (ead);
                        } while (exmore);

                        if (error != ERROR_NO_MORE_ENTRIES)
                            PrintFault(error, NULL);

                        FreeDosObject(DOS_EXALLCONTROL, excontrol);
                    }
                    else
                        PrintFault(ERROR_NO_FREE_STORE, NULL);

                    UnLock(sourcelock);
                }
                else
                    PrintFault(IoErr(), source);

                FreeMem(buffer, BUFFERSIZE);
            }
            else
                PrintFault(ERROR_NO_FREE_STORE, NULL);
            FreeArgs(readargs);

        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
```
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
