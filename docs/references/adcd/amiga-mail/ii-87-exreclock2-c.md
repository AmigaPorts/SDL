---
title: II-87/ExRecLock2.c
manual: amiga-mail
chapter: amiga-mail
section: ii-87-exreclock2-c
functions: [IoErr, Write]
libraries: [dos.library]
---

# II-87/ExRecLock2.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ExRecLock2.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 ExRecLock2.c
slink FROM LIB:c.o,ExRecLock2.o TO ExRecLock2 LIBRARY LIB:sc.lib,LIB:amiga.lib
quit ;*/

/*
(c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved.
The information contained herein is subject to change without notice,
and is provided "as is" without warranty of any kind, either expressed
or implied.  The entire risk as to the use of this information is
assumed by the user.
*/

/* This is a simple example of using record locking to create an exclusive record    */
/* lock on a file, and writing to that record.  The example ExRecLock1 is almost     */
/* exactly the same as this example, except ExRecLock1 uses the record lock directly */
/* before ExRecLock2's record.  If you try to run ExRecLock2 (or ExRecLock1) while   */
/* another instance of ExRecLock2 (or ExRecLock1) is running, the second record lock */
/* attempt will fail.                                                                */

#include <clib/dos_protos.h>
#include <clib/alib_protos.h>
#include <clib/alib_stdio_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }                    /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }
#endif

#define RECORDSIZE   12
#define RECORDOFFSET 12

extern struct Library *DOSBase;

UBYTE *vers = "\0$VER: ExRecLock2 37.2";
UBYTE *string = "ExRecLock2\n";                           /* This string will be the */
                                                          /* contents of the record. */
void main(void)
{
```c
    BPTR fh;

    if (DOSBase->lib_Version >= 37)   /* Record locking was introduced in Release 2, */
    {                                 /* but the standard startup code will open any */
                                      /* version of dos.library, so we have to ex-   */
                                      /* plicitly check the version number of DOS.   */

        if (fh = Open("t:testRLock", MODE_READWRITE))     /* Open the file, creating */
        {                                                 /*        it if necessary. */
            if (DOSTRUE == LockRecord(fh,           /* Lock the record as exclusive, */
                                      RECORDOFFSET, /* and do not wait if it is not  */
                                      RECORDSIZE,   /* available immediately.        */
                                      REC_EXCLUSIVE_IMMED, 0))
            {
                LONG error = RECORDOFFSET;

                                     /* If the record is beyond the end of the file, */
                if (Seek(fh, 0, OFFSET_END) < RECORDOFFSET)    /* lengthen the file. */
                    error = SetFileSize(fh, RECORDOFFSET, OFFSET_BEGINNING);

                if (error == RECORDOFFSET)    /* If there was no error with the file */
                {                             /*                file size, continue. */
                    if (Seek(fh, RECORDOFFSET, OFFSET_BEGINNING) < 0)
                        PrintFault(IoErr(), "Seek() error");

                    if (Write(fh, string, RECORDSIZE) < 0)
                        PrintFault(IoErr(), "Write() error");
                    else
                        PutStr("Write successful, ");
                }
                PutStr("Waiting 10 seconds...\n");
                TimeDelay(UNIT_VBLANK, 10, 0);       /* Amiga.lib function that puts */
                          /* a task to sleep for a given amount of time.  This waits */
                          /* 10 seconds before unlocking the record to give the user */
                          /* a chance to start a second copy of this example.        */
                UnLockRecord(fh, RECORDOFFSET, RECORDSIZE);
            }
            else PrintFault(IoErr(), "Record Lock Failed");
            Close(fh);
        }
        else PrintFault(IoErr(), "Open Failed");
    }
    else PutStr("Need dos.library V37 or greater.\n");
```
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Write — dos.library](../autodocs/dos.library.md#write)
