---
title: Lib_examples/CloseWindowSafely.c
manual: libraries
chapter: libraries
section: lib-examples-closewindowsafely-c
functions: [Forbid, Permit]
libraries: [exec.library]
---

# Lib_examples/CloseWindowSafely.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* This example shows the CloseWindowSafely() function.  Use this
** function to close any windows that share an IDCMP port with another
** window.
**
** CloseWindowSafely.c
**
** these functions close an Intuition window that shares a port with other
** Intuition windows.
**
** We are careful to set the UserPort to NULL before closing, and to free
** any messages that it might have been sent.
*/
#include "exec/types.h"
#include "exec/nodes.h"
#include "exec/lists.h"
#include "exec/ports.h"
#include "intuition/intuition.h"

/*
** function to remove and reply all IntuiMessages on a port that have been
** sent to a particular window (note that we don't rely on the ln_Succ
** pointer of a message after we have replied it)
*/
VOID StripIntuiMessages(struct MsgPort *mp, struct Window *win)
{
struct IntuiMessage *msg;
struct Node *succ;

msg = (struct IntuiMessage *)mp->mp_MsgList.lh_Head;

while (succ = msg->ExecMessage.mn_Node.ln_Succ)
	{
	if (msg->IDCMPWindow == win)
		{
		/* Intuition is about to free this message.
		** Make sure that we have politely sent it back.
		*/
		Remove(msg);

		ReplyMsg(msg);
		}
	msg = (struct IntuiMessage *)succ;
	}
}

/*
** Entry point to CloseWindowSafely()
** Strip all IntuiMessages from an IDCMP which are waiting for a specific
** window.  When the messages are gone, set the UserPort of the window to
** NULL and call ModifyIDCMP(win,0).  This will free the Intuition arts of
** the IDMCMP and trun off message to this port without changing the
** original UserPort (which may be in use by other windows).
*/
VOID CloseWindowSafely(struct Window *win)
{
/* we forbid here to keep out of race conditions with Intuition */
Forbid();

/* send back any messages for this window  that have not yet been
** processed
*/
StripIntuiMessages(win->UserPort, win);

/* clear UserPort so Intuition will not free it */
win->UserPort = NULL;

/* tell Intuition to stop sending more messages */
ModifyIDCMP(win, 0L);

/* turn multitasking back on */
Permit();

/* Now it's safe to really close the window */
CloseWindow(win);
}

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
