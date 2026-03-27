---
title: II-37/Pattern.c
manual: amiga-mail
chapter: amiga-mail
section: ii-37-pattern-c
functions: [IoErr, MatchPattern, Output, ParsePattern, ReadArgs]
libraries: [dos.library]
---

# II-37/Pattern.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Pattern.c.   AmigaMail pattern matching example.  Compiled with SAS/C 6.56:
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 Pattern.c
slink from Pattern.o to Pattern lib lib:amiga.lib
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

#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <dos/dosasl.h>
#include <dos/rdargs.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/utility_protos.h>

/* define pragmas if you have them
#define PRAGMAS */
#ifdef PRAGMAS
#include <pragmas/exec_pragmas.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/utility_pragmas.h>
#else
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;
struct Library *UtilityBase;
#endif

VOID            main(VOID);
UWORD           StrLen(UBYTE *);

VOID main(VOID)
{
#ifdef PRAGMAS

```c
    struct DosLibrary *DOSBase;
    struct Library *UtilityBase;
```
#endif


```c
    struct RDArgs  *readargs;
    LONG            rargs[3];
    LONG            vargs[4];
    UBYTE         **strings;
    UBYTE          *pattern, *parsebuffer;
    UWORD           case_sensitive, buffersize;
    LONG            iswild, success;
    COUNT           i;
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
        UtilityBase = DOSBase->dl_UtilityBase;

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("PATTERN/A,CASE/S,STRINGS/A/M", rargs, NULL))
        {

            /* The pattern. */
            pattern = (UBYTE *) (rargs[0]);

            /*
             * Case sensitive or not? (default not. Note filename matching
             * should ALWAYS be case insensitive).
             */
            case_sensitive = (UWORD) (rargs[1]);

            /* Pointer to array of strings to match */
            strings = (UBYTE **) (rargs[2]);

            /* Get a buffer big enough to hold all the tokens */
            buffersize = StrLen(pattern) * 3;

            if (parsebuffer = AllocMem(buffersize, MEMF_CLEAR))
            {

                /* Parse the pattern, according to case sensitivity flag */
                if (case_sensitive)
                    iswild = ParsePattern(pattern, parsebuffer, buffersize);
                else
                {
                    /* make pattern uppercase in case of character classes */
                    i = 0;
                    while (pattern[i])
                        pattern[i] = ToUpper(pattern[i++]);
                    iswild = ParsePatternNoCase(pattern, parsebuffer, buffersize);
                }

                /*
                 * -1 if ParsePattern() failed, 0 for no wildcards, 1 for
                 * wildcards. For this I don't care if the supplied pattern had
                 * wildcards or not.
                 */
                if (iswild != -1)
                {
                    /* The array of strings is terminated with a NULL */
                    while (*strings)
                    {

                        /*
                         * MatchPattern() returns 1 for a successful match, 0
                         * for no match
                         */
                        if (case_sensitive)
                            success = MatchPattern(parsebuffer, *strings);
                        else
                            success = MatchPatternNoCase(parsebuffer, *strings);
                        if (success)
                        {
                            vargs[0] = (LONG) * strings;
                            VFPrintf(Output(), "Match: %s\n", vargs);
                        }
                        else
                        {
                            if (IoErr() != 0)
                            {
                                VFPrintf(Output(), "Overflow\n", NULL);
                                break;
                            }
                        }
                        strings++;
                    }
                }
                else
                    PrintFault(ERROR_BAD_TEMPLATE, pattern);
                FreeMem(parsebuffer, buffersize);
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

UWORD StrLen(UBYTE * string)
{
```c
    UBYTE          *length = string + 1;

    while (*string++ != '\0');
    return ((UWORD) (string - length));
```
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [MatchPattern — dos.library](../autodocs/dos.library.md#matchpattern)
- [Output — dos.library](../autodocs/dos.library.md#output)
- [ParsePattern — dos.library](../autodocs/dos.library.md#parsepattern)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
