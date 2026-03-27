---
title: II-49/ListDir2.c
manual: amiga-mail
chapter: amiga-mail
section: ii-49-listdir2-c
functions: [IoErr, Output]
libraries: [dos.library]
---

# II-49/ListDir2.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ListDir2.c   AmigaMail seconds ExAll() example.
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 ListDir2.c
slink from ListDir2.o to ListDir2 lib lib:amiga.lib ;if you don't have pragmas
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
#include <utility/hooks.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/utility_protos.h>

/* undef PRAGMAS if you don't have them */
#define PRAGMAS
#undef PRAGMAS
#ifdef PRAGMAS
#include <pragmas/exec_pragmas.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/utility_pragmas.h>
#else
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;
struct Library *UtilityBase;

#endif

/* Buffersize to receive filenames in */
#define BUFFERSIZE 512


VOID            main(VOID);
UWORD           StrLen(UBYTE *);

/* SAS/C specific, use asm stub otherwise */
#define ASM __asm
#define REG(x) register __## x
BOOL ASM  ExAllHook(REG(a0) struct Hook * hook,

```c
                    REG(a1) struct ExAllData * data,
                    REG(a2) LONG * datatype);
```
VOID
main(VOID)
{
#ifdef PRAGMAS

```c
    struct DosLibrary *DOSBase;
    struct Library *UtilityBase;
```
#endif

```c
    struct RDArgs  *readargs;
    LONG            rargs[4];
    struct ExAllControl *excontrol;
    struct ExAllData *ead, *buffer;
    struct Hook     exallhook;
    UBYTE          *pattern, *parsebuffer;
    BPTR            sourcelock;
    BOOL            exmore;
    COUNT           i;
    LONG            parselength, type, error;
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

        rargs[1] = 0L;
        rargs[2] = 0L;
        if (readargs = ReadArgs("PATTERN/A,DIRS/S,FILES/S", rargs, NULL))
        {

            pattern = (UBYTE *) rargs[0];

            /*
             * If DIRS or files not specified or both, accept
             * both files and directories
             */
            if (rargs[1] == rargs[2])
                type = 0;
            else
            {
                /* Accept only directories */
                if (rargs[1])
                    type = 1;
                /* Accept only files */
                else
                    type = -1;
            }

            parselength = StrLen(pattern) * 3;
            if (parsebuffer = AllocMem(parselength, MEMF_CLEAR))
            {

                /* Make pattern uppercase for possible character classes */
                i = 0;
                while (pattern[i])
                    pattern[i] = ToUpper(pattern[i++]);

                if ((ParsePatternNoCase(pattern, parsebuffer, parselength)) != -1)
                {

                    if (buffer = AllocMem(BUFFERSIZE, MEMF_CLEAR))
                    {

                        sourcelock =
                                ((struct Process *) FindTask(NULL))->pr_CurrentDir;

                        if (excontrol = AllocDosObject(DOS_EXALLCONTROL, NULL))
                        {

                            exallhook.h_Entry = (ULONG (*)())ExAllHook;
                            exallhook.h_Data = (VOID *) type;

                            excontrol->eac_MatchString = parsebuffer;
                            excontrol->eac_MatchFunc = &exallhook;

                            do
                            {

                                exmore = ExAll(sourcelock,
                                               buffer,
                                               BUFFERSIZE,
                                               ED_TYPE,
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

                        FreeMem(buffer, BUFFERSIZE);
                    }
                    else
                        PrintFault(ERROR_NO_FREE_STORE, NULL);
                }
                else
                    PrintFault(ERROR_BAD_TEMPLATE, NULL);
                FreeMem(parsebuffer, parselength);
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

BOOL ASM
ExAllHook(REG(a0) struct Hook * hook,
```c
          REG(a1) struct ExAllData * data,
          REG(a2) LONG * datatype)
```
{
```c
    LONG            neededfiletype = (LONG) hook->h_Data;
    BOOL            success = TRUE;

    if (neededfiletype != 0)
    {
        if (data->ed_Type > 0 && neededfiletype < 0)
            success = FALSE;
        if (data->ed_Type < 0 && neededfiletype > 0)
            success = FALSE;
    }
    return (success);
```
}


UWORD
StrLen(UBYTE * string)
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
- [Output — dos.library](../autodocs/dos.library.md#output)
