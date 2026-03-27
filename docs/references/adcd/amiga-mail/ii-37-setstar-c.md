---
title: II-37/SetStar.c
manual: amiga-mail
chapter: amiga-mail
section: ii-37-setstar-c
functions: [IoErr, Output, ReadArgs]
libraries: [dos.library]
---

# II-37/SetStar.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* SetStar.c.   AmigaMail '*' wildcard example. Pure code if pragmas are used.
;* Compiled with SAS/C 6.56
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 SetStar.c
slink from SetStar.o to SetStar lib lib:amiga.lib; if you don't have pragmas
quit
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

#include <exec/types.h>
#include <dos/dosextens.h>
#include <dos/rdargs.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>

/*
 * undef PRAGMAS if you don't have them #define PRAGMAS
 */
#ifdef PRAGMAS
#include <pragmas/exec_pragmas.h>
#include <pragmas/dos_pragmas.h>
#else
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;

#endif

static UBYTE   *VersTag = "\0$VER: SetStar 37.1 (12.07.91)";


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
    LONG            rargs[2];
    UWORD           on, off;
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
        rargs[0] = 0;
        rargs[1] = 0;

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("ON/S,OFF/S", rargs, NULL))
        {
            on = (UWORD) (rargs[0]);
            off = (UWORD) (rargs[1]);

            /*
             * The RNF_WILDSTAR bit in the rn_Flags field indicates whether the
             * '*' should be treated as wildcard or not.
             *
             * Show current setting if both ON & OFF or specified or neither.
             */
            if (on == off)
            {
                if (DOSBase->dl_Root->rn_Flags & RNF_WILDSTAR)
                    rargs[0] = (LONG) "ON";
                else
                    rargs[0] = (LONG) "OFF";
                VFPrintf(Output(), "Wildstar is %s\n", rargs);
            }
            else
            {
                if (on)
                    DOSBase->dl_Root->rn_Flags |= RNF_WILDSTAR;
                else
                    DOSBase->dl_Root->rn_Flags &= ~RNF_WILDSTAR;
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
