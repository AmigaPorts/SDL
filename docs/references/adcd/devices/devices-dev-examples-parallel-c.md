---
title: Devices/Dev_examples/Parallel.c
manual: devices
chapter: devices
section: devices-dev-examples-parallel-c
functions: [Wait]
libraries: [exec.library]
---

# Devices/Dev_examples/Parallel.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Parallel.c
 *
 * Parallel device example
 *
 * Compile with SAS C 5.10: LC -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/io.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <devices/parallel.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }     /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

void main(void)
{
struct MsgPort  *ParallelMP;          /* Define storage for one pointer */
struct IOExtPar *ParallelIO;         /* Define storage for one pointer */
ULONG            WaitMask;          /* Collect all signals here       */
ULONG            Temp;             /* Hey, we all need pockets :-)   */

if (ParallelMP=CreatePort(0,0) )
```c
    {
    if (ParallelIO=(struct IOExtPar *)
        CreateExtIO(ParallelMP,sizeof(struct IOExtPar)) )
        {
        if (OpenDevice(PARALLELNAME,0L,(struct IORequest *)ParallelIO,0) )
            printf("%s did not open\n",PARALLELNAME);
        else
            {
            /* Precalculate a wait mask for the CTRL-C,CTRL-F and message
             * port signals.  When one or more signals are received, Wait()
             *  will return.  Press CTRL-C to exit the example.  Press
             * CTRL-F to wake up the example without doing anything.
             * NOTE: A signal may show up without an associated message!
             */
            WaitMask = SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_F |
                       1L << ParallelMP->mp_SigBit;

            ParallelIO->IOPar.io_Command  = CMD_WRITE;
            ParallelIO->IOPar.io_Length   = -1;
            ParallelIO->IOPar.io_Data     = (APTR)"Hey, Jude!\\r\n";
            SendIO(ParallelIO);             /* execute write */

            printf("Sleeping until CTRL-C, CTRL-F, or write finish\n");
            while(1)
                {
                Temp = Wait(WaitMask);
                printf("Just woke up (YAWN!)\n");

                if (SIGBREAKF_CTRL_C & Temp)
                    break;

                if (CheckIO(ParallelIO) ) /* If request is complete... */
                    {
                    WaitIO(ParallelIO);   /* clean up and remove reply */
                    printf("%ld bytes sent\n",ParallelIO->IOPar.io_Actual);
                    break;
                    }
                }

            AbortIO(ParallelIO);/* Ask dev. to abort request if pending */
            WaitIO(ParallelIO); /* Wait for abort, then clean up */

            CloseDevice((struct IORequest *)ParallelIO);
            }
        DeleteExtIO(ParallelIO);
        }
    DeletePort(ParallelMP);
    }
```
}

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
