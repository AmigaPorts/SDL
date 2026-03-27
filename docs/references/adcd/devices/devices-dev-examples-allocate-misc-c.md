---
title: Devices/Dev_examples/Allocate_Misc.c
manual: devices
chapter: devices
section: devices-dev-examples-allocate-misc-c
functions: []
libraries: []
---

# Devices/Dev_examples/Allocate_Misc.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Allocate_Misc.c
 *
 * Example of allocating a miscellaneous resource
 * We will allocate the serial resource and wait till
 * CTRL-C is pressed.  While we are waiting, the
 * query_serial program should be run.  It will try
 * to open the serial device and if unsuccessful, will
 * return the name of the owner.  It will be us!
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <resources/misc.h>

#include <clib/exec_protos.h>
#include <clib/misc_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct Library *MiscBase = NULL;

void main(int argc, char **argv)
{
UBYTE *owner = NULL;       /* owner of misc resource */

if (!(MiscBase= (struct Library *)OpenResource(MISCNAME)))
```c
    printf("Cannot open %s\n",MISCNAME);
```
else
   {
```c
    /* Allocate both pieces of the serial hardware */
    if ((owner = AllocMiscResource(MR_SERIALPORT,"Serial Port Hog")) == NULL)
        {
        if ((owner = AllocMiscResource(MR_SERIALBITS,"Serial Port Hog")) == NULL)
            {
            /* Wait for CTRL-C to be pressed */
            printf("\nWaiting for CTRL-C...\n");
            Wait(SIGBREAKF_CTRL_C);

            /* We're back */

            /* Deallocate the serial port register */
            FreeMiscResource(MR_SERIALBITS);
            }
        else
            printf("\nUnable to allocate MR_SERIALBITS because %s owns it\n",owner);

        /* Deallocate the serial port */
        FreeMiscResource(MR_SERIALPORT);
       }
    else
       printf("\nUnable to allocate MR_SERIALPORT because %s owns it\n",owner);
```
   }
}

