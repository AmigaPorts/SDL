/* Source: ADCD 2.1
 * Section: 24-message-ports-deleting-a-message-port
 * Library: libraries
 * ADCD reference: libraries/24-message-ports-deleting-a-message-port.md
 */

    struct MsgPort *newmp;

    if (newmp)
    {
        if ( newmp->mp_Node.ln_Name ) RemPort(newmp);
                                /* if it was public... */
        DeleteMsgPort(newmp);
    }
