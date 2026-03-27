---
title: Devices/Dev_examples/Multiple_Timers.c
manual: devices
chapter: devices
section: devices-dev-examples-multiple-timers-c
functions: [WaitPort]
libraries: [exec.library]
---

# Devices/Dev_examples/Multiple_Timers.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*  Multiple_Timers.c
 *
 *  This program is designed to do multiple (3) time requests using one
 *  OpenDevice.  It creates a message port - TimerMP, creates an
 *  extended I/O structure of type timerequest named TimerIO[0] and
 *  then uses that to open the device.  The other two time request
 *  structures - TimerIO[1] and TimerIO[2] - are created using AllocMem
 *  and then copying TimerIO[0] into them.  The tv_secs field of each
 *  structure is set and then three SendIOs are done with the requests.
 *  The program then goes into a while loop until all messages are received.
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <devices/timer.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

VOID main(VOID);

void main(void)
{
struct timerequest *TimerIO[3];
struct MsgPort *TimerMP;
struct Message *TimerMSG;

ULONG error,x,seconds[3]={4,1,2}, microseconds[3]={0,0,0};

int allin = 3;
char *position[]={"last","second","first"};

if (TimerMP = CreatePort(0,0))

```c
    {
    if (TimerIO[0] = (struct timerequest *)
                      CreateExtIO(TimerMP,sizeof(struct timerequest)) )
        {
            /* Open the device once */
        if (!(error=OpenDevice( TIMERNAME, UNIT_VBLANK,(struct IORequest *) TimerIO[0], 0L)))
            {
            /* Set command to TR_ADDREQUEST */
            TimerIO[0]->tr_node.io_Command = TR_ADDREQUEST;

            if (TimerIO[1]=(struct timerequest *)
                    AllocMem(sizeof(struct timerequest),MEMF_PUBLIC | MEMF_CLEAR))
                {
                if (TimerIO[2]=(struct timerequest *)
                       AllocMem(sizeof(struct timerequest),MEMF_PUBLIC | MEMF_CLEAR))
                    {
                    /* Copy fields from the request used to open the timer device */
                    *TimerIO[1] = *TimerIO[0];
                    *TimerIO[2] = *TimerIO[0];

                    /* Initialize other fields */
                    for (x=0;x<3;x++)
                        {
                        TimerIO[x]->tr_time.tv_secs   = seconds[x];
                        TimerIO[x]->tr_time.tv_micro  = microseconds[x];
                        printf("\nInitializing TimerIO[%d]",x);
                        }

                    printf("\n\nSending multiple requests\n\n");

                    /* Send multiple requests asynchronously */
                    /* Do not got to sleep yet...            */
                    SendIO((struct IORequest *)TimerIO[0]);
                    SendIO((struct IORequest *)TimerIO[1]);
                    SendIO((struct IORequest *)TimerIO[2]);

                    /* There might be other processing done here */

                    /* Now go to sleep with WaitPort() waiting for the requests */
                    while (allin)
                          {
                          WaitPort(TimerMP);
                          /* Get the reply message */
                          TimerMSG=GetMsg(TimerMP);
                          for (x=0;x<3;x++)
                              if (TimerMSG==(struct Message *)TimerIO[x])
                                  printf("Request %ld finished %s\n",x,position[--allin]);
                          }

                    FreeMem(TimerIO[2],sizeof(struct timerequest));
                    }

                else
                    printf("Error: could not allocate TimerIO[2] memory\n");

                FreeMem(TimerIO[1],sizeof(struct timerequest));
                }

            else
                printf("Error could not allocate TimerIO[1] memory\n");

            CloseDevice((struct IORequest *) TimerIO[0]);
            }

        else
            printf("\nError: Could not OpenDevice\n");

        DeleteExtIO((struct IORequest *) TimerIO[0]);
        }

    else
        printf("Error: could not create IORequest\n");

    DeletePort(TimerMP);
    }
```
else
```c
    printf("\nError: Could not CreatePort\n");
```
}

---

## See Also

- [WaitPort — exec.library](../autodocs/exec.library.md#waitport)
