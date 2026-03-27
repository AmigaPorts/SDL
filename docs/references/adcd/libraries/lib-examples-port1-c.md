---
title: lib_examples/port1.c
manual: libraries
chapter: libraries
section: lib-examples-port1-c
functions: []
libraries: []
---

# lib_examples/port1.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* port1.c - Execute me to compile with SAS C 5.10
LC -b1 -cfistq -v -y -j73 port1.c
Blink FROM LIB:c.o,port1.o TO port1 LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

* port1.c - port and message example, run at the same time as port2.c
*/

#include <exec/types.h>
#include <exec/ports.h>
#include <dos/dos.h>
#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL-C handling */
int chkabort(void) {return(0);}
#endif

struct XYMessage {
```c
    struct Message xym_Msg;
    WORD           xy_X;
    WORD           xy_Y;
```
};

void main(int argc, char **argv)
{
```c
    struct MsgPort *xyport;
    struct XYMessage *xymsg;
    ULONG portsig, usersig, signal;
    BOOL ABORT = FALSE;

    if (xyport = CreatePort("xyport", 0))
    {
        portsig = 1 << xyport->mp_SigBit;       /* Give user a `break' signal. */
        usersig = SIGBREAKF_CTRL_C;

        printf("Start port2 in another shell.  CTRL-C here when done.\n");
        do
        {                                                 /* port1 will wait forever and reply   */
            signal = Wait(portsig | usersig);             /* to messages, until the user breaks. */

                                   /* Since we only have one port that might get messages we     */
            if (signal & portsig)  /* have to reply to, it is not really necessary to test for   */
            {                      /* the portsignal. If there is not message at the port, xymsg */

                while(xymsg = (struct XYMessage *)GetMsg(xyport))        /* simply will be NULL. */
                {
                    printf("port1 received: x = %d y = %d\n", xymsg->xy_X, xymsg->xy_Y);

                    xymsg->xy_X += 50;       /* Since we have not replied yet to the owner of    */
                    xymsg->xy_Y += 50;       /* xymsg, we can change the data contents of xymsg. */

                    printf("port1 replying with: x = %d y = %d\n", xymsg->xy_X, xymsg->xy_Y);
                    ReplyMsg((struct Message *)xymsg);
                }
            }

            if (signal & usersig)                                    /* The user wants to abort. */
            {
                while(xymsg = (struct XYMessage *)GetMsg(xyport))    /* Make sure port is empty. */
                    ReplyMsg((struct Message *)xymsg);
                ABORT = TRUE;
            }
        }
        while (ABORT == FALSE);
            DeletePort(xyport);
        }
    else printf("Couldn't create 'xyport'\n");
```
}

