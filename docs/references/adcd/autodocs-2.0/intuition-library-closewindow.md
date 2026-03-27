---
title: intuition.library/CloseWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-closewindow
functions: [ClearMenuStrip, CloseScreen, Forbid, OpenScreen, OpenWindow, Permit, SetMenuStrip]
libraries: [exec.library, intuition.library]
---

# intuition.library/CloseWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CloseWindow -- Close an Intuition window.
SYNOPSIS

```c
    CloseWindow( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                 A0

    VOID CloseWindow( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Closes an Intuition window.  Unlinks it from the system, deallocates
    its memory, and makes it disappear.

    When this function is called, all IDCMP messages which have been sent
    to your window are deallocated.  If the window had shared a message
    Port with other windows, you must be sure that there are no unreplied
    messages for this window in the message queue.  Otherwise, your program
    will try to make use of a linked list (the queue) which contains free
    memory (the old messages).  This will give you big problems.
    See the code fragment CloseWindowSafely(), below.

    NOTE:  If you have added a [Menu](autodocs-2.0/includes-intuition-intuition-h.md) strip to this [Window](autodocs-2.0/includes-intuition-intuition-h.md) (via
    a call to [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md)) you must be sure to remove that [Menu](autodocs-2.0/includes-intuition-intuition-h.md) strip
    (via a call to [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md)) before closing your [Window](autodocs-2.0/includes-intuition-intuition-h.md).

    NOTE: This function may block until it is safe to de-link and free
    your window.  Your program may thus be suspended while the user
    plays with gadgets, menus, or window sizes and position.

    New for V36: If your window is a "Visitor Window" (see OpenWindow)
    CloseWindow will decrement the "visitor count" in the public screen
    on which the window was open.  When the last visitor window is
    closed, a signal will be sent to the public screen task, if this
    was pre-arranged (see OpenScreen).
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = a pointer to a [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md), [OpenScreen()](autodocs-2.0/intuition-library-openscreen.md), [CloseScreen()](autodocs-2.0/intuition-library-closescreen.md)
```
EXAMPLE
/*  CloseWindowSafely */


```c
    /* these functions close an Intuition window
     * that shares a port with other Intuition
     * windows or IPC customers.
     *
     * We are careful to set the UserPort to
     * null before closing, and to free
     * any messages that it might have been
     * sent.
     */
    #include "exec/types.h"
    #include "exec/nodes.h"
    #include "exec/lists.h"
    #include "exec/ports.h"
    #include "intuition/intuition.h"

    CloseWindowSafely( win )
    struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *win;
    {
        /* we forbid here to keep out of race conditions with Intuition */
        Forbid();

        /* send back any messages for this window
         * that have not yet been processed
         */
        StripIntuiMessages( win->UserPort, win );

        /* clear UserPort so Intuition will not free it */
        win->UserPort = NULL;

        /* tell Intuition to stop sending more messages */
        ModifyIDCMP( win, 0L );

        /* turn multitasking back on */
        Permit();

        /* and really close the window */
        CloseWindow( win );
    }

    /* remove and reply all IntuiMessages on a port that
     * have been sent to a particular window
     * (note that we don't rely on the ln_Succ pointer
     *  of a message after we have replied it)
     */
    StripIntuiMessages( mp, win )
    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *mp;
    struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *win;
    {
        struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *msg;
        struct [Node](autodocs-2.0/includes-exec-nodes-h.md) *succ;

        msg = (struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *) mp->mp_MsgList.lh_Head;

        while( succ =  msg->ExecMessage.mn_Node.ln_Succ ) {

            if( msg->IDCMPWindow ==  win ) {

                /* Intuition is about to free this message.
                 * Make sure that we have politely sent it back.
                 */
                Remove( msg );

                ReplyMsg( msg );
            }

            msg = (struct [IntuiMessage](autodocs-2.0/includes-intuition-intuition-h.md) *) succ;
        }
    }
```

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseScreen — intuition.library](../autodocs/intuition.library.md#closescreen)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [OpenScreen — intuition.library](../autodocs/intuition.library.md#openscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
