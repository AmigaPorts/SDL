/* Source: ADCD 2.1
 * Section: 17-introduction-to-exec-interprocess-communications
 * Library: libraries
 * ADCD reference: libraries/17-introduction-to-exec-interprocess-communications.md
 */

    struct Message *mymsg; /*defined in <exec/ports.h> */
    struct Window *mywin;  /* defined in <intuition/intuition.h> */
            ...

    /* at some point, this application would have successfully opened a */
    /* window and stored a pointer to it in mywin.                      */
        ...

        /* Here the application goes to sleep until the user clicks */
        /* the window's close gadget. This window was set up so     */
        /* that the only time Intuition will send a message to this */
        /* window's port is if the user clicks the window's close   */
        /* gadget.                                                  */

        WaitPort(mywin->UserPort);
        while (mymsg = GetMsg(mywin->UserPort))
            /* process message now or copy information from message */
            ReplyMsg(mymsg);
        ...

    /* Close window, clean up */
