---
title: II-43/Part.c
manual: amiga-mail
chapter: amiga-mail
section: ii-43-part-c
functions: [IoErr, Output]
libraries: [dos.library]
---

# II-43/Part.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Part.c - AmigaMail File/Path separator example.  Compiled with SAS/C 6.56.
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 Part.c
slink from Part.o to Part lib lib:amiga.lib ; if you don't have pragmas
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
struct Library *DOSBase;

#endif

VOID            main(VOID);
LONG            GetPath(UBYTE * path, UBYTE * buffer, LONG buffersize);
UBYTE          *ItsWild(UBYTE * string);

VOID main(VOID)
{
#ifdef PRAGMAS

```c
    struct Library *DOSBase;
```
#endif

```c
    struct RDArgs  *readargs;
    LONG            rargs[2];
    LONG            vargs[8];
    UBYTE          *path, *filename;
    UBYTE          *buffer;
    UBYTE          *filepart, *pathpart;
    struct Process *process;
    BPTR            lock;
    APTR            wptr;
    BOOL            error;
```
#ifndef PRAGMAS
```c
    /* set up SysBase */
    SysBase = (*((struct Library **) 4));
```
#endif

```c
    /* Fail silently if < 37 */
    if (DOSBase = OpenLibrary("dos.library", 37))
    {

        /*
         * Use a generous 256 byte buffer. Should suffice for everything but
         * extreme cases.
         */
        if (buffer = AllocMem(256, MEMF_CLEAR))
        {

            if (readargs = ReadArgs("PATH/A,FILENAME/A", rargs, NULL))
            {
                path = (UBYTE *) (rargs[0]);
                filename = (UBYTE *) (rargs[1]);

                error = GetPath(path, buffer, 255);
                if (error)
                    PrintFault(error, NULL);

                filepart = FilePart(path);
                pathpart = PathPart(path);

                vargs[0] = (LONG) path;
                vargs[1] = (LONG) filepart;
                vargs[2] = (LONG) pathpart;
                vargs[3] = (LONG) buffer;
                VFPrintf(Output(),
                         "Filename: %s\nFilepart: %s\nPathpart: %s\nPath: %s\n",
                         vargs);

                /* No requesters */
                process = (struct Process *) FindTask(NULL);
                wptr = process->pr_WindowPtr;
                process->pr_WindowPtr = (APTR) - 1L;

                /*
                 * Make sure this name is for real. This will weed out names
                 * like "dh0:/" and non-existent directories. (and also
                 * complain about non-mounted volumes.) It is tempting to look
                 * for trailing slashes and remove them but you shouldn't. You
                 * might misinterpret the users intention. Better to generate a
                 * warning and prompt for new input.
                 */
                if (lock = Lock(buffer, SHARED_LOCK))
                    UnLock(lock);
                else
                    PrintFault(IoErr(), buffer);

                /* Reset windowpointer */
                process->pr_WindowPtr = wptr;

                /*
                 * Normally we should respect the test for an invalid path. To
                 * show the results however, we blunder along...
                 *
                 * Add the filename to the path.
                 */
                if (AddPart(buffer, filename, 255))
                    vargs[0] = (LONG) buffer;
                else
                    vargs[0] = (LONG) "OVERFLOW";

                VFPrintf(Output(), "\nNew path: %s\n", vargs);

                FreeArgs(readargs);
            }
            else
                PrintFault(IoErr(), NULL);
            FreeMem(buffer, 256);
        }
        CloseLibrary(DOSBase);
    }
```
}

/*
 * Standalone function to isolate a path and copy it into a supplied buffer.
 * Does not test if the path is valid. Returns an error in case of buffer
 * overflow.
 */
LONG
GetPath(UBYTE * path, UBYTE * buffer, LONG buffersize)
{
```c
    UBYTE          *pathpart, *filepart;
    UBYTE          *tmp1, *tmp2;
    BPTR            lock;
    struct FileInfoBlock *fib;
    LONG            error = 0;

    /* Open own copy of dos.library if pragmas are used so it's standalone */
```
#ifdef PRAGMAS
```c
    struct Library *DOSBase;

    if (!(DOSBase = OpenLibrary("dos.library", 36)))
        return (1);
```
#endif


```c
    /*
     * If there seems to be no path, the pathpart will point to the filepart
     * too, so we need to check for that.
     */
    filepart = FilePart(path);
    pathpart = PathPart(path);

    /*
     * This also handles cases where there is only a volume/device name, only a
     * directory name or a combo of those.
     */
    if (pathpart == path)
    {

        /*
         * There seems to be only one component. Copy it if it is not wild.
         * Caller will have to check whether if it exists and if it is a file
         * or directory.
         */
        if (!(ItsWild(pathpart)))
            pathpart = NULL;
    }

    if (pathpart != path)
    {

        /*
         * If pathpart equals filepart (pointer wise) then there is only one
         * component (possible preceeded by a volume name).
         */
        if (pathpart == filepart)
        {
            if (!(ItsWild(pathpart)))
                pathpart = NULL;
        }
        else
        {

            /*
             * Try to lock it to determine if the last component is a
             * directory.
             */
            if (lock = Lock(path, SHARED_LOCK))
            {
                if (fib = AllocMem(sizeof(struct FileInfoBlock), MEMF_CLEAR))
                {
                    if ((Examine(lock, fib)) == DOSTRUE)
                    {
                        /* Hey it's a directory after all */
                        if (fib->fib_DirEntryType > 0)
                            pathpart = NULL;
                    }
                    FreeMem(fib, sizeof(struct FileInfoBlock));
                }
                UnLock(lock);
            }           /* else treat it as a filename */
        }

        /* Copy the pathpart in the buffer */
        tmp1 = buffer;
        tmp2 = path;
        while ((*tmp1++ = *tmp2++) && (tmp2 != pathpart))
        {
            if (tmp1 == (buffer + buffersize))
            {
                error = ERROR_NO_FREE_STORE;
                break;
            }
        }
        *tmp1 = '\0';  /* NULL terminate. */
    }
```
#ifdef PRAGMAS
```c
    CloseLibrary(DOSBase);
```
#endif
```c
    return (error);
```
}

/* Simple test whether a filename contains wildcards or not */
UBYTE          *
ItsWild(UBYTE * string)
{
```c
    static UBYTE   *special = "#?*%([|";
    UBYTE          *tmp = string;
    COUNT           i;

    do
    {
        for (i = 0; special[i] != '\0'; i++)
        {
            if (*tmp == special[i])
                return (tmp);
        }
        tmp++;
    } while (*tmp);

    return (NULL);
```
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
