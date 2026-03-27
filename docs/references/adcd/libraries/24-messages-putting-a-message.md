---
title: 24 / Messages / Putting a Message
manual: libraries
chapter: libraries
section: 24-messages-putting-a-message
functions: [CreateMsgPort, PutMsg]
libraries: [exec.library]
---

# 24 / Messages / Putting a Message

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A message is delivered to a given destination port with the [PutMsg()](autodocs-2.0/exec-library-putmsg.md)
function.  The message is queued to the port, and that port's arrival
action is invoked.  If the action specifies a task signal or a software
interrupt, the originating task may temporarily lose the processor while
the destination processes the message.  If a reply to the message is
required, the [mn_ReplyPort](libraries/24-exec-messages-and-ports-messages.md) field must be set up prior to the call to
PutMsg().

Here is a code fragment for putting a message to a public port.  A
[complete example](libraries/lib-examples-port2-c.md) is printed at the end of the chapter.


#Include <exec/types.h>
#include <exec/memory.h>
#include <exec/ports.h>
#include <libraries/dos.h>

VOID main(VOID);
BOOL SafePutToPort(struct Message *, STRPTR);

struct XYMessage {
```c
    struct Message xy_Msg;
    UWORD          xy_X;
    UWORD          xy_Y;
```
};

VOID main(VOID)
{
```c
    struct MsgPort *xyport, *xyreplyport;
    struct XYMessage *xymsg, *msg;
    BOOL   foundport;

    /* Allocate memory for the message we're going to send. */
    if (xymsg = (struct XYMessage *) AllocMem(sizeof(struct XYMessage),
                                             MEMF_PUBLIC | MEMF_CLEAR))
    {

        /* The replyport we'll use to get response */
        if (xyreplyport = CreateMsgPort()) {
                                         /* or use CreatePort(0,0) */

            xymsg->xy_Msg.mn_Node.ln_Type = NT_MESSAGE;
                                         /* Compose the message    */
            xymsg->xy_Msg.mn_Length = sizeof(struct XYMessage);
            xymsg->xy_Msg.mn_ReplyPort = xyreplyport;
            xymsg->xy_X = 10;
            xymsg->xy_Y = 20;

            /* Now try to send that message to a public port named
             *  "xyport". If foundport eq 0, the port isn't out there.
             */
            if (foundport = SafePutToPort((struct Message *)xymsg,
                                           "xyport"))
            {

            . . .   /* Now let's wait till the someone responds... */

            }
            else printf("Couldn't find 'xyport'\n");

            DeleteMsgPort(xyreplyport);  /* Use DeletePort() if    */
                                         /* the port was created   */
        }                                /* with CreatePort().     */
        else printf("Couldn't create message port\n");
        FreeMem(xymsg, sizeof(struct XYMessage));
    }
    else printf("Couldn't get memory for xymessage\n");
```
}

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [PutMsg — exec.library](../autodocs/exec.library.md#putmsg)
