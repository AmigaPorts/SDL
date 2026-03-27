---
title: lib_examples/port2.c
manual: libraries
chapter: libraries
section: lib-examples-port2-c
functions: [Forbid, Permit]
libraries: [exec.library]
---

# lib_examples/port2.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* port2.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfistq -v -y -j73 port2.c
Blink FROM LIB:c.o,port2.o TO port2 LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit

** port2.c - port and message example, run at the same time as port1.c
*/

#include <exec/types.h>
#include <exec/ports.h>
#include <exec/memory.h>
#include <dos/dos.h>
#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL-C handling */
int chkabort(void) {return(0);}
#endif

BOOL SafePutToPort(struct Message *, STRPTR);

struct XYMessage {
```c
    struct Message xy_Msg;
    WORD           xy_X;
    WORD           xy_Y;
```
};

void main(int argc, char **argv)
{
```c
    struct MsgPort *xyreplyport;
    struct XYMessage *xymsg, *reply;
                                                           /* Using CreatePort() with no name       */
    if (xyreplyport = CreatePort(0,0))                     /* because this port need not be public. */
    {
        if (xymsg = (struct XYMessage *) AllocMem(sizeof(struct XYMessage), MEMF_PUBLIC | MEMF_CLEAR))
        {
            xymsg->xy_Msg.mn_Node.ln_Type = NT_MESSAGE;                /* make up a message,        */
            xymsg->xy_Msg.mn_Length = sizeof(struct XYMessage);        /* including the reply port. */
            xymsg->xy_Msg.mn_ReplyPort = xyreplyport;
            xymsg->xy_X = 10;                                   /* our special message information. */
            xymsg->xy_Y = 20;

            printf("Sending to port1: x = %d y = %d\n", xymsg->xy_X, xymsg->xy_Y);
                                                                   /* port2 will simply try to put  */

            if (SafePutToPort((struct Message *)xymsg, "xyport"))  /* one message to port1 wait for */
            {                                                      /*  the reply, and then exit     */
                WaitPort(xyreplyport);
                if (reply = (struct XYMessage *)GetMsg(xyreplyport))
                    printf("Reply contains: x = %d y = %d\n",         /* We don't ReplyMsg since   */
                            xymsg->xy_X, xymsg->xy_Y);                /* WE initiated the message. */

                      /* Since we only use this private port for receiving replies, and we sent     */
                      /* only one and got one reply there is no need to cleanup. For a public port, */
                      /* or if you pass a pointer to the port to another process, it is a very good */
                      /* habit to always handle all messages at the port before you delete it.      */
            }
            else printf("Can't find 'xyport'; start port1 in a separate shell\n");
            FreeMem(xymsg, sizeof(struct XYMessage));
        }
        else printf("Couldn't get memory\n");
        DeletePort(xyreplyport);
    }
    else printf("Couldn't create xyreplyport\n");
```
}


BOOL SafePutToPort(struct Message *message, STRPTR portname)
{
```c
    struct MsgPort *port;

    Forbid();
    port = FindPort(portname);
    if (port) PutMsg(port, message);
    Permit();
    return(port ? TRUE : FALSE); /* FALSE if the port was not found */

         /* Once we've done a Permit(), the port might go away and leave us with an invalid port    */
```
}        /* address. So we return just a BOOL to indicate whether the message has been sent or not. */

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
