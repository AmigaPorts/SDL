---
title: IX-1/4play.c
manual: amiga-mail
chapter: amiga-mail
section: ix-1-4play-c
functions: []
libraries: []
---

# IX-1/4play.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * 4play.c
 */

#include    <exec/types.h>
#include    <libraries/dos.h>

#include    <stdlib.h>
#include    <stdio.h>

#include    <clib/exec_protos.h>

UBYTE portdata;
UBYTE *portptr = &portdata;

UBYTE firedata;
UBYTE *fireptr = &firedata;

extern int getport(void);
extern void read34(void);
extern void freeport(void);


/*
 * Lattice control-c stop...
 */
int CXBRK(void) { return(0); }      /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }   /* really */


void Quit(char whytext[], LONG return_code)
{
```c
    if(return_code==0) freeport();  /* Assembly routine to
                                       de-allocate parallel port */

    printf("%s\n",whytext);

    exit(return_code);              /* returning non-zero
                                       terminates the program */
```
}


void main(void)
{
```c
    BOOL done=FALSE;
    UBYTE error;

    /* getport() is an assembly routine that allocates the parallel port
     * and makes all the lines we're interested in "read" lines.
     */
    if(error=getport()) Quit("Parallel port in use",25);
    /* WARNING:
     * This example continuously reads the ports and checks for CTRL_C,
     * thereby eating a lot of CPU time.  Actual applications that expect
     * to be even more system friendly might want to set up some interrupts
     * on the fire button lines, such that the game can read the ports less
     * often, but never miss a "fire" press.
     */

    while(!done)
    {
        read34();       /* read34() is the assembly routine that copies the
                         * relavent data from the port into our variables.
                         */

        /* We'll just print the raw bytes from the read, and leave it as an
         * exercise for the reader to mask out the relevant bits.
         * (Check the pinouts to find which bits the switches appear at.)
         */
        printf("portdata = %u, firedata = %u\n",portdata,firedata);

        /* Check CTRL_C */
        if(SetSignal(0L,0L) & SIGBREAKF_CTRL_C) /* Hit since last check? */
        {
            SetSignal(0L,SIGBREAKF_CTRL_C); /* Clear old status */
            done=TRUE;
        }
    }
    Quit("Ctrl-C was pressed.",0);
```
}

