---
title: III-29/dillo_test.c
manual: amiga-mail
chapter: amiga-mail
section: iii-29-dillo-test-c
functions: []
libraries: []
---

# III-29/dillo_test.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* dillo_test.c - Execute me to compile me with SAS/C 6.56
sc data=far nominc strmer streq nostkchk saveds ign=73 dillo_test.c
slink FROM LIB:c.o,dillo_test.o TO dillo_test LIB LIB:SC.lib,LIB:Amiga.lib
quit
*/

/*
**  dillo_test.c
**
**  This is the sample program to test the functions inside
**  armadillo.library.  It creates a small array of Armadillos
**  and after assigning various values, prints out their status.
**
*/

#include    <exec/types.h>
#include    <exec/libraries.h>

#include    <clib/exec_protos.h>
#include    <pragmas/exec_pragmas.h>

#include    <stdio.h>

#include    "dillo_protos.h"
#include    "armadillo_pragmas.h"

extern struct ExecBase *SysBase;	/* olsen 30-Jan-96 */

/* Global data for the test program */

struct Library *DilloBase;      /* armadillo.library library base */

APTR dillo[5];                  /* Array of generic pointers to     */

                                /* armadillos, since programs don't */
                                /* need to know what the insides of */
                                /* an armadillo look like.          */
STRPTR names[5] = { "Alex", "Bob", "Chris", "Daniel", "Eustace" };
ULONG namlen[5] = { 5, 4, 6, 7, 8 };
ULONG weight[5] = { 18, 20, 19, 17, 354 };

void
main(void)
{
```c
    BOOL okay = FALSE;
    ULONG i = 0L;

    if (DilloBase = OpenLibrary("armadillo.library",0))
    {

        for (i=0;i<5;i++)
        {
            if (dillo[i] = CreateArmadillo())
            {
                if (okay = NameArmadillo( dillo[i], names[i], namlen[i] ))
                {
                    printf("Armadillo %ld named %s.\n",i,names[i]);
                }
                else
                {
                    printf("Armadillo %ld naming failure, it's anonymous.\n",i);
                }

                if (okay = FillArmadillo( dillo[i], weight[i] ))
                {
                    printf("Armadillo %ld weighs %ld.\n",i,weight[i]);
                }
                else
                {
                    printf("Armadillo %ld fill failure, it's dieting.\n",i);
                }

                if (i>2)
                {
                    if (okay = FlattenArmadillo( dillo[i], TRUE ))
                    {
                        printf("Armadillo %ld had a slight mishap.\n",i);
                    }
                }
            }
            else
            {
                printf("Couldn't create Armadillo %ld\n",i);
            }
        }

        /* Okay, all the armadillos are created (hopefully) and */
        /* so as proof of concept and to test the data access   */
        /* functions, now the program shows the status of each  */
        /* of the armadillos.                                   */

        printf("\nArmadillo Status Report\n");
        printf("-----------------------\n");

        for(i=0;i<5;i++)
        {
            UBYTE namebuf[33];

            printf("Armadillo #%ld\n",i);
            if (DilloName(dillo[i],(STRPTR)&namebuf,32))
            {
                printf("  Name   = \"%s\"\n",namebuf);
            }
            else
            {
                printf("  Name is invalid.\n");
            }
            printf("  Weight = %ld pounds\n\n",DilloWeight(dillo[i]));
            printf("  Dillo is %s\n",
                   (DilloFlat(dillo[i])?"flat":"lucky"));
            printf("-----\n");
        }

        printf("Total Dillos created: %ld\n\n",DilloBirths());

        /* Now that the armadillos have been tested, we can */
        /* delete them with gleeful abandon.                */

        for(i=0;i<5;i++)
        {
            DeleteArmadillo( dillo[i] );
        }

        /* We're done, so close the library... */
        CloseLibrary(DilloBase);
    }
    else
    {
        printf("Couldn't open armadillo.library!\n");
    }
```
}

