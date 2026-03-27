---
title: I-7/SimpleFR.c
manual: amiga-mail
chapter: amiga-mail
section: i-7-simplefr-c
functions: []
libraries: []
---

# I-7/SimpleFR.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* simpleFR.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 simpleFR.c
slink FROM LIB:c.o,simpleFR.o TO simpleFR LIBRARY LIB:sc.lib,LIB:amiga.lib
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

#include <clib/asl_protos.h>
#include <clib/exec_protos.h>
#include <clib/alib_stdio_protos.h>
#include <dos/dosasl.h>
#include <exec/libraries.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

UBYTE *vers = "\0$VER: simpleFR 1.1";

void main(void);

#define MYLEFTEDGE 0
#define MYTOPEDGE  0
#define MYWIDTH    320
#define MYHEIGHT   400

struct Library *AslBase;

struct TagItem frtags[] =
{
```c
    ASL_Hail,       (ULONG)"The RKM file requester",
    ASL_Height,     MYHEIGHT,
    ASL_Width,      MYWIDTH,
    ASL_LeftEdge,   MYLEFTEDGE,
    ASL_TopEdge,    MYTOPEDGE,
    ASL_OKText,     (ULONG)"O KAY",
    ASL_CancelText, (ULONG)"not OK",
    ASL_File,       (ULONG)"asl.library",
    ASL_Dir,        (ULONG)"libs:",
    TAG_DONE
```
};



void main()
{

```c
    struct FileRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 36L))
    {
        if (fr = (struct FileRequester *)
            AllocAslRequest(ASL_FileRequest, frtags))
        {
            /* Application body, blah, blah,... */

            /* Application need a requester */
            if (AslRequest(fr, 0L))
                printf("file choice = %s%s\n", fr->rf_Dir, fr->rf_File);
            else
                printf("User Cancelled\n");

            /* More application body, blah, blah... */
        }

        /* Don't need any more requesters, better
        ** give the requester structure back.
        */
        FreeAslRequest(fr);
    }
    CloseLibrary(AslBase);
```
}

