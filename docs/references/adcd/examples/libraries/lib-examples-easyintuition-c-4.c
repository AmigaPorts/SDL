/* Source: ADCD 2.1
 * Section: lib-examples-easyintuition-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyintuition-c.md
 */

    BOOL done = FALSE;
    struct IntuiMessage *message;
    ULONG class;

    /* Examine pending messages */
    while( message = (struct IntuiMessage *)GetMsg(win->UserPort) )
    {
        class = message->Class;   /* get all data we need from message */

        /* When we're through with a message, reply */
        ReplyMsg( (struct Message *)message);

        /* See what events occurred */
        switch( class )
        {
            case IDCMP_CLOSEWINDOW:
                done = TRUE;
                break;
            default:
                break;
        }
    }
    return(done);
