# intuition.library/CloseWindow



    NAME
	CloseWindow -- [Close](../Includes_and_Autodocs_3._guide/node0149.html) an Intuition window.

    SYNOPSIS
	CloseWindow( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) )
		     A0

	VOID CloseWindow( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) * );

    FUNCTION
	Closes an Intuition window.  Unlinks it from the system, deallocates
	its memory, and makes it disappear.

	When this function is called, all IDCMP messages which have been sent
	to your window are deallocated.  If the window had shared a message
	Port with other windows, you must be sure that there are no unreplied
	messages for this window in the message queue.  Otherwise, your program
	will try to make use of a linked list (the queue) which contains free
	memory (the old messages).  This will give you big problems.
	See the code fragment CloseWindowSafely(), below.

	NOTE:  If you have added a [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) strip to this [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) (via
	a call to [SetMenuStrip()](../Includes_and_Autodocs_3._guide/node03F2.html)) you must be sure to remove that [Menu](../Includes_and_Autodocs_3._guide/node05E0.html#line59) strip
	(via a call to [ClearMenuStrip()](../Includes_and_Autodocs_3._guide/node039D.html)) before closing your [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908).

	NOTE: This function may block until it is safe to de-link and free
	your window.  Your program may thus be suspended while the user
	plays with gadgets, menus, or window sizes and position.

	New for V36: If your window is a "Visitor Window" (see OpenWindow)
	CloseWindow will decrement the "visitor count" in the public screen
	on which the window was open.  When the last visitor window is
	closed, a signal will be sent to the public screen task, if this
	was pre-arranged (see OpenScreen).

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = a pointer to a [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure

    RESULT
	None

    BUGS

    SEE ALSO
	[OpenWindow()](../Includes_and_Autodocs_3._guide/node03D5.html), [OpenScreen()](../Includes_and_Autodocs_3._guide/node03D3.html), [CloseScreen()](../Includes_and_Autodocs_3._guide/node039F.html)


    EXAMPLE
    /*	CloseWindowSafely */
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
	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *win;
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
	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *mp;
	struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *win;
	{
	    struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *msg;
	    struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *succ;

	    msg = (struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *) mp->mp_MsgList.lh_Head;

	    while( succ =  msg->ExecMessage.mn_Node.ln_Succ ) {

		if( msg->IDCMPWindow ==  win ) {

		    /* Intuition is about to free this message.
		     * Make sure that we have politely sent it back.
		     */
		    Remove( msg );

		    ReplyMsg( msg );
		}

		msg = (struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *) succ;
	    }
	}

