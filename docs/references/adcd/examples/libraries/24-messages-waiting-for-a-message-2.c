/* Source: ADCD 2.1
 * Section: 24-messages-waiting-for-a-message
 * Library: libraries
 * ADCD reference: libraries/24-messages-waiting-for-a-message.md
 */

    struct XYMessage *xy_msg;
    struct MsgPort   *xyport;
    ULONG usersig, portsig;
    BOOL ABORT = FALSE;

    if (xyport = CreatePort("xyport", 0))
    {
        portsig = 1 << xyport->mp_SigBit;
        usersig = SIGBREAKF_CTRL_C;     /* User can break with CTRL-C.  */
        for (;;)
        {
            signal = Wait(portsig | usersig);
                                        /* Sleep till someone signals.  */

            if (signal & portsig)       /* Got a signal at the msgport. */
            {   .  .  .
            }
            if (signal & usersig)       /* Got a signal from the user.  */
            {
                ABORT = TRUE;           /* Time to clean up.            */
                 . . .
            }
            if (ABORT) break;
        }
        DeletePort(xyport);
    }
    else printf("Couldn't create xyport\n");


    WaitPort() Does Not Remove A Message.
    -------------------------------------
    [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) only returns a pointer to the first message in a port.
    It does not actually remove the message from the port queue.
