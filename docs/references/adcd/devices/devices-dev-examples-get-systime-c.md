---
title: Devices/Dev_examples/Get_Systime.c
manual: devices
chapter: devices
section: devices-dev-examples-get-systime-c
functions: []
libraries: []
---

# Devices/Dev_examples/Get_Systime.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* Get_Systime.c
 *
 * Get system time example
 *
 * Compile with SAS C 5.10: LC -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/io.h>
#include <exec/memory.h>
#include <devices/timer.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/dos_protos.h>
#include <clib/intuition_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

struct timerequest *TimerIO;
struct MsgPort *TimerMP;
struct Message *TimerMSG;

VOID main(VOID);

void main()
{
LONG error;
ULONG days,hrs,secs,mins,mics;

if (TimerMP = CreatePort(0,0))
```c
    {
    if (TimerIO = (struct timerequest *)
                   CreateExtIO(TimerMP,sizeof(struct timerequest)) )
        {
            /* Open with UNIT_VBLANK, but any unit can be used */
        if (!(error=OpenDevice(TIMERNAME,UNIT_VBLANK,(struct IORequest *)TimerIO,0L)))
            {
            /* Issue the command and wait for it to finish, then get the reply */
            TimerIO->tr_node.io_Command = TR_GETSYSTIME;
            DoIO((struct IORequest *) TimerIO);

            /* Get the results and close the timer device */
            mics=TimerIO->tr_time.tv_micro;
            secs=TimerIO->tr_time.tv_secs;

            /* Compute days, hours, etc. */
            mins=secs/60;
            hrs=mins/60;
            days=hrs/24;
            secs=secs%60;
            mins=mins%60;
            hrs=hrs%24;

            /* Display the time */
            printf("\nSystem Time (measured from Jan.1,1978)\n");
            printf("  Days   Hours  Minutes Seconds Microseconds\n");
            printf("%6ld %6ld %6ld %6ld %10ld\n",days,hrs,mins,secs,mics);

            /* Close the timer device */
            CloseDevice((struct IORequest *) TimerIO);
            }
        else
            printf("\nError: Could not open timer device\n");

        /* Delete the IORequest structure */
        DeleteExtIO(TimerIO);
        }
    else
        printf("\nError: Could not create I/O structure\n");

    /* Delete the port */
    DeletePort(TimerMP);
    }
```
else
```c
    printf("\nError: Could not create port\n");
```
}

