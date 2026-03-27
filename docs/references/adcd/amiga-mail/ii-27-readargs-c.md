---
title: II-27/ReadArgs.c
manual: amiga-mail
chapter: amiga-mail
section: ii-27-readargs-c
functions: [Printf, ReadArgs, VPrintf]
libraries: [dos.library]
---

# II-27/ReadArgs.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* ReadArgs.c - Execute me to compile me with SAS/C 6.56
sc DATA=NEAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 ReadArgs.c
slink FROM LIB:c.o,ReadArgs.o TO ReadArgs LIBRARY LIB:sc.lib,LIB:amiga.lib
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


#include <dos/dos.h>
#include <dos/rdargs.h>
#include <clib/dos_protos.h>
#include <clib/alib_stdio_protos.h>


#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }
#endif

UBYTE *vers = "\0$VER: ReadArgs 1.0";

#define TEMPLATE "S=SourceFiles/A/M,D=DebugLevel/K/N,L=link/S"
#define OPT_SOURCE  0
#define OPT_DEBUG   1
#define OPT_LINK    2
#define OPT_COUNT   3

/* The array of LONGs where ReadArgs() will store the data from
** the command line arguments.  C guarantees that all the array
** entries will be set to zero.
*/
LONG result[OPT_COUNT];

/* My custom RDArgs */
struct RDArgs *myrda;

ULONG StrLen(UBYTE *);

void main(void)
{
```c
    UWORD x;
    UBYTE **sourcefiles;

    /* Need to ask DOS for a RDArgs structure */
    if (myrda = (struct RDArgs *)AllocDosObject(DOS_RDARGS, NULL))
    {
        /* set up my parameters for ReadArgs() */

        /* use the following command line */
        myrda->RDA_Source.CS_Buffer = "file1 file2 file3 D=1 Link file4 file5\n";
        myrda->RDA_Source.CS_Length = (LONG)StrLen(myrda->RDA_Source.CS_Buffer);

        /* parse my command line */
        if (ReadArgs(TEMPLATE, result, myrda))
        {
            /*start printing out the results */

            /* We don't need to check if there is a value in
            ** result[OPT_SOURCE] because the ReadArgs() template
            ** requires (using the /A modifier) that there be
            ** file names, so ReadArgs() will either fill in a
            ** value or ReadArgs() will fail.
            */
            sourcefiles = (UBYTE **)result[OPT_SOURCE];
            /* VPrintf() is a lot like Printf() except it's in
            ** ROM, and the arguments are referenced from an
            ** array rather than being extracted from the stack.
            */
            VPrintf("Files specified:\n", NULL);
            for (x=0; sourcefiles[x]; x++)
                VPrintf("\t%s\n", (LONG *)&sourcefiles[x]);

            /* Is there something in the "DebugLevel" option?
            ** If there is, print it.
            */
            if (result[OPT_DEBUG])
                VPrintf("Debugging Level = %ld\n", (LONG *)result[OPT_DEBUG]);

            /* If the link toggle was present, say something about it. */
            if (result[OPT_LINK])
                VPrintf("linking...\n", NULL);
            FreeArgs(myrda);
        }
        FreeDosObject(DOS_RDARGS, myrda);
    }
```
}


ULONG StrLen(UBYTE *string)
{
```c
    ULONG x = 0L;

    while (string[x++]);
    return(x);
```
}

---

## See Also

- [Printf — dos.library](../autodocs/dos.library.md#printf)
- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
- [VPrintf — dos.library](../autodocs/dos.library.md#vprintf)
