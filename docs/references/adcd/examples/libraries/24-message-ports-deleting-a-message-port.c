/* Source: ADCD 2.1
 * Section: 24-message-ports-deleting-a-message-port
 * Library: libraries
 * ADCD reference: libraries/24-message-ports-deleting-a-message-port.md
 */

    void DeletePort(mp)
    struct MsgPort *mp;
    {
        if ( mp->mp_Node.ln_Name ) RemPort(mp);  /* if it was public... */

        mp->mp_SigTask         = (struct Task *) -1;
                                /* Make it difficult to re-use the port */
        mp->mp_MsgList.lh_Head = (struct Node *) -1;

        FreeSignal( mp->mp_SigBit );
        FreeMem( mp, (ULONG)sizeof(struct MsgPort) );
    }
