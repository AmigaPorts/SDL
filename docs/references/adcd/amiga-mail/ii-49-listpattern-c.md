---
title: II-49/ListPattern.c
manual: amiga-mail
chapter: amiga-mail
section: ii-49-listpattern-c
functions: [IoErr, MatchFirst, MatchNext, Output, ReadArgs]
libraries: [dos.library]
---

# II-49/ListPattern.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ListPattern.c - AmigaMail MatchFirst()/MatchNext() example.
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 ListPattern.c
slink from ListPattern.o to ListPattern lib lib:amiga.lib ;if you don't have pragmas
quit
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

VOID            main(VOID);
UWORD           StrLen(UBYTE *);

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
    LONG            rargs[1];
    LONG            vargs[4];
    UBYTE          *pattern;
    struct AnchorPath *anchorpath;
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
        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("PATTERN/A", rargs, NULL))
        {
            pattern = (UBYTE *) rargs[0];
            if (anchorpath = AllocMem(sizeof(struct AnchorPath) + 512, MEMF_CLEAR))
            {
                anchorpath->ap_Strlen = 512;
                anchorpath->ap_BreakBits = SIGBREAKF_CTRL_C;

                if ((error = MatchFirst(pattern, anchorpath)) == 0)
                {
                    do
                    {
                        vargs[0] = (LONG) anchorpath->ap_Buf;
                        VFPrintf(Output(), "%s\n", vargs);
                    } while ((error = MatchNext(anchorpath)) == 0);
                }

                MatchEnd(anchorpath);

                if (error != ERROR_NO_MORE_ENTRIES)
                    PrintFault(error, NULL);

                FreeMem(anchorpath, sizeof(struct AnchorPath) + 512);
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
- [MatchFirst — dos.library](../autodocs/dos.library.md#matchfirst)
- [MatchNext — dos.library](../autodocs/dos.library.md#matchnext)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
