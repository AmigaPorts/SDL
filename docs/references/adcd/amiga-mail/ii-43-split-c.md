---
title: II-43/Split.c
manual: amiga-mail
chapter: amiga-mail
section: ii-43-split-c
functions: [IoErr, Output, ReadArgs, SplitName]
libraries: [dos.library]
---

# II-43/Split.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Split.c - AmigaMail SplitName() example.  Compiled with SAS/C 6.56.
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 Split.c
slink from Split.o to Split lib lib:amiga.lib ; if you don't have pragmas
quit
* Tuesday, 16-Jul-91 12:15:49, Ewout
*
*
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

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

/* def PRAGMAS if you have them */
/* #define PRAGMAS */
#ifdef PRAGMAS
#include <pragmas/exec_pragmas.h>
#include <pragmas/dos_pragmas.h>
#else
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;

#endif

#define BUFFERSIZE      128

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
    UBYTE          *filename, *buffer;
    ULONG           buffersize;
    WORD            position = 0;
    LONG            vargs[4];
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

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("FILE/A,BUFFERSIZE/A/N", rargs, NULL))
        {
            filename = (UBYTE *) rargs[0];
            buffersize = *((LONG *) rargs[1]);
            if (buffersize < 1 || buffersize > 4096)
                buffersize = BUFFERSIZE;

            if (buffer = AllocMem(buffersize, MEMF_CLEAR))
            {
                position = SplitName(filename, ':', buffer, position, buffersize);

                vargs[0] = position;
                vargs[1] = (LONG) buffer;
                VFPrintf(Output(), "Devicename: position: %ld Buffer: %s\n", vargs);

                if (position == -1)
                    position = 0;

                do
                {
                    position =
                        SplitName(filename, '/', buffer, position, buffersize);
                    vargs[0] = position;
                    vargs[1] = (LONG) buffer;
                    VFPrintf(Output(),
                             "Path component: position: %ld Buffer: %s\n",
                             vargs);
                } while (position != -1);
                FreeMem(buffer, buffersize);
            }
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
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [SplitName — dos.library](../autodocs/dos.library.md#splitname)
