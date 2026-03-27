/* Source: ADCD 2.1
 * Section: 24-message-ports-creating-a-message-port
 * Library: libraries
 * ADCD reference: libraries/24-message-ports-creating-a-message-port.md
 */

    struct MsgPort *newmp;
            /* A private message port has been created. CreateMsgPort() */
    if (newmp = CreateMsgPort())
            /* returns NULL if the creation of the message port failed. */
    {
        newmp->mp_Node.ln_Name = "Griffin";
        newmp->mp_Node.ln_Pri  = 0;
                                /* To make it public fill in the fields */
        AddPort(newmp);         /* with appropriate values.             */
    }
