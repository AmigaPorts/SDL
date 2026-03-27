/* Source: ADCD 2.1
 * Section: intuition-library-closewindow
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-closewindow.md
 */

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
    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *win;
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
    struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *mp;
    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *win;
    {
        struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *msg;
        struct [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) *succ;

        msg = (struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *) mp->mp_MsgList.lh_Head;

        while( succ =  msg->ExecMessage.mn_Node.ln_Succ ) {

            if( msg->IDCMPWindow ==  win ) {

                /* Intuition is about to free this message.
                 * Make sure that we have politely sent it back.
                 */
                Remove( msg );

                ReplyMsg( msg );
            }

            msg = (struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *) succ;
        }
    }
