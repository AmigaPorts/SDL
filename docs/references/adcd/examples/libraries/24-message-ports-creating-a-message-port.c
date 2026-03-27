/* Source: ADCD 2.1
 * Section: 24-message-ports-creating-a-message-port
 * Library: libraries
 * ADCD reference: libraries/24-message-ports-creating-a-message-port.md
 */

    struct MsgPort *CreatePort(UBYTE *name, LONG pri)
    {
        LONG sigBit;
        struct MsgPort *mp;

        if ((sigBit = AllocSignal(-1L)) == -1) return(NULL);

        mp = (struct MsgPort *) AllocMem((ULONG)sizeof(struct MsgPort),
                 (ULONG)MEMF_PUBLIC | MEMF_CLEAR);
        if (!mp) {
            FreeSignal(sigBit);
            return(NULL);
        }
        mp->mp_Node.ln_Name = name;
        mp->mp_Node.ln_Pri  = pri;
        mp->mp_Node.ln_Type = NT_MSGPORT;
        mp->mp_Flags        = PA_SIGNAL;
        mp->mp_SigBit       = sigBit;
        mp->mp_SigTask      = (struct Task *)FindTask(0L);
                                                  /* Find THIS task.   */

        if (name) AddPort(mp);
        else NewList(&(mp->mp_MsgList));          /* init message list */

        return(mp);
    }
